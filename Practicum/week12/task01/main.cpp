#include<iostream>
#include"House.h"
int main()
{
    House a;
    a.loadFromStream(std::cin);
    a.writeToStream(std::cout);

    return 0;
}