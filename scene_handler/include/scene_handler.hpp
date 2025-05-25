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
  planning_scene_interface() {

    

  joint_state_subscriber = this->create_subscription<sensor_msgs::msg::JointState>(
      "joint_states",
      rclcpp::SensorDataQoS(),
      std::bind(&scene_handler::update_joint_states, this, std::placeholders::_1));

  planning_scene_diff_publisher = this->create_publisher<moveit_msgs::msg::PlanningScene>("planning_scene", 10);
  //remove collision objects


  create_safe_zone();
  
  //Test transformations:

  add_collision_object("red box", 0.2, 0.4, 0.0, M_PI/4, box_size_x, box_size_y, box_size_z, object_color("red"));
  add_collision_object("green box", 0.2, 0.6, 0.0, M_PI*1.2, box_size_x, box_size_y, box_size_z, object_color("green"));
  

  //Joint states:

  }

  void update_joint_states(sensor_msgs::msg::JointState::SharedPtr msg) {
    // Update the joint states in the MoveGroupInterface
    joint_values = msg->position;
    RCLCPP_INFO(this->get_logger(), "Updated joint states from topic: Joint 1:%f, Joint 2:%f, Joint 3:%f, Joint 4:%f, Joint 5:%f, Joint 6:%f",
                                                                      joint_values[0], joint_values[1], joint_values[2], joint_values[3], joint_values[4], joint_values[5]);
    for (int px = 100; px < 500; px += 50) {
      for (int py = 100; py < 500; py += 50) {
        auto test_box = matrix_transformations_.camera_to_base_coordinates({(double)px, (double)py}, joint_values, 0.3);
        RCLCPP_INFO(this->get_logger(), "Box from pixel (%d,%d): x=%f, y=%f", px, py, test_box[0], test_box[1]);
      }
    auto test_box = matrix_transformations_.camera_to_base_coordinates({(double)px, 240}, joint_values, 0.3);
    RCLCPP_INFO(this->get_logger(), "Box from pixel (%d,240): x=%f, y=%f", px, test_box[0], test_box[1]);

    remove_collision_object("blue box" + std::to_string(object_counter-1));
    add_collision_object("blue box", test_box[0], test_box[1], 0, M_PI/3, box_size_x, box_size_y, box_size_z, object_color("blue"));

    rclcpp::sleep_for(std::chrono::milliseconds(500));
}

    //std::vector<double> test_box = matrix_transformations_.camera_to_base_coordinates({0.2, 0.4}, joint_values, 0.3);
   // RCLCPP_INFO(this->get_logger(), "Test box position: x:%f, y:%f, z:%f", test_box[0], test_box[1], test_box[2]);

   
  }

  

  void create_safe_zone(){
    /*Workspace measurments:
      base_plate:
        x 45cm y25cm z1.5cm
      Table (smaller than the actual):
        x 85cm y 80cm z 
    */

  //Security zones:
    add_collision_object("Robot base plate",0.0,0.0,-0.015,0.0,0.45,0.25,0.015, object_color("grey"));
    add_collision_object("Working scene", 0.0, 0.25, -working_table_z-0.015, 0.0, working_table_x, working_table_y, working_table_z, object_color("grey"));
  }


  static std_msgs::msg::ColorRGBA object_color(std::string color="green") {
    //gul grønn rød blå
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

  void add_collision_object(std::string object_name, double position_x, double position_y, double position_z,double yaw = 0.0, double box_size_x = 0.1, double box_size_y = 0.1, double box_size_z = 0.2, std_msgs::msg::ColorRGBA color = object_color("green")) {

    moveit_msgs::msg::CollisionObject collision_object; 
    collision_object.header.frame_id = move_group_interface.getPlanningFrame();
    collision_object.id = object_name + std::to_string(object_counter);

    shape_msgs::msg::SolidPrimitive primitive;
    primitive.type = primitive.BOX;
    primitive.dimensions.resize(3);
    primitive.dimensions[primitive.BOX_X] = box_size_x;
    primitive.dimensions[primitive.BOX_Y] = box_size_y;
    primitive.dimensions[primitive.BOX_Z] = box_size_z;

    tf2::Quaternion quat;
    quat.setRPY(0, 0, yaw);
    geometry_msgs::msg::Quaternion msg_quat = tf2::toMsg(quat);
    geometry_msgs::msg::Pose box_pose;
    box_pose.orientation = msg_quat;

    box_pose.position.x = position_x;
    box_pose.position.y = position_y;
    box_pose.position.z = position_z;

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
    double box_size_x = 0.05;
    double box_size_y = 0.05;
    double box_size_z = 0.05;
    double working_table_x = 0.85;
    double working_table_y = 0.80;
    double working_table_z = 0.01;

    int object_counter = 0;

    std::vector<double> joint_values;

    matrix_transformations matrix_transformations_;

    MoveGroupInterface move_group_interface;
    PlanningSceneInterface planning_scene_interface;

    rclcpp::Publisher<moveit_msgs::msg::PlanningScene>::SharedPtr planning_scene_diff_publisher;
    rclcpp::Subscription<sensor_msgs::msg::JointState>::SharedPtr joint_state_subscriber;

    CollisionObject collision_object;
  


};