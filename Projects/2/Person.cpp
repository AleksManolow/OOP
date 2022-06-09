#include"Person.h"

Person::Person():Hero(30, 20, 50)
{

}

void Person::print() const
{
    std::cout << "---------Person---------" << std::endl;
    Hero::print();
    std::cout << "------------------------" << std::endl;
    
}