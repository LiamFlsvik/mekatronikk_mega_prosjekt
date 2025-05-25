
#include <Eigen/Dense>
#include <opencv2/opencv.hpp>
#include <vector>

class matrix_transformations {
    public:

    matrix_transformations(){
    
        camera_parameter_matrix = (cv::Mat_<double>(3,3) << 585.20149,    0.0,         359.74242,
                                                            0.0,           584.03096,  256.50443,
                                                            0.0,           0.0,          1.0);

        distortion_coefficients = (cv::Mat_<double>(1,5) << 0.173910, -0.181651, 0.010147, 0.032039, 0.0);

    } 
    
    public:

  
    // Camera pixel coordinates to base coordinates:
    Eigen::Matrix <double,3,1> pixel_to_camera_coordinates(const std::vector<double>& pixel_coordinates, double depth_ = 0.3) {
        
        
        std::vector<cv::Point2d> distored_points;
        distored_points.emplace_back(pixel_coordinates[0], pixel_coordinates[1]);

        //Undistort image:
        std::vector<cv::Point2d> undistorted_points;
        cv::undistortPoints(distored_points, undistorted_points, camera_parameter_matrix, distortion_coefficients);

        //Normalized pixel coordinates:
        double x = undistorted_points[0].x * depth_;
        double y = undistorted_points[0].y * depth_;
        double z = depth_;
        //

        return Eigen::Vector3d(x, y, z);

    }

    // Camera coordinates to base coordinates:
    std::vector<double> camera_to_base_coordinates(const std::vector<double>& pixel_coordinates, const std::vector<double>& joint_angles, double depth_ = 0.3){
        //Get camera coordinates:
        Eigen::Vector4d camera_coordinates;
        camera_coordinates << pixel_to_camera_coordinates(pixel_coordinates, depth_), 1.0;

        //Get transformation matrix from base to camera:
        Eigen::Matrix<double, 4, 4> c_T_b = T_camera_from_base(joint_angles);
        Eigen::Matrix4d b_T_c = c_T_b.inverse(); 

        //Transform camera coordinates to base coordinates:
        Eigen::Vector4d base_coordinates = b_T_c * camera_coordinates;
        std::vector<double> base_coordinates_vector = {base_coordinates(0), base_coordinates(1), base_coordinates(2)};
        return base_coordinates_vector;
    }

    // Transformation matrix from base to camera
    Eigen::Matrix <double,4,4> T_camera_from_base(const std::vector<double> joint_angles_){
        Eigen::Matrix <double,4,4> camera_T_base;   
        camera_T_base = 
            calculate_DHMatrix(0.1519,    joint_angles_[0],         0.0,            M_PI/2.0)*
            calculate_DHMatrix(0.0,       joint_angles_[1],      -0.24365,             0.0)*
            calculate_DHMatrix(0.0,       joint_angles_[2],      -0.213250,            0.0)*
            calculate_DHMatrix(0.11235,   joint_angles_[3],      0.0,             M_PI/2.0)*
            calculate_DHMatrix(0.08535,   joint_angles_[4],      0.0,            -M_PI/2.0)*
            calculate_DHMatrix(0.0819,    joint_angles_[5],      0.0,                  0.0)*
            calculate_DHMatrix(0.1,                    0.0,      0.08,                 0.0); 
        return camera_T_base;
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


    cv::Mat camera_parameter_matrix;
    double c_x = 0.0;
    double c_y = 0.0;
    double depth = 0.3;
    std::vector<double> joint_angles = {0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0};
    std::vector<double> endeeffector_position = {0.0, 0.0, 0.0};
    cv::Mat distortion_coefficients;



};