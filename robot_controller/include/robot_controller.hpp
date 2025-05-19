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
    
    
    move_group_interface.setPlanningPipelineId("pilz_industrial_motion_planner");
    move_group_interface.setPlannerId("PTP");
    RCLCPP_INFO(logger,"%sRobot Planning Pipeline:%s %s%s%s",COLOR_GREEN, COLOR_RESET,COLOR_BLUE,move_group_interface.getPlanningPipelineId().c_str(),COLOR_RESET);
    RCLCPP_INFO(logger,"%sRobot Planning Id:%s %s%s%s",COLOR_GREEN, COLOR_RESET,COLOR_BLUE,move_group_interface.getPlannerId().c_str(),COLOR_RESET);
   
    go_to_home_position({0.0, -M_PI/2, 0.0, 0.0, 0.0, 0.0});

    go_to_home_position();

    
    RCLCPP_INFO(logger, "%sScanning workplace%s", COLOR_BLUE, COLOR_RESET);
    scan_workplace();
    

  }

void scan_workplace(){
  const double r = 0.4;
  const double height = 0.4; //Scan height
  /*double scan_depth_offset = height -0.15;
  if (scan_depth_offset < 0.0){
    scan_depth_offset = 0.01;
  }*/
  const double num_points = 8;
  const double angle_increment = (M_PI / num_points);
  double angle = 0.0;

  for (int i = 0; i < num_points*2; ++i) {
    //Get pose
    
    if (i < num_points){
      angle += angle_increment;
    } else {
      angle -= angle_increment;
    }
    double x = r * cos(angle);
    double y = r * sin(angle);
    move_robot(x,y,height,0,-M_PI,angle);
    std::this_thread::sleep_for(std::chrono::milliseconds(500));
    }
  
  go_to_home_position();
}
void point_on_object(double x,double y, double z){
  move_robot(x,y,z,0,-M_PI,0);
}

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

    move_group_interface.setPoseTarget(target_pose);

  //Plan
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
    std::vector<double> home_joints = home_joints_;//= {0.0, -1.57, 1.57, -1.57, -1.57, 0};
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

private:
  double box_pick_offset = 0.1;
  const double box_height = 0.1; //height of the box
  const double box_width = 0.1; //width of the box
  const double box_length = 0.1; //length of the box
  std::vector<std::vector<std::pair<double, double>>> poses = {{{0.1, 0.0}, {0.0, 0.1}}, {{-0.1, 0.0}, {0.0, -0.1}}};
  RobotModelLoader robot_model_loader_;
  moveit::core::RobotModelPtr robot_model_;
  moveit::core::RobotStatePtr robot_state_;
  const std::string PLANNING_GROUP;
  const moveit::core::JointModelGroup *joint_model_group_;
  MoveGroupInterface move_group_interface;
  moveit::planning_interface::PlanningSceneInterface planning_scene_interface;
  rclcpp::TimerBase::SharedPtr startup_timer_;
  rclcpp::Logger logger;
  tf2::Quaternion quat;
  
};

