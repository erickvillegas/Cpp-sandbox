#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <utility>

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
void openAndReadConfigFile(std::string filename)
{
   std::string data;
   std::ifstream ifile;
   ifile.open(filename);
   std::cout << "Reading from the file" << std::endl;
   std::vector<std::string> myvec;
   if (ifile.is_open())
   {
      std::cout << "FILE IS OPEN" << std::endl;
      while (std::getline(ifile, data))
      {
         std::cout << data << std::endl;
         myvec = split(data, ' ');
         if (myvec[0].compare("Window") == 0) 
         {
            std::cout << "Window FOUND!" << std::endl;
         }
         if (myvec[0].compare("Font") == 0) 
         {
            std::cout << "Font FOUND!" << std::endl;
         }
         if (myvec[0].compare("Circle") == 0) 
         {
            std::cout << "Circle FOUND!" << std::endl;
         }
         if (myvec[0].compare("Rectangle") == 0) 
         {
            std::cout << "Rectangle FOUND!" << std::endl;
         }

      }
   }
   ifile.close();
}

int main()
{
   // openAndReadFile();
   openAndReadConfigFile("config.txt");
   return 0; 
}