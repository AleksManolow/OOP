#include"Mag.h"

Mag::Mag():Hero(10, 40, 50)
{

}

void Mag::print() const
{
    std::cout << "-----------MAG-----------" << std::endl;
    Hero::print();
    std::cout << "-------------------------" << std::endl;
}