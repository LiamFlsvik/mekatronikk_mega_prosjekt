#include <chrono>
#include <thread>
#include <rclcpp/rclcpp.hpp>
#include <geometry_msgs/msg/pose.hpp>
#include <moveit_msgs/msg/robot_trajectory.hpp>
#include <moveit/robot_model_loader/robot_model_loader.hpp>
#include <moveit/robot_state/robot_state.hpp>
#include <moveit/planning_scene_interface/planning_scene_interface.hpp>
#include <moveit/move_group_interface/move_group_interface.hpp>
#include <tf2_geometry_msgs/tf2_geometry_msgs.hpp>
#include <tf2/LinearMath/Quaternion.hpp>

#include <color_logger.hpp>
//TODO: Service
using RobotModelLoader = robot_model_loader::RobotModelLoader;
using MoveGroupInterface = moveit::planning_interface::MoveGroupInterface;

class robot_controller : public rclcpp::Node
{
public:
  robot_controller()
  : Node("robot_controller_node"),
    robot_model_loader_(std::shared_ptr<rclcpp::Node>(this)),
    robot_model_(robot_model_loader_.getModel()),
    robot_state_(std::make_shared<moveit::core::RobotState>(robot_model_)),
    PLANNING_GROUP("ur_manipulator"),
    move_group_interface(std::shared_ptr<rclcpp::Node>(this), PLANNING_GROUP),
    logger(rclcpp::get_logger("robot_controller_node")){
    
  //Parameters
    parameter_init();

    parameter_cb_handle = this->add_on_set_parameters_callback(std::bind(&robot_controller::on_parameter_change, this, std::placeholders::_1));

    RCLCPP_INFO(logger,"%sRobot Planning Pipeline:%s %s%s%s",COLOR_GREEN, COLOR_RESET,COLOR_BLUE,move_group_interface.getPlanningPipelineId().c_str(),COLOR_RESET);
    RCLCPP_INFO(logger,"%sRobot Planning Id:%s %s%s%s",COLOR_GREEN, COLOR_RESET,COLOR_BLUE,move_group_interface.getPlannerId().c_str(),COLOR_RESET);

    add_camera_collision();

    go_to_home_position({0.0, -M_PI/2, 0.0, 0.0, 0.0, 0.0});
    go_to_home_position();

    RCLCPP_INFO(logger, "%sScanning workplace%s", COLOR_BLUE, COLOR_RESET);
    scan_workplace();
  }

void scan_workplace(){
/*
This code starts at a angle defined in the parameter scan_angle_start and 
performs a half circle movement in the counter-clockwise and then the clockwise direction.
*/
  const double angle_increment = (M_PI / num_scan_points);
  double angle = scan_angle_start;

  for (int i = 0; i < round(num_scan_points)*2; ++i) {
    if (i < num_scan_points){
      angle += angle_increment;
    } else {
      angle -= angle_increment;
    }
    double x = scan_radius * cos(angle);
    double y = scan_radius * sin(angle);

    move_robot(x,y,scan_height,0,-M_PI,-angle);
    std::this_thread::sleep_for(std::chrono::milliseconds(500));
    }
  
  go_to_home_position();
}

// This code can be called to move the robots endeffector to a desired location with a specified roll, pitch and yaw.
void move_robot(double x, double y, double z, double roll = 0, double pitch = 0, double yaw = -M_PI/2){
  //End effector roll pitch and yaw:
    tf2::Quaternion quat;
    quat.setRPY(roll, pitch, yaw);
    geometry_msgs::msg::Quaternion msg_quat = tf2::toMsg(quat);
  //Robot pose
    geometry_msgs::msg::Pose target_pose;
    target_pose.orientation = msg_quat;
    target_pose.position.x = x;
    target_pose.position.y = y;
    target_pose.position.z = z;
  //Set pose target
    move_group_interface.setPoseTarget(target_pose);
  //create plan
    moveit::planning_interface::MoveGroupInterface::Plan plan;
    auto const sucess = static_cast<bool>(move_group_interface.plan(plan)); 
    if (sucess) {
      RCLCPP_INFO(logger, "%sPlan success%s", COLOR_GREEN, COLOR_RESET);
      RCLCPP_INFO(logger, "%sposition: x: %f, y: %f, z: %f %s",COLOR_GREEN, target_pose.position.x, target_pose.position.y, target_pose.position.z, COLOR_RESET);
      move_group_interface.execute(plan);
      
    } else {
      RCLCPP_ERROR(logger, "Plan failed");
      return;
    }
}
 
  void go_to_home_position(std::vector<double> home_joints_= {0.0, -1.57, 1.57, -1.57, -1.57, 0})
  {
    std::vector<double> home_joints = home_joints_;
    move_group_interface.setJointValueTarget(home_joints);
    MoveGroupInterface::Plan plan;
    if (move_group_interface.plan(plan) == moveit::core::MoveItErrorCode::SUCCESS) {
      RCLCPP_INFO(logger, "%sHome position successfully reached%s", COLOR_GREEN, COLOR_RESET);
      move_group_interface.execute(plan);
      std::this_thread::sleep_for(std::chrono::seconds(1));
    } else {
      RCLCPP_ERROR(logger, "Home planning failed");
    }
  }

  void add_camera_collision(){
    moveit::planning_interface::PlanningSceneInterface planning_scene_interface;
    planning_scene_interface.removeCollisionObjects({"camera"});
    moveit_msgs::msg::CollisionObject collision_object;
    collision_object.header.frame_id = "tool0"; 
    collision_object.id = "camera";

    shape_msgs::msg::SolidPrimitive camera;
    camera.type = shape_msgs::msg::SolidPrimitive::BOX;
    camera.dimensions = {camera_length, camera_width, camera_height};

    geometry_msgs::msg::Pose camera_pose;
    camera_pose.orientation.w = 1.0;
    camera_pose.position.x = 0.0;
    camera_pose.position.y = 0.0;
    camera_pose.position.z = camera_offset+ camera_height/2; 


    collision_object.primitives.push_back(camera);
    collision_object.primitive_poses.push_back(camera_pose);
    collision_object.operation = collision_object.ADD;

    planning_scene_interface.applyCollisionObject(collision_object);

    moveit_msgs::msg::AttachedCollisionObject attached_object;
    attached_object.link_name = "tool0";
    attached_object.object = collision_object;
    attached_object.touch_links = std::vector<std::string>{"tool0"};  

    planning_scene_interface.applyAttachedCollisionObject(attached_object);
    
}
  void parameter_init(){
      this->declare_parameter<std::string>("planning_pipeline_id", "pilz_industrial_motion_planner");
      this->declare_parameter<std::string>("planner_id", "PTP");

      this->declare_parameter<std::string>("planning_group", "ur_manipulator");
      PLANNING_GROUP = this->get_parameter("planning_group").as_string();
    //Desired scan radius for the robot 
      this->declare_parameter<double>("scan_radius", 0.4);
      scan_radius = this->get_parameter("scan_radius").as_double();
    //Desired scan height
      this->declare_parameter<double>("scan_height", 0.4);
      scan_height = this->get_parameter("scan_height").as_double();
    //Number of points to move to during each half circle "trajectory"
      this->declare_parameter<int>("num_scan_points", 8);
      num_scan_points = this->get_parameter("num_scan_points").as_int();

    //Camera dimensions z
      this->declare_parameter<double>("camera_height", 0.4);
      camera_height = this->get_parameter("camera_height").as_double();

    //Camera dimensions x
      this->declare_parameter<double>("camera_width", 0.4);
      camera_width = this->get_parameter("camera_width").as_double();

    //Camera dimensions y
      this->declare_parameter<double>("camera_length", 0.4);
      camera_length = this->get_parameter("camera_length").as_double();

    //Camera offset from the endeffector, must be greater than 0.0
      this->declare_parameter<double>("camera_offset",0.0);
      camera_offset = this->get_parameter("camera_offset").as_double();

    //The initial angle during the scan, 
      this->declare_parameter<double>("scan_angle_start",0.0);
      scan_angle_start = this->get_parameter("scan_angle_start").as_double();

      move_group_interface.setPlanningPipelineId("pilz_industrial_motion_planner");
      move_group_interface.setPlannerId("PTP");
    }
    
    rcl_interfaces::msg::SetParametersResult on_parameter_change(const std::vector<rclcpp::Parameter> &params){
      rcl_interfaces::msg::SetParametersResult result;
      result.successful = true;
      result.reason = "Parameters updated successfully";

      for (const auto &param : params) {
        const std::string &name = param.get_name();

        if (name == "planning_pipeline_id") {
          move_group_interface.setPlanningPipelineId(param.as_string());
          RCLCPP_INFO(logger, "Updated planning_pipeline_id to: %s", param.as_string().c_str());

        } else if (name == "planner_id") {
          move_group_interface.setPlannerId(param.as_string());
          RCLCPP_INFO(logger, "Updated planner_id to: %s", param.as_string().c_str());

        } else if (name == "planning_group") {
          PLANNING_GROUP = this->get_parameter("planning_group").as_string();

          RCLCPP_WARN(logger, "Changing planning_group dynamically is unsupported at runtime.");

        } else if (name == "scan_radius") {
          scan_radius = param.as_double();
          RCLCPP_INFO(logger, "Updated scan_radius to: %f", scan_radius);

        } else if (name == "scan_height") {
          scan_height = param.as_double();
          RCLCPP_INFO(logger, "Updated scan_height to: %f", scan_height);

        } else if (name == "num_scan_points") {
          num_scan_points = param.as_int();
          RCLCPP_INFO(logger, "Updated num_scan_points to: %f", num_scan_points);

        } else if (name == "camera_height") {
          camera_height = param.as_double();
          add_camera_collision();
          RCLCPP_INFO(logger, "Updated camera_height to: %f", camera_height);

        } else if (name == "camera_width") {
          camera_width = param.as_double();
          RCLCPP_INFO(logger, "Updated camera_width to: %f", camera_width);
          add_camera_collision();
        } else if (name == "camera_length") {
          camera_length = param.as_double();
          add_camera_collision();

          RCLCPP_INFO(logger, "Updated camera_length to: %f", camera_length);
        } else if (name == "camera_offset") {
          camera_offset = param.as_double();
          add_camera_collision();
          RCLCPP_INFO(logger, "Updated camera_offset to: %f", camera_offset);
        
        } else if (name == "scan_angle_start") {
          scan_angle_start = param.as_double();
          RCLCPP_INFO(logger, "Updated scan_angle_start to: %f", scan_angle_start);
        }
        else {
          result.successful = false;
          result.reason = "Unsupported parameter: " + name;
          RCLCPP_WARN(logger, "Unsupported parameter: %s", name.c_str());
        } 
      }
      return result;
    }
   
private:
  rclcpp::node_interfaces::OnSetParametersCallbackHandle::SharedPtr parameter_cb_handle;
  double scan_radius = 0.4;
  double scan_height = 0.4;
  double num_scan_points = 8;
  double box_point_offset = 0.1;
  double camera_height = 0.04;
  double camera_width = 0.04;
  double camera_length = 0.04;
  double camera_offset = 0.01;
  double scan_angle_start = 0;

  std::vector<std::vector<std::pair<double, double>>> poses = {{{0.1, 0.0}, {0.0, 0.1}}, {{-0.1, 0.0}, {0.0, -0.1}}};
  RobotModelLoader robot_model_loader_;
  moveit::core::RobotModelPtr robot_model_;
  moveit::core::RobotStatePtr robot_state_;
  std::string PLANNING_GROUP;
  moveit::core::JointModelGroup *joint_model_group_;
  MoveGroupInterface move_group_interface;
  moveit::planning_interface::PlanningSceneInterface planning_scene_interface;
  rclcpp::TimerBase::SharedPtr startup_timer_;
  rclcpp::Logger logger;
  tf2::Quaternion quat;
  
};

