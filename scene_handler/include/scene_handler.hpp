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
//#include "box_handler.hpp"
#include "process_msgs/msg/cube.hpp"
#include "process_msgs/msg/cube_array.hpp"
#include <geometry_msgs/msg/pose_stamped.hpp>

#include <tf2_ros/buffer.h>
#include <tf2_ros/transform_listener.h>

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

    cube_array_subscriber = this->create_subscription<process_msgs::msg::CubeArray>(
      "cube_array", 10, std::bind(&scene_handler::update_cube_array, this, std::placeholders::_1));

    planning_scene_diff_publisher = this->create_publisher<moveit_msgs::msg::PlanningScene>("planning_scene", 10);

    create_safe_zone();
    add_collision_object("red box", {0.2, 0.4, 0.0}, M_PI/4, {box_size_x, box_size_y, box_size_z}, "red");
    add_collision_object("green box",{0.2, 0.6, 0.0}, M_PI*1.2,{box_size_x, box_size_y, box_size_z}, "green");
  }

  void update_joint_states(sensor_msgs::msg::JointState::SharedPtr msg) {
    joint_values = msg->position;
    RCLCPP_INFO(this->get_logger(), "Updated joint states from topic: Joint 1:%f, Joint 2:%f, Joint 3:%f, Joint 4:%f, Joint 5:%f, Joint 6:%f",
                                                                      joint_values[0], joint_values[1], joint_values[2], joint_values[3], joint_values[4], joint_values[5]);

    
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

      // extract translation
    double x  = transformStamped.transform.translation.x;
    double y  = transformStamped.transform.translation.y;
    double z  = transformStamped.transform.translation.z;

    // extract quaternion
    double qx = transformStamped.transform.rotation.x;
    double qy = transformStamped.transform.rotation.y;
    double qz = transformStamped.transform.rotation.z;
    double qw = transformStamped.transform.rotation.w;

    // log the raw pose
    RCLCPP_INFO(get_logger(),
                "Tool0 via TF: [%.3f, %.3f, %.3f], "
                "quat [%.3f, %.3f, %.3f, %.3f]",
                x, y, z, qx, qy, qz, qw);

    // build and normalize the tf2::Quaternion
    tf2::Quaternion q(qx, qy, qz, qw);
    q.normalize();

    // now convert to RPY
    double roll, pitch, yaw;
    tf2::Matrix3x3(q).getRPY(roll, pitch, yaw);
    RCLCPP_INFO(get_logger(),
                "Tool0 RPY (rad): roll=%.3f, pitch=%.3f, yaw=%.3f",
                roll, pitch, yaw);


    matrix_transformations_.set_orientation(roll, pitch, yaw);
    matrix_transformations_.set_position(x, y, z);

    
    auto test_box = matrix_transformations_.base_T_pixel({300,300});
    remove_collision_object("blue box" + std::to_string(object_counter-1));
    add_collision_object("blue box", {test_box[0], test_box[1], 0.0}, M_PI/3, {box_size_x, box_size_y, box_size_z},"blue");

  }

  void update_cube_array(process_msgs::msg::CubeArray::SharedPtr msg) {
    auto cubes = msg->cubes;
    for (const auto& cube : cubes) {
      add_box(cube.color,{cube.position.x, cube.position.y,cube.position.z}, cube.angle);
    } 
  }

  void update_box(std::string name, std::vector<double> position, double yaw = 0.0) {
    remove_collision_object(name);
    add_collision_object(name, position, 0.0, {box_size_x, box_size_y, box_size_z}, "green");
  }

  void add_box(std::string name, std::vector<double> position, double yaw){
    add_collision_object(name, position, 0.0, {box_size_x, box_size_y, box_size_z}, "green");
  }

  void create_safe_zone(){
    add_collision_object("Robot base plate",{0.0,0.0,-0.015}, 0.0, {0.45, 0.25,0.015},"grey");
    add_collision_object("Working scene",{0.0, 0.25, -working_table_z-0.015}, 0.0,{working_table_x, working_table_y, working_table_z}, "grey");
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

  void add_collision_object(std::string object_name, std::vector<double> position, double yaw = 0.0,std::vector<double> box_size = {0.1, 0.1, 0.2}, std::string color_string="grey") {
    std_msgs::msg::ColorRGBA color = object_color(color_string);
    moveit_msgs::msg::CollisionObject collision_object; 
    collision_object.header.frame_id = move_group_interface.getPlanningFrame();
    collision_object.id = object_name + std::to_string(object_counter);
    
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
    RCLCPP_INFO(this->get_logger(), "Object counter: %d", object_counter);

    moveit_msgs::msg::ObjectColor object_color_msg;
    object_color_msg.id = collision_object.id;
    object_color_msg.color = color;

    moveit_msgs::msg::PlanningScene planning_scene_msg;
    planning_scene_msg.is_diff = true;
    planning_scene_msg.object_colors.push_back(object_color_msg);
    planning_scene_diff_publisher->publish(planning_scene_msg);
    object_counter++;
  }

    void remove_collision_object(const std::string& object_name) {
    planning_scene_interface.removeCollisionObjects({object_name});
    RCLCPP_INFO(this->get_logger(), "Removed collision object: %s", object_name.c_str());
  }

  private:
    const double box_size_x = 0.05;
    const double box_size_y = 0.05;
    const double box_size_z = 0.05;

    const double working_table_x = 0.85;
    const double working_table_y = 0.80;
    const double working_table_z = 0.01;

    int object_counter = 0;

    std::vector<double> joint_values;

    matrix_transformations matrix_transformations_;
    //box_handler box_handler_;

    MoveGroupInterface move_group_interface;
    PlanningSceneInterface planning_scene_interface;

    rclcpp::Publisher<moveit_msgs::msg::PlanningScene>::SharedPtr planning_scene_diff_publisher;
    rclcpp::Subscription<sensor_msgs::msg::JointState>::SharedPtr joint_state_subscriber;

    CollisionObject collision_object;
    rclcpp::Subscription<process_msgs::msg::CubeArray>::SharedPtr cube_array_subscriber;   
    tf2_ros::Buffer              tf_buffer_;
    tf2_ros::TransformListener   tf_listener_;

};