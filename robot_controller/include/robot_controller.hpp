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
#include <process_msgs/msg/task.hpp>
#include <process_msgs/msg/task_feedback.hpp>
#include <process_msgs/msg/scene_state.hpp>
#include <process_msgs/msg/cube.hpp>
#include <process_msgs/msg/cube_array.hpp>
#include <rclcpp/executor.hpp>


using robot_model_loader::RobotModelLoader;
using moveit::planning_interface::MoveGroupInterface;

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
    cube_array_subscriber = this->create_subscription<process_msgs::msg::CubeArray>(
      "cubes/virtual_boxes", 10, std::bind(&robot_controller::update_cubes, this, std::placeholders::_1));


    RCLCPP_INFO(logger,"%sRobot Planning Pipeline:%s %s%s%s",COLOR_GREEN, COLOR_RESET,COLOR_BLUE,move_group_interface.getPlanningPipelineId().c_str(),COLOR_RESET);
    RCLCPP_INFO(logger,"%sRobot Planning Id:%s %s%s%s",COLOR_GREEN, COLOR_RESET,COLOR_BLUE,move_group_interface.getPlannerId().c_str(),COLOR_RESET);

    add_camera_collision();
    RCLCPP_INFO(logger, "%sAdded camera collision%s",COLOR_BLUE,COLOR_RESET);
    move_group_interface.setStartStateToCurrentState();
    RCLCPP_INFO(logger, "%sScanning workplace%s", COLOR_BLUE, COLOR_RESET);

    scan_workplace();
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));

    task_sub_ = this->create_subscription<process_msgs::msg::Task>(
      "/task_command", 10,
      [this](const process_msgs::msg::Task::SharedPtr msg) {
        handle_task(msg);
      });
  
    feedback_pub_ = this->create_publisher<process_msgs::msg::TaskFeedback>(
      "/task/feedback", 10);
  
    scene_sub_ = this->create_subscription<process_msgs::msg::SceneState>(
      "/scene/state", 10,
      [this](const process_msgs::msg::SceneState::SharedPtr msg) {
        last_scene_ = msg;
      });
   
  }

bool scan_workplace(){
/*
This code starts at a angle defined in the parameter scan_angle_start and 
performs a half circle movement in the counter-clockwise and then the clockwise direction.
*/
  allow_cube_updates=true;
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

    move_robot(x,y,scan_height,0,0,0);
    std::this_thread::sleep_for(std::chrono::milliseconds(500));
    move_group_interface.setStartStateToCurrentState();
    }
  //allow_cube_updates = false;
  return true;
}
bool move_robot(double x, double y, double z, double roll = 0, double pitch = 0, double yaw = -M_PI/2){
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
    auto const success = static_cast<bool>(move_group_interface.plan(plan)); 
    if (success) {
      RCLCPP_INFO(logger, "%sPlan success%s", COLOR_GREEN, COLOR_RESET);
      RCLCPP_INFO(logger, "%sposition: x: %f, y: %f, z: %f %s",COLOR_GREEN, target_pose.position.x, target_pose.position.y, target_pose.position.z, COLOR_RESET);
      move_group_interface.execute(plan);
      std::this_thread::sleep_for(std::chrono::milliseconds(5000));
      return true;

    } else {
      RCLCPP_ERROR(logger, "%sPlan failed%s", COLOR_RED, COLOR_RESET);
      return false;
    }
    return false;
  }
 
  bool go_to_home_position(std::vector<double> home_joints_= {1.57, -1.57, 0.785, -0.785, -1.57, 0})
  {
      std::vector<double> home_joints = home_joints_;
      move_group_interface.setJointValueTarget(home_joints);
      MoveGroupInterface::Plan plan;
      auto const result = move_group_interface.plan(plan); // Add result variable
      if (result == moveit::core::MoveItErrorCode::SUCCESS) {
          RCLCPP_INFO(logger, "%sHome position successfully reached%s", COLOR_GREEN, COLOR_RESET);
          move_group_interface.execute(plan);
          std::this_thread::sleep_for(std::chrono::milliseconds(5000));
          return true;
      } else {
          RCLCPP_ERROR(logger, "Home planning failed");
          return false;
      }
  }
  void update_cubes(process_msgs::msg::CubeArray::SharedPtr msg) {
    if (!allow_cube_updates){
      return;
    }
    auto cubes = msg->cubes;
    for (const auto& cube : cubes) {
      RCLCPP_INFO(logger, "Received cube: color=%s, position=(%.2f, %.2f, %.2f), angle=%.2f",
                  cube.color.c_str(), cube.position.x, cube.position.y, cube.position.z, cube.angle);
      if (cube.color == "red") {
        virtual_boxes[0].position = {cube.position.x, cube.position.y};
        virtual_boxes[0].angle = cube.angle;
      } else if (cube.color == "yellow") {
        virtual_boxes[1].position = {cube.position.x, cube.position.y};
        virtual_boxes[1].angle = cube.angle;
      } else if (cube.color == "blue") {
        virtual_boxes[2].position = {cube.position.x, cube.position.y};
        virtual_boxes[2].angle = cube.angle;
      } else if (cube.color == "green") {
        virtual_boxes[3].position = {cube.position.x, cube.position.y};
        virtual_boxes[3].angle = cube.angle;
      } else {
        RCLCPP_WARN(logger, "Unknown cube color: %s", cube.color.c_str());
      }
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
    camera_pose.position.y = -camera_offset_width;
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

      this->declare_parameter<double>("camera_offset_width", 0.0);
      camera_offset_width = this->get_parameter("camera_offset_width").as_double();

    //The initial angle during the scan, 
      this->declare_parameter<double>("scan_angle_start",0.0);
      scan_angle_start = this->get_parameter("scan_angle_start").as_double();

    //The height over the cubes when pointing
      this->declare_parameter<double>("cube_point_offset", 0.1);
      cube_point_offset = this->get_parameter("cube_point_offset").as_double();

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
        } else if (name == "camera_offset_width") {
          camera_offset_width = param.as_double();
          RCLCPP_INFO(logger, "updated camera_offset_width to %f", camera_offset_width);

        } else if (name == "cube_point_offset"){
          cube_point_offset = param.as_double();
          RCLCPP_INFO(logger, "Updated cube_point_offset to: %f", cube_point_offset);
        } 
        else {
          result.successful = false;
          result.reason = "Unsupported parameter: " + name;
          RCLCPP_WARN(logger, "Unsupported parameter: %s", name.c_str());
        } 
      }
      return result;
    }

    void publishJointStates(){
      sensor_msgs::msg::JointState msg;
      msg.name = move_group_interface.getJointNames();
      msg.position = move_group_interface.getCurrentJointValues();
      msg.header.stamp = this->now();
      joint_state_publisher->publish(msg);
      RCLCPP_INFO(logger, "Published joint states: %s", msg.name[0].c_str());
    }

private:
  void handle_task(const process_msgs::msg::Task::SharedPtr msg) {
    process_msgs::msg::TaskFeedback feedback;
    feedback.command = msg->command;

    try {
      if(msg->command == "MOVE_HOME") {
        feedback.success = go_to_home_position();
        feedback.message = feedback.success ? "Home reached" : "Move home failed";
        std::this_thread::sleep_for(std::chrono::milliseconds(5000));

      }
      else if(msg->command == "SCAN") {
        feedback.success = scan_workplace();
        feedback.message = feedback.success ? "Scan completed" : "Scan failed";
        std::this_thread::sleep_for(std::chrono::milliseconds(5000));
      }
      else if(msg->command == "POINT") {
        feedback.success = point_to_cubes();
        feedback.message = feedback.success ? "Pointing completed" : "Pointing failed";
        std::this_thread::sleep_for(std::chrono::milliseconds(5000));
      }
      else {
        feedback.success = false;
        feedback.message = "Unknown command: " + msg->command;
      }
    } catch(const std::exception& e) {
      feedback.success = false;
      feedback.message = "Exception: " + std::string(e.what());
    }
    
    feedback_pub_->publish(feedback);
  }

  bool point_to_cubes() {
    for (const auto& cube : virtual_boxes) {
      if (cube.position.empty()) {
        RCLCPP_WARN(logger, "Cube coordinates are empty, skipping.");
        continue;
      }
      double x = cube.position[0];
      double y = cube.position[1];
      double z = camera_height + cube_point_offset;
      double roll = 0;
      double yaw = cube.angle;
      double pitch = 0;
      move_robot(x,y,scan_height,0,0,0);

      if (!move_robot(x, y, z, roll, pitch, yaw)) {
        RCLCPP_ERROR(logger, "Failed to point to %s cube at (%f, %f)", cube.color.c_str(), x, y);
        return false;
      }
      std::this_thread::sleep_for(std::chrono::seconds(2));
    }
    return true;
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
  double camera_offset_width = 0.0;
  double cube_point_offset = 0.1;

  struct Cube {
    std::string color;
    std::vector<double> position;
    double angle;
  };

  std::vector<Cube> virtual_boxes = {
    {"red", {0.0, 0.0}, 0.0},
    {"yellow", {0.0, 0.0}, 0.0},
    {"blue", {0.0, 0.0}, 0.0},
    {"green", {0.0, 0.0}, 0.0}
  };
  

  rclcpp::Publisher<sensor_msgs::msg::JointState>::SharedPtr joint_state_publisher;
  RobotModelLoader robot_model_loader_;
  moveit::core::RobotModelPtr robot_model_;
  moveit::core::RobotStatePtr robot_state_;
  bool allow_cube_updates = true;
  std::string PLANNING_GROUP;
  moveit::core::JointModelGroup *joint_model_group_;
  MoveGroupInterface move_group_interface;
  moveit::planning_interface::PlanningSceneInterface planning_scene_interface;
  rclcpp::TimerBase::SharedPtr startup_timer_;
  rclcpp::Logger logger;
  tf2::Quaternion quat;
  process_msgs::msg::CubeArray::SharedPtr cube_array_;
  rclcpp::TimerBase::SharedPtr timer_;
  rclcpp::Subscription<process_msgs::msg::CubeArray>::SharedPtr cube_array_subscriber;
  rclcpp::Subscription<process_msgs::msg::Task>::SharedPtr task_sub_;
  rclcpp::Publisher<process_msgs::msg::TaskFeedback>::SharedPtr feedback_pub_;
  rclcpp::Subscription<process_msgs::msg::SceneState>::SharedPtr scene_sub_;
  process_msgs::msg::SceneState::SharedPtr last_scene_;

};

