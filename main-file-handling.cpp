#include <iostream>
#include <fstream>


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