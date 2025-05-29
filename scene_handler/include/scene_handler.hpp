#include <rclcpp/rclcpp.hpp>
#include <moveit/move_group_interface/move_group_interface.hpp>
#include <moveit/planning_scene_interface/planning_scene_interface.hpp>
#include <moveit_msgs/msg/planning_scene.hpp>
#include <geometry_msgs/msg/pose.hpp>
#include <moveit_msgs/msg/collision_object.hpp>
#include <shape_msgs/msg/solid_primitive.hpp>
#include <tf2_geometry_msgs/tf2_geometry_msgs.hpp>
#include <tf2/LinearMath/Quaternion.hpp>
#include "matrix_transformations.hpp"
#include "process_msgs/msg/cube.hpp"
#include "process_msgs/msg/cube_array.hpp"
#include <geometry_msgs/msg/pose_stamped.hpp>
#include <chrono>
#include <tf2_ros/buffer.h>
#include <tf2_ros/transform_listener.h>
#include <process_msgs/msg/task.hpp>

using moveit::planning_interface::MoveGroupInterface;
using moveit::planning_interface::PlanningSceneInterface;
using moveit_msgs::msg::CollisionObject;
//TODO: Parameter service
class scene_handler: public rclcpp::Node{
  public:
  scene_handler(): 
  rclcpp::Node("scene_handler_node"), 
  joint_values({0.0, 0.0, 0.0, 0.0, 0.0, 0.0}),
  matrix_transformations_(),
  move_group_interface(std::shared_ptr<rclcpp::Node>(this), "ur_manipulator"),
  planning_scene_interface(),
  tf_buffer_(this->get_clock()),
  tf_listener_(tf_buffer_)
  {
    joint_state_subscriber = this->create_subscription<sensor_msgs::msg::JointState>(
      "joint_states",
      rclcpp::SensorDataQoS(),
      std::bind(&scene_handler::update_joint_states, this, std::placeholders::_1));

    parameters_init();
    parameter_cb_handle = this->add_on_set_parameters_callback(std::bind(&scene_handler::on_parameter_change, this, std::placeholders::_1));

    cube_array_subscriber = this->create_subscription<process_msgs::msg::CubeArray>(
      "cubes/detections", 10, std::bind(&scene_handler::update_cube_array, this, std::placeholders::_1));

    task_sub_ = this->create_subscription<process_msgs::msg::Task>(
       "/task_command", 10, std::bind(&scene_handler::handle_task, this, std::placeholders::_1));

    planning_scene_diff_publisher = this->create_publisher<moveit_msgs::msg::PlanningScene>("planning_scene", 10);

    cube_array_publisher = this->create_publisher<process_msgs::msg::CubeArray>("cubes/virtual_boxes", 10);
    timer_ = this->create_wall_timer(
     std::chrono::milliseconds(400), std::bind(&scene_handler::publish_virtual_boxes, this));

    create_safe_zone();
  }

  void update_joint_states(sensor_msgs::msg::JointState::SharedPtr msg) {
    //TODO: move this section to updated_cube_array, the joint_values are not used in this function, but rather used as a lazy way to update the x, y, z, roll  values of the robot base in the matrix_transformations class.
    joint_values = msg->position;   
    // TF2-based lookup for tool0
    geometry_msgs::msg::TransformStamped transformStamped;
    try {
      transformStamped = tf_buffer_.lookupTransform(
        "base_link",  // source frame
        "tool0",      // target frame
        rclcpp::Time(0),
        rclcpp::Duration::from_seconds(0.5));
    } catch (const tf2::TransformException &ex) {
      RCLCPP_WARN(this->get_logger(), "Could not transform from base_link to tool0: %s", ex.what());
      return;
    }
    double x  = transformStamped.transform.translation.x;
    double y  = transformStamped.transform.translation.y;
    double z  = transformStamped.transform.translation.z;
   
    double qx = transformStamped.transform.rotation.x;
    double qy = transformStamped.transform.rotation.y;
    double qz = transformStamped.transform.rotation.z;
    double qw = transformStamped.transform.rotation.w;
    tf2::Quaternion q(qx, qy, qz, qw);
    q.normalize();

    double roll, pitch, yaw;
    tf2::Matrix3x3(q).getRPY(roll, pitch, yaw);

    matrix_transformations_.set_orientation(roll, pitch, yaw);
    matrix_transformations_.set_position(x, y, z);
  }
  void handle_task(const process_msgs::msg::Task::SharedPtr msg) {
   
     const std::string &command = msg->command;
    if(command == "SCAN"){
      allow_cube_updates = true;
      RCLCPP_INFO(this->get_logger(), "Cube updates are enabled.");
    } else {
      allow_cube_updates = false;
      RCLCPP_INFO(this->get_logger(), "Cube updates are disabled.");
    }
  }

  void update_cube_array(process_msgs::msg::CubeArray::SharedPtr msg) {
    if (!allow_cube_updates){
      return;
    }
    auto cubes = msg->cubes;
    for (const auto& cube : cubes) {
        auto cube_coordinates = matrix_transformations_.base_T_pixel({cube.position.x, cube.position.y});
        int index = 0;
        if (cube_coordinates.size() == 0) {
            // Check if cube_coordinates is empty
            RCLCPP_WARN(this->get_logger(), "Invalid coordinates for cube color: %s", cube.color.c_str());
            continue; // Skip this cube if the coordinates are invalid
        }
        if (cube.color == "red"){
          index = 0;
        }
        else if (cube.color == "blue"){
          index = 1;
        }
        else if (cube.color == "green"){
          index = 2;
        }
        else if (cube.color == "yellow"){
          index = 3;
        }
        else {
          RCLCPP_WARN(this->get_logger(), "Unknown color: %s", cube.color.c_str());
          continue; // Skip this cube if the color is unknown
        }

        if(virtual_boxes[index].update(cube_coordinates, cube.angle)){
          if(cubes_found[index]){
            return;
          } else {
            cubes_found[index] = false;
            std::vector<double> box_position = virtual_boxes[index].get_position_filtered();
            remove_collision_object(cube.color);
            add_box(cube.color, {box_position[0], box_position[1], 0}, virtual_boxes[index].get_yaw());
          }
        }  
    }
}

  void publish_virtual_boxes() {
    process_msgs::msg::CubeArray cube_array_msg;
    for (size_t i = 0; i < virtual_boxes.size(); i++) {
      process_msgs::msg::Cube cube_msg;
      cube_msg.position.x = virtual_boxes[i].get_position_filtered()[0];
      cube_msg.position.y = virtual_boxes[i].get_position_filtered()[1];
      cube_msg.position.z = 0.0; // Assuming z is always 0 for virtual boxes
      cube_msg.angle = virtual_boxes[i].get_yaw();
      cube_msg.color = virtual_boxes[i].get_color();
      cube_array_msg.cubes.push_back(cube_msg);
    }
    cube_array_publisher->publish(cube_array_msg);
  }

  void create_safe_zone(){
    add_collision_object("Robot base plate",{0.0,0.0,-0.015}, 0.0, {0.45, 0.25,0.015},"grey");
    add_collision_object("Working scene",{0.0, 0.25, -working_table_z-0.015}, 0.0,{working_table_x, working_table_y, working_table_z}, "grey");
    add_collision_object("Virtual wall 1",{working_table_x,0,0}, 0.0, {0.03,1.0,1.0}, "grey");
    
  }

  static std_msgs::msg::ColorRGBA object_color(std::string color = "green") {
    if (color == "yellow" ){
      std_msgs::msg::ColorRGBA color;
      color.r = 0.8f; color.g = 0.8f; color.b = 0.1f; color.a = 1.0f;  
      return color;
    } 
    else if (color == "grey"){
      std_msgs::msg::ColorRGBA color;
      color.r = 0.5f; color.g = 0.5f; color.b = 0.5f; color.a = 1.0f;  
      return color;
    }
    else if (color == "red") {
      std_msgs::msg::ColorRGBA color;
      color.r = 0.8f; color.g = 0.1f; color.b = 0.1f; color.a = 1.0f;  
      return color;
    }
    else if (color == "blue") {
      std_msgs::msg::ColorRGBA color;
      color.r = 0.1f; color.g = 0.1f; color.b = 0.8f; color.a = 1.0f;  
      return color;
    }
    else if (color == "green") {
      std_msgs::msg::ColorRGBA color;
      color.r = 0.1f; color.g = 0.8f; color.b = 0.1f; color.a = 1.0f; 
      return color;
    }
    else {
      std_msgs::msg::ColorRGBA color;
      color.r = 0.1f; color.g = 0.1f; color.b = 0.1f; color.a = 1.0f;  
      return color;
    }
  }

  void add_box(std::string name, std::vector<double> position, double yaw){
    add_collision_object(name, position, yaw, {box_size_x, box_size_y, box_size_z}, name);
  }
  

  void add_collision_object(std::string object_name, std::vector<double> position, double yaw = 0.0,std::vector<double> box_size = {0.1, 0.1, 0.2}, std::string color_string="grey") {
    std_msgs::msg::ColorRGBA color = object_color(color_string);
    moveit_msgs::msg::CollisionObject collision_object; 
    collision_object.header.frame_id = move_group_interface.getPlanningFrame();
    collision_object.id = object_name;
    shape_msgs::msg::SolidPrimitive primitive;
    primitive.type = primitive.BOX;
    primitive.dimensions.resize(3);
    primitive.dimensions[primitive.BOX_X] = box_size[0];
    primitive.dimensions[primitive.BOX_Y] = box_size[1];
    primitive.dimensions[primitive.BOX_Z] = box_size[2];

    tf2::Quaternion quat;
    quat.setRPY(0, 0, yaw);
    geometry_msgs::msg::Quaternion msg_quat = tf2::toMsg(quat);
    geometry_msgs::msg::Pose box_pose;
    box_pose.orientation = msg_quat;

    box_pose.position.x = position[0];
    box_pose.position.y = position[1];
    box_pose.position.z = position[2];

    collision_object.primitives.push_back(primitive);
    collision_object.primitive_poses.push_back(box_pose);
    collision_object.operation = collision_object.ADD;

    planning_scene_interface.applyCollisionObjects({collision_object});

    RCLCPP_INFO(this->get_logger(), "Added collision object: %s", object_name.c_str());

    moveit_msgs::msg::ObjectColor object_color_msg;
    object_color_msg.id = collision_object.id;
    object_color_msg.color = color;

    moveit_msgs::msg::PlanningScene planning_scene_msg;
    planning_scene_msg.is_diff = true;
    planning_scene_msg.object_colors.push_back(object_color_msg);
    planning_scene_diff_publisher->publish(planning_scene_msg);
    }

    void remove_collision_object(const std::string& object_name) {
    planning_scene_interface.removeCollisionObjects({object_name});
    RCLCPP_INFO(this->get_logger(), "Removed collision object: %s", object_name.c_str());
  }
  
  
  void parameters_init(){
    this->declare_parameter<double>("box_size_x", 0.05);
    box_size_x= this->get_parameter("box_size_x").as_double();

    this->declare_parameter<double>("box_size_y", 0.05);
    box_size_y= this->get_parameter("box_size_y").as_double();

    this->declare_parameter<double>("box_size_z", 0.05);
    box_size_z= this->get_parameter("box_size_z").as_double();

    this->declare_parameter<double>("camera_filter_position_filter_strenght", 0.9);
    for(size_t i = 0; i < virtual_boxes.size(); i++){
      virtual_boxes[i].set_filter_strength(this->get_parameter("camera_filter_position_filter_strenght").as_double());
    }
  }
    rcl_interfaces::msg::SetParametersResult on_parameter_change(const std::vector<rclcpp::Parameter> &params){
      rcl_interfaces::msg::SetParametersResult result;
      result.successful = true;
      result.reason = "Parameters updated successfully";

      for (const auto &param : params) {
        const std::string &name = param.get_name();

        if (name == "box_size_x") {
          box_size_x = param.as_double();
          RCLCPP_INFO(this->get_logger(), "Box size x set to: %s", param.as_string().c_str());
        } else if (name == "box_size_y") {
          box_size_y = param.as_double();
          RCLCPP_INFO(this->get_logger(), "Box size y set to: %s", param.as_string().c_str());
        } else if(name == "box_size_z"){
          box_size_z = param.as_double();
          RCLCPP_INFO(this->get_logger(), "Box size z set to: %s", param.as_string().c_str());
        } else if(name == "camera_x_offset"){
            matrix_transformations_.set_camera_offset_x(param.as_double());
          RCLCPP_INFO(this->get_logger(), "Camera x offset set to: %f", param.as_double());
        } else if(name == "camera_y_offset"){
          matrix_transformations_.set_camera_offset_x(param.as_double());
          RCLCPP_INFO(this->get_logger(), "Camera y offset set to: %f", param.as_double());
        } else if (name == "camera_filter_position_filter_strenght") {
          double alpha = param.as_double();
          for (size_t i = 0; i < virtual_boxes.size(); ++i) {
            virtual_boxes[i].set_filter_strength(alpha);
          }
          RCLCPP_INFO(this->get_logger(),
                      "Camera position filter strength set to: %f", alpha);
        } else {
          result.successful = false;
          result.reason = "Unsupported parameter: " + name;
          RCLCPP_WARN(this->get_logger(), "Unsupported parameter: %s", name.c_str());
        } 
      }
    return result;
    }
    double box_size_x = 0.05;
    double box_size_y = 0.05;
    double box_size_z = 0.05;
  
    const double working_table_x = 0.85;
    const double working_table_y = 0.80;
    const double working_table_z = 0.01;

    int object_counter = 0;

    std::vector<double> joint_values;

    matrix_transformations matrix_transformations_;
    std::vector<bool> cubes_found{false,false,false,false};

    MoveGroupInterface move_group_interface;
    PlanningSceneInterface planning_scene_interface;
    rclcpp::Publisher<moveit_msgs::msg::PlanningScene>::SharedPtr planning_scene_diff_publisher;
    rclcpp::Subscription<sensor_msgs::msg::JointState>::SharedPtr joint_state_subscriber;
    rclcpp::node_interfaces::OnSetParametersCallbackHandle::SharedPtr parameter_cb_handle;
    rclcpp::Publisher<process_msgs::msg::CubeArray>::SharedPtr cube_array_publisher;
    CollisionObject collision_object;
    rclcpp::Subscription<process_msgs::msg::CubeArray>::SharedPtr cube_array_subscriber;   
    tf2_ros::Buffer              tf_buffer_;
    tf2_ros::TransformListener   tf_listener_;
    rclcpp::TimerBase::SharedPtr timer_;
    std::string task_type = "HOME";

    rclcpp::Subscription<process_msgs::msg::Task>::SharedPtr task_sub_;
    bool allow_cube_updates = false; // Flag to allow or disallow cube updates

    struct Box {
      std::vector<double> position{-0.05, -0.05, 0, 0};
      std::vector<double> position_filtered = position;
      double camera_filter_position_filter_strenght = 0.9; // Filter coefficient for position updates
      std::vector<double> size{0.05, 0.05, 0.05}; 
      double yaw = 0.0; 
      std::string color = "grey"; 
      int id = 0; // Unique identifier for the box

    Box(const std::vector<double> position, const std::vector<double> size, const std::string color, const int id)
            : position(position), size(size), color(color), id(id) {}
    bool update(std::vector<double> new_position_, double yaw_) {
        if (abs(new_position_[0]) < 0.05) {
          new_position_[0] = 0.05; // Ensure the x position is not too close to the robot base
        }
        if (abs(new_position_[1]) < 0.05){
          new_position_[1] = 0.05; // Ensure the y position is not too close to the robot base
        }

        for (size_t i = 0; i < 2; ++i) {
            //if ((std::abs(position[i] - new_position_[i]) > 0.02 )|| (yaw - yaw_ > 0.02))) { // Threshold to avoid unnecessary updates
          position[i] = new_position_[i];
          position_filtered[i] = new_position_[i]*(1-camera_filter_position_filter_strenght) + camera_filter_position_filter_strenght * position_filtered[i]; // Apply low-pass filter
          yaw = yaw_;
        }
        return true;
        
      }
     std::vector<double> get_position_filtered() const {
        return position_filtered;
      }
      double get_yaw() const {
        return yaw;
      }
      void set_filter_strength(double new_alpha) {
        camera_filter_position_filter_strenght = new_alpha;
      }
      std::string get_color() const {
        return color;
      }
      
      int get_id() const {
        return id;
      }
    };

    std::vector<Box> virtual_boxes{
      {{0.0, 0.0, 0.0, 0.0},    {0.05, 0.05, 0.05},     "red", 0},
      {{0.1, 0.1, 0.1, 0.0},    {0.05, 0.05, 0.05},    "blue", 1},
      {{-0.1, -0.1, -0.1, 0.0}, {0.05, 0.05, 0.05},   "green", 2},
      {{0.2, 0.2, 0.2, 0.0},    {0.05, 0.05, 0.05},   "yellow",3}};

};