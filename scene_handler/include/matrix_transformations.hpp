
#include <Eigen/Dense>
#include <vector>

class matrix_transformations {
    public:

    matrix_transformations(){
    
        camera_parameter_matrix << 585.20149,    0,         359.74242,
                                   0,           584.03096,  256.50443,
                                   0,           0,          1.0;

        camera_parameter_matrix_inverse = camera_parameter_matrix.inverse();

    } 
      
    std::vector<double> calculate_box_position(const std::vector<double>& joint_angles_, const std::vector<double>& pixel_coordinates){
        if (joint_angles_.size() < 6) {
            throw std::invalid_argument("Joint angles must be a vector of size 6.");
        }
        Eigen::Vector3d base_coordinates = camera_T_base(joint_angles_, pixel_coordinates);
        std::vector<double> box_position = {base_coordinates(0), base_coordinates(1), base_coordinates(2)};
        return box_position;
    }

    private:
  
    // Camera pixel coordinates to base coordinates:
    Eigen::Matrix <double,3,1> camera_T_base(const std::vector<double>& joint_angles_, const std::vector<double>& pixel_coordinates){
        Eigen::Matrix <double,4,4> c_T_b = calculate_c_T_b(joint_angles_);
        Eigen::Matrix <double,3,1> camera_coordinates = pixel_T_camera(pixel_coordinates);
        Eigen::Vector4d camera_coordinates_homogeneous(camera_coordinates(0), camera_coordinates(1), camera_coordinates(2), 1.0);
        Eigen::Vector4d base_coordinates_homogeneous = c_T_b * camera_coordinates_homogeneous;
        return base_coordinates_homogeneous.head<3>();
    }

      // Pixel coordinates to camera coordinates:
    Eigen::Matrix <double,3,1> pixel_T_camera(const std::vector<double>& pixel_coordinates){
    if (pixel_coordinates.size() < 2) {
        throw std::invalid_argument("Pixel coordinates must be a vector of size 2.");
    }
    Eigen::Vector3d pixel_vector;
    pixel_vector << pixel_coordinates[0], pixel_coordinates[1], 1.0;

    Eigen::Matrix<double, 3, 1> ray = camera_parameter_matrix_inverse * pixel_vector;
    ray.normalize();  // direction vector

    return 0.3 * ray;  // Return scaled direction in camera frame
}


    // Transformation matrix from camera to base frame:
    Eigen::Matrix <double,4,4> calculate_c_T_b(const std::vector<double>& joint_angles_){
        return  base_T_camera(joint_angles_).inverse();
    }


    // Transformation matrix from base to camera
    Eigen::Matrix <double,4,4> base_T_camera(const std::vector<double> joint_angles_){
        Eigen::Matrix <double,4,4> b_T_c;
        b_T_c = 
            calculate_DHMatrix(0.1519,    joint_angles_[0],         0,          M_PI/2)*
            calculate_DHMatrix(0,         joint_angles_[1],      -0.24365,           0)*
            calculate_DHMatrix(0,         joint_angles_[2],      -0.213250,          0)*
            calculate_DHMatrix(0.11235,   joint_angles_[3],      0,             M_PI/2)*
            calculate_DHMatrix(0.08535,   joint_angles_[4],      0,            -M_PI/2)*
            calculate_DHMatrix(0.0819,    joint_angles_[5],      0,                  0)*
            calculate_DHMatrix(0.1,                    0.0,      0.08,           -M_PI); //0.1 0 0.08 0
        return b_T_c;
    }

    //DH transformation matrix
    Eigen::Matrix <double,4,4> calculate_DHMatrix(double d,double theta,double a,double alpha){
        Eigen::Matrix<double, 4, 4> tr_matrix;
        tr_matrix << cos(theta), -sin(theta)*cos(alpha), sin(theta)*sin(alpha), a*cos(theta),
                    sin(theta), cos(theta)*cos(alpha), -cos(theta)*sin(alpha), a*sin(theta),
                    0, sin(alpha), cos(alpha), d,
                    0, 0, 0, 1;
        return tr_matrix;
    }


  Eigen::Matrix <double,3,3> camera_parameter_matrix;
  Eigen::Matrix<double, 3,3> camera_parameter_matrix_inverse;

  std::vector<double> joint_angles = {0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0};


};