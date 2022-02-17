#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <utility>
#include <memory>

// https://stackoverflow.com/questions/9435385/split-a-string-using-c11
std::vector<std::string> split(const std::string &s, char delim) {
  std::stringstream ss(s);
  std::string item;
  std::vector<std::string> elems;
  while (std::getline(ss, item, delim)) {
    elems.push_back(item);
  }
  return elems;
}

/*
base-class
*/
class S{};

/*
Shape class with text
*/
template <class T>
class Shape : public S{
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

void openAndReadFile()
{
   char data[100];

   std::ofstream ofile;
   ofile.open("afile.dat");
   std::cout << "Enter name: ";
   std::cin.getline(data, 100);
   ofile << data << std::endl;
   ofile.close();

   std::ifstream ifile;
   ifile.open("afile.dat");
   std::cout << "Reading from the file" << std::endl;
   ifile >> data;
   std::cout << data << std::endl;
   ifile >> data;
   std::cout << data << std::endl;
   ifile.close();
}

/*
sample function that will open config file and split using space as 
delimiter.
also shows that you can use array indexing on std::vector
*/
void openAndReadConfigFile(std::string filename, 
                           int & wheight,
                           int & wwidth,
                           sf::Font & font,
                           int & fontSize,
                           sf::Color & color,
                           std::vector<std::shared_ptr<Shape<sf::CircleShape>>> & circles, 
                           std::vector<std::shared_ptr<Shape<sf::RectangleShape>>> & rectangles 
                           )
{
   std::string data;
   std::ifstream ifile;
   ifile.open(filename);
   // std::cout << "Reading from the file" << std::endl;
   std::vector<std::string> myvec;
   if (ifile.is_open())
   {
      // std::cout << "FILE IS OPEN" << std::endl;
      while (std::getline(ifile, data))
      {
         // std::cout << data << std::endl;
         myvec = split(data, ' ');
         if (myvec[0].compare("Window") == 0) 
         {
            // std::cout << "Window FOUND!" << std::endl;
            wheight = std::stoi(myvec[1]);
            wwidth = std::stoi(myvec[2]);
         }
         if (myvec[0].compare("Font") == 0) 
         {
            // std::cout << "Font FOUND!" << std::endl;
            // font = sf::Font(myvec[1]);
            font.loadFromFile(myvec[1]);
            fontSize = std::stoi(myvec[2]);
            color = sf::Color(std::stoi(myvec[3]), std::stoi(myvec[4]), std::stoi(myvec[5]));
         }
         if (myvec[0].compare("Circle") == 0) 
         {
            // std::cout << "Circle FOUND!" << std::endl;
            sf::CircleShape circle;
            circle.setPosition(std::stoi(myvec[2]), std::stoi(myvec[3]));
            circle.setFillColor(sf::Color(std::stoi(myvec[6]), std::stoi(myvec[7]), std::stoi(myvec[8])));
            circle.setRadius(std::stoi(myvec[9]));
            sf::Text name;
            name.setString(myvec[1]);
            name.setFont(font);
            name.setCharacterSize(fontSize);

            Shape<sf::CircleShape>* shapeContainer = new Shape <sf::CircleShape>();  
            shapeContainer->m_XSpeed = std::stof(myvec[4]);
            shapeContainer->m_YSpeed = std::stof(myvec[5]);
            shapeContainer->m_shape = circle;
            shapeContainer->m_text = name;
            circles.push_back(std::shared_ptr<Shape<sf::CircleShape>> (shapeContainer));
         }
         if (myvec[0].compare("Rectangle") == 0) 
         {
            // std::cout << "Rectangle FOUND!" << std::endl;
            sf::RectangleShape rectangle;
            rectangle.setPosition(std::stoi(myvec[2]), std::stoi(myvec[3]));
            rectangle.setFillColor(sf::Color(std::stoi(myvec[6]), std::stoi(myvec[7]), std::stoi(myvec[8])));
            rectangle.setSize(sf::Vector2f(std::stoi(myvec[9]), std::stoi(myvec[10])));
            sf::Text name;
            name.setString(myvec[1]);
            name.setFont(font);
            name.setCharacterSize(fontSize);

            Shape<sf::RectangleShape>* shapeContainer = new Shape <sf::RectangleShape>();  
            shapeContainer->m_XSpeed = std::stof(myvec[4]);
            shapeContainer->m_YSpeed = std::stof(myvec[5]);
            shapeContainer->m_shape = rectangle;
            shapeContainer->m_text = name;
            rectangles.push_back(std::shared_ptr<Shape<sf::RectangleShape>> (shapeContainer));
         }
      }
   }
   ifile.close();
}

int main()
{
   // openAndReadFile();
   int wHeight = 600;
   int wWidth = 400;
   sf::Font font;
   int fontSize = 12;
   sf::Color fontColor = sf::Color::White;
   std::vector<std::shared_ptr<Shape<sf::CircleShape>>> circles;
   std::vector<std::shared_ptr<Shape<sf::RectangleShape>>> rectangles;
   
   std::cout << "Font Color =  " << fontColor.toInteger() << std::endl;

   openAndReadConfigFile("config.txt", wHeight, wWidth, font, fontSize, fontColor, circles, rectangles);

   std::cout << "wHeight =  " << wHeight << std::endl;
   std::cout << "wWidth =  " << wWidth << std::endl;
   // std::cout << "Font =  " << font.getInfo() << std::endl;
   std::cout << "Font Size =  " << fontSize << std::endl;
   std::cout << "Font Color =  " << fontColor.toInteger() << std::endl;
   std::cout << "circles size = " << circles.size() << std::endl;
   std::cout << "rectangles size = " << rectangles.size() << std::endl;
   for (std::shared_ptr<Shape<sf::CircleShape>> i : circles)
   {
      std::cout << std::string(i->m_text.getString()) << std::endl;
   }
   for (std::shared_ptr<Shape<sf::RectangleShape>> i : rectangles)
   {
      std::cout << std::string(i->m_text.getString()) << std::endl;
   }
   return 0; 
}