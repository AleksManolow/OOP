#include<iostream>
#include<fstream>
#include"Date.h"
int main()
{
    std::ifstream fileToRead("dareRead.txt");
    Date date1 = date1.readDate(fileToRead);



    return 0;
}