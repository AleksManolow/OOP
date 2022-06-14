#include<iostream>
#include<string>
#include<fstream>
#include"Map.h"
int main()
{
    std::fstream listOfProperties("textF.txt", std::ios::in | std::ios::out);
    Map a;
    listOfProperties >> a;
    std::cout << a;


    return 0;
}