#include<iostream>
#include<string>
#include<fstream>
#include"GenerateMap.h"
#include"CoordinatesHero.h"
#include"TaskManager.h"
int main()
{
    // std::fstream listOfProperties("Level1.txt", std::ios::in | std::ios::out);
    // GenerateMap a;
    // listOfProperties >> a;
    // std::cout << a;
    TaskManager a;
    a.openFile();
    a.saveFile();
    //a.writeToStream(std::cout);

    return 0;
}