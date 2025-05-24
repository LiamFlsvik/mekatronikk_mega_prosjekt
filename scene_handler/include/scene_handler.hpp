#include <rclcpp/rclcpp.hpp>
#include <moveit/move_group_interface/move_group_interface.hpp>
#include <moveit/planning_scene_interface/planning_scene_interface.hpp>
#include <moveit_msgs/msg/planning_scene.hpp>
#include <geometry_msgs/msg/pose.hpp>
#include <moveit_msgs/msg/collision_object.hpp>
#include <shape_msgs/msg/solid_primitive.hpp>
#include <tf2_geometry_msgs/tf2_geometry_msgs.hpp>
#include <tf2/LinearMath/Quaternion.hpp>


using moveit::planning_interface::MoveGroupInterface;
using moveit::planning_interface::PlanningSceneInterface;
using moveit_msgs::msg::CollisionObject;

//TODO: Parameter service
class scene_handler: public rclcpp::Node{
  public:
  scene_handler(): 
  rclcpp::Node("scene_handler_node"), 
  move_group_interface(std::shared_ptr<rclcpp::Node>(this),"ur_manipulator"),
  planning_scene_interface(){

  create_safe_zone();
    
  }

  void create_safe_zone(){
    /*arbeidsområde målinger:
      base:
        x 45cm y25cm z1.5cm
      område
        x 85cm y 80cm z */
    //Add robot base plate
    add_collision_object("Robot base plate",0.0,0.0,-0.015,0.0,0.45,0.25,0.015);
    add_collision_object("Working scene", 0.0, 0.25, -working_table_z-0.015, 0.0, working_table_x, working_table_y, working_table_z);
    //TODO: add safe zones
  }

  void add_box(std::string name, double position_x, double position_y, double position_z, double yaw){
    tf2::Quaternion quat;
    quat.setRPY(0, 0, yaw);
    geometry_msgs::msg::Quaternion msg_quat = tf2::toMsg(quat);
    //Robot pose
    geometry_msgs::msg::Pose target_pose;
    target_pose.orientation = msg_quat;

    add_collision_object(name, position_x, position_y, position_z, box_size_x, box_size_y, box_size_z);
    RCLCPP_INFO(this->get_logger(), "Added box: %s", name.c_str());
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

    geometry_msgs::msg::Pose box_pose;
    box_pose.orientation.w = 1.0;
    box_pose.position.x = position_x;
    box_pose.position.y = position_y;
    box_pose.position.z = position_z;

    collision_object.primitives.push_back(primitive);
    collision_object.primitive_poses.push_back(box_pose);
    collision_object.operation = collision_object.ADD;

    planning_scene_interface.applyCollisionObjects({collision_object});
    object_counter++;

    RCLCPP_INFO(this->get_logger(), "Added collision object: %s", object_name.c_str());
    RCLCPP_INFO(this->get_logger(), "Object counter: %d", object_counter);
  }

  void remove_collision_object(const std::string& object_name) {
  planning_scene_interface.removeCollisionObjects({object_name});
  RCLCPP_INFO(this->get_logger(), "Removed collision object: %s", object_name.c_str());
}

  private:
  double box_size_x = 0.1;
  double box_size_y = 0.1;
  double box_size_z = 0.1;
  double working_table_x = 0.85;
  double working_table_y = 0.80;
  double working_table_z = 0.01;

  int object_counter = 0;

  MoveGroupInterface move_group_interface;
  PlanningSceneInterface planning_scene_interface;
  CollisionObject collision_object;
  tf2::Quaternion quat;
  geometry_msgs::msg::Quaternion msg_quat;

};