#include<iostream>
#include<string>
#include<fstream>
#include"GenerateMap.h"
#include"CoordinatesHero.h"
int main()
{
    std::fstream listOfProperties("Level1.txt", std::ios::in | std::ios::out);
    GenerateMap a;
    listOfProperties >> a;
    std::cout << a;


    return 0;
}