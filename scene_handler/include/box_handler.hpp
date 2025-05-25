

#include <string>
#include <vector>

class box_handler{

public:
    box_handler(){
        
    }



    void add_virtual_box(const std::string name_, const std::vector<double> position){
            
    }



    private:
    //Struct for boxes:
    struct Box{
        std::string name;
        std::vector<double> position; 
        std::vector<double> size{0,0,0}; 
        std::string color;

    }

};