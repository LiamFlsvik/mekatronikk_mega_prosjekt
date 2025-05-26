

#include <string>
#include <vector>
#include <stdexcept>
#include <algorithm>

class box_handler{

public:
    box_handler(){
        //Constructor for box handler
        //Initialize the virtual boxes vector
        virtual_boxes = std::vector<Box>();

    }


    void create_virtual_box(const std::string name_, std::string color, const std::vector<double> position, const double yaw = 0, std::vector<double> size){
        //Check if the position is valid
        if (position.size() != 3) {
            throw std::runtime_error("Position must be a vector of size 3 including; x, y, z ");
        }
        if(!check_name(name_)){
            
            //Create a virtual box 
            std::vector<double> position_ = {position[0], position[1], position[2], yaw}; // x, y, z, yaw
            std::vector<double> size = {0.1, 0.1, 0.1}; //Default size
            std::string color = color; //Default color
            virtual_boxes.emplace_back(name_, position, size, color);
        } else {
            throw std::runtime_error("Box with the name: " + name_ + " is already made, overwriting the current box.");
            update_box(name_, position);
        }

    }
    void remove_virtual_box(const std::string& name) {
        //Find the box with the given name
        auto it = std::remove_if(virtual_boxes.begin(), virtual_boxes.end(),
            [&name](const Box& box) { return box.name == name; });

        //Remove box if found
        if (it != virtual_boxes.end()) {
            virtual_boxes.erase(it, virtual_boxes.end());
        } else {
            throw std::runtime_error("Box with the name: " + name + " does not exist.");
        }
    }
    void update_box(const std::string& name, std::vector<double> position){
        //Find the box with the given name
        auto it = std::find_if(virtual_boxes.begin(), virtual_boxes.end(),
            [&name](const Box& box) { return box.name == name; });

        if (it != virtual_boxes.end()) {
            if (position.size() != 4) {
                throw std::runtime_error("Position must be a vector of size 4 including; x, y, z. and yaw");
            }
        } else {
            throw std::runtime_error("Box with the name: " + name + " does not exist.");
        }
        if(check_updated_point(name,position)){
            it->position = position;
        }

    }

    bool check_updated_point(std::string name, std::vector<double> position){
        //Find the box with the given name
        auto it = std::find_if(virtual_boxes.begin(), virtual_boxes.end(),
            [&name](const Box& box) { return box.name == name; });
        
        //Check the current box position against the new one:
        if (deadzone_x < std::abs(it->position[0] - position[0]) ||
            deadzone_y < std::abs(it->position[1] - position[1]) ||
            deadzone_z < std::abs(it->position[2] - position[2])) {
            return false; //Position is not updated
        } else {
            return true; //Position is updated
        }
    }


     //Check if the name already exists in the virtual boxes
    bool check_name(const std::string& name) {
        for (const auto& box : virtual_boxes) {
            if (box.name == name) {
                throw std::runtime_error("Box with the name: " + name + " already exists.");
            }
        }
    }

    private:

    //Struct for boxes:
    struct Box{
        std::string name;
        std::vector<double> position{0,0,0,0};  // x y z yaw
        std::vector<double> size{0,0,0}; 
        std::string color = "grey"; 
        Box(const std::string& name, const std::vector<double>& position, const std::vector<double>& size, const std::string& color)
            : name(name), position(position), size(size), color(color) {}
    };
    
    std::vector<Box> virtual_boxes; 
    double deadzone_x = 0.05; // Deadzone for x position
    double deadzone_y = 0.05; // Deadzone for y position
    double deadzone_z = 0.05; // Deadzone for z position

};