#include <iostream>
#include <fstream>

class Shape
{
    std::string m_shape_type;
    std::string m_name; //Shape name
    float m_x; //initial x position
    float m_y; //initial y position
    float m_sx; //initial speed in x axis
    float m_sy; //initial speed in y axis
    int m_r; //Red in RGB
    int m_g; //Green in RGB
    int m_b; //Blue in RGB

public:
    Shape(std::string shape, 
          std::string name, 
          float x, 
          float y, 
          float sx, 
          float sy, 
          int r, 
          int g, 
          int b);

};

int main()
{
   return 0; 
};