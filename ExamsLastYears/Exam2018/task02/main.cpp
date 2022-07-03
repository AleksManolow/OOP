#include<iostream>
#include"Map.h"
int main()
{
    Map<std::string, double> firstMap; 
    firstMap.push_back("aleks" , 8.5);
    firstMap.push_back("gosho", 2.5);
    Map<std::string, double> secoundMap; 
    secoundMap.push_back("aleks" , 8.5);
    secoundMap.push_back("gosho", 2.5);
    Map<std::string, double> c = firstMap + secoundMap; 
    std::cout << c;

    return 0;
}