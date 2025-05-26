
#include <Eigen/Dense>
#include <opencv2/opencv.hpp>
#include <vector>

class matrix_transformations {
    public:

    matrix_transformations(){

        camera_parameter_matrix = (cv::Mat_<double>(3,3) << -530.47292,    0.0,         357.1054,
                                                            0.0,           530.51882,  258.43042,
                                                            0.0,           0.0,          1.0);

        distortion_coefficients = (cv::Mat_<double>(1,5) << 0.073635, -0.121473, -0.000465, 0.015358, 0.00);
    } 
    
    public:
    // Camera pixel coordinates to base coordinates:
    Eigen::Matrix <double,3,1> pixel_to_camera_coordinates(const std::vector<double>& pixel_coordinates) {
        std::vector<cv::Point2d> distored_points;
        distored_points.emplace_back(pixel_coordinates[0], pixel_coordinates[1]);

        //Undistort image:
        std::vector<cv::Point2d> undistorted_points;
        cv::undistortPoints(distored_points, undistorted_points, camera_parameter_matrix, distortion_coefficients);

        //Normalized camera coordinates:
        double x =  -0.025+undistorted_points[0].x * depth;
        double y =  0.12  + undistorted_points[0].y * depth;
        double z = depth;
        
        return Eigen::Vector3d(x, y, z);
    }


    std::vector<double> base_T_pixel(const std::vector<double>& pixel_coordinates) {
        // 1) Build base->tool from stored pose (x,y,z,yaw)
        double yaw = orientation[2];
        Eigen::Matrix<double,4,4> base_T_tool;
        base_T_tool <<
        std::cos(yaw), -std::sin(yaw), 0.0, position[0],
        std::sin(yaw),  std::cos(yaw), 0.0, position[1],
                0.0,            0.0,    1.0, position[2],
                0.0,            0.0,    0.0,          1.0;

        // 2) Tool->camera via DH (d=0.1, a=0.08)
        Eigen::Matrix<double,4,4> tool_T_camera = calculate_DHMatrix(0.1, 0.0, 0.08, 0.0);

        // 3) Chain to get base->camera
        Eigen::Matrix<double,4,4> base_T_camera = base_T_tool * tool_T_camera;

        // 4) Back-project pixel into camera frame
        Eigen::Vector3d p_camera = pixel_to_camera_coordinates(pixel_coordinates);
        Eigen::Vector4d p_camera_homogene{p_camera.x(), p_camera.y(), p_camera.z(), 1.0};

        // 5) Transform to world
        Eigen::Vector4d world_h = base_T_camera * p_camera_homogene;

        return {world_h.x(), world_h.y(), world_h.z()};
  }

    //DH transformation matrix
    Eigen::Matrix <double,4,4> calculate_DHMatrix(double d,double theta,double a,double alpha){
        Eigen::Matrix<double, 4, 4> tr_matrix;
       //Conventional DH matrix
        tr_matrix << cos(theta), -sin(theta)*cos(alpha), sin(theta)*sin(alpha), a*cos(theta),
                    sin(theta), cos(theta)*cos(alpha), -cos(theta)*sin(alpha), a*sin(theta),
                    0, sin(alpha), cos(alpha), d,
                    0, 0, 0, 1; 
        return tr_matrix;
    }
    //Orientation in [rad]
    void set_orientation(double roll, double pitch, double yaw) {
        orientation = {roll, pitch, yaw};
    }
    //Position in [m]
    void set_position(double x, double y, double z) {
        position = {x, y, z};
        depth = -z-0.1;
    }

    cv::Mat camera_parameter_matrix;
    double c_x = 0.0;
    double c_y = 0.0;
    double depth = 0.3;
    std::vector<double> joint_angles = {0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0};
    std::vector<double> endeeffector_position = {0.0, 0.0, 0.0};
    cv::Mat distortion_coefficients;
    std::vector<double> position;
    std::vector<double> orientation;
};