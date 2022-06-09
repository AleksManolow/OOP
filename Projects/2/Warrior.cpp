#include"Warrior.h"
Warrior::Warrior():Hero(40, 10, 50)
{

}
void Warrior::print() const
{
    std::cout << "---------WARRIOR---------" << std::endl;
    Hero::print();
    std::cout << "-------------------------" << std::endl;
}