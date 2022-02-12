#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

// https://stackoverflow.com/questions/9435385/split-a-string-using-c11
std::vector<std::string> split(const std::string &s) {
  std::stringstream ss(s);
  std::string item;
  std::vector<std::string> elems;
  char delim;
  delim = ' ';
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
void openAndReadConfigFile(std::string filename)
{
   std::string data;
   std::ifstream ifile;
   ifile.open(filename);
   std::cout << "Reading from the file" << std::endl;
   if (ifile.is_open())
   {
      std::cout << "FILE IS OPEN" << std::endl;
      while (std::getline(ifile, data))
      {
         std::cout << data << std::endl;
         for (std::string element : split(data))
         {
            std::cout << element << std::endl;
         };
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