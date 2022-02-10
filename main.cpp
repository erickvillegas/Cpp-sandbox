#include <iostream>
void myfunc(int * myarray);
void myfunc2(int myarray[]);

int main() {
  std::cout << "Hello World!\n";
  int arr[3];
  arr[0] = 5;
  arr[1] = 10;
  *(arr+2) = 20;
  // arr[3] = 40;
  std::cout << &arr[0] << std::endl;
  std::cout << &arr[1] << std::endl;
  std::cout << &arr[2] << std::endl;
  int * myarr = new int[];
  myarr[0] = 10;
  myarr[1] = 20;
  myarr[2] = 30;
  myarr[3] = 50;
  std::cout << myarr[0] << std::endl;
  std::cout << *(myarr+1) << std::endl;
  std::cout << 1[myarr] << std::endl;
  std::cout << myarr[2] << std::endl;

  myfunc(myarr);
  std::cout << myarr[0] << std::endl;
  std::cout << myarr[1] << std::endl;
  std::cout << myarr[2] << std::endl;
  std::cout << myarr[3] << std::endl;
  std::cout << myarr[4] << std::endl;
  myfunc2(myarr);
  std::cout << myarr[0] << std::endl;
  std::cout << myarr[1] << std::endl;
  std::cout << myarr[2] << std::endl;
  std::cout << myarr[3] << std::endl;
  return 0;
}

void myfunc(int * myarray)
{
  myarray[1] = 25;
  myarray[3] = 11;
}

void myfunc2(int myarray[])
{
  myarray[1] = 52;
  myarray[3] = 2;
}