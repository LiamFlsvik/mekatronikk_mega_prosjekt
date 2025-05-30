
#include <Eigen/Dense>
#include <opencv2/opencv.hpp>
#include <vector>

class matrix_transformations {
    public:

    matrix_transformations(){
        camera_parameter_matrix = (cv::Mat_<double>(3,3) << -550.074787, 0.000000, 313.652175,
                                                            0.000000, 548.618685, 262.686364,
                                                            0.000000, 0.000000, 1.000000);

        distortion_coefficients = (cv::Mat_<double>(1,5) << 0.161813, -0.106074, 0.003609, -0.009673, 0.000000);
    } 
    
    // Camera pixel coordinates to base coordinates:
    Eigen::Matrix <double,3,1> pixel_to_camera_coordinates(const std::vector<double>& pixel_coordinates) {
        std::vector<cv::Point2d> distored_points;
        distored_points.emplace_back(pixel_coordinates[0], pixel_coordinates[1]);

        //Undistort image:
        std::vector<cv::Point2d> undistorted_points;
        cv::undistortPoints(distored_points, undistorted_points, camera_parameter_matrix, distortion_coefficients);

        //Normalized camera coordinates:
        double x =  -camera_x_offset + undistorted_points[0].x * depth;
        double y =  -camera_y_offset + undistorted_points[0].y * depth;
        double z =  depth;
        
        return Eigen::Vector3d(x, y, z);
    }


    std::vector<double> base_T_pixel(const std::vector<double>& pixel_coordinates) {
        
        //Tool to base transform
        double yaw = orientation[2];
        Eigen::Matrix<double,4,4> base_T_tool;
        base_T_tool <<
        std::cos(yaw), -std::sin(yaw), 0.0, position[0],
        std::sin(yaw),  std::cos(yaw), 0.0, position[1],
                0.0,            0.0,    1.0, position[2],
                0.0,            0.0,    0.0,          1.0;

        
        Eigen::Matrix<double,4,4> tool_T_camera = calculate_DHMatrix(0.1, M_PI, 0.08, 0); //calculate_DHMatrix(0.1, 0.0, 0.08, 0.0);
        //Camera to base
        Eigen::Matrix<double,4,4> base_T_camera = base_T_tool * tool_T_camera;

        //Pixel to camera frame
        Eigen::Vector3d p_camera = pixel_to_camera_coordinates(pixel_coordinates);
        Eigen::Vector4d p_camera_homogene{p_camera.x(), p_camera.y(), p_camera.z(), 1.0};

        //Transform to world
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
    public:
    //Orientation in [rad]
    void set_orientation(double roll, double pitch, double yaw) {
        orientation = {roll, pitch, yaw};
    }
    //Position in [m]
    void set_position(double x, double y, double z) {
        position = {x, y, z};
        depth = z-0.09; //-z.
    }
    void set_camera_offset_x(double x_offset) {
        camera_x_offset = x_offset;
    }
    void set_camera_offset_y(double y_offset) {
        camera_y_offset = y_offset;
    }
    private:
    cv::Mat camera_parameter_matrix;
    double camera_x_offset = -0.025;
    double camera_y_offset = 0.12;
    double depth = 0.3;
    std::vector<double> joint_angles = {0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0};
    std::vector<double> endeeffector_position = {0.0, 0.0, 0.0};
    cv::Mat distortion_coefficients;
    std::vector<double> position;
    std::vector<double> orientation;

};