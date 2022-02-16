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
        float m_XSpeed, m_YSpeed;
        sf::Text m_text;
        void setPosition()
        {
            // position of m_shape
            sf::Vector2f previousPosition = m_shape.getPosition();
            sf::Vector2f moveVector(m_XSpeed, m_YSpeed);
            sf::Vector2f newPosition = previousPosition + moveVector;
            m_shape.setPosition(newPosition);

            // position of text
            // get position of m_shape and put an offset before assigning
            

        };
};

int main()
{
   return 0; 
};