#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>
#include <vector>

/*
Shape class with text
*/
template <class T>
class Shape
{
    public:
        T m_shape;
        sf::Text m_text;
        void setPosition();
};

int main()
{
   return 0; 
};