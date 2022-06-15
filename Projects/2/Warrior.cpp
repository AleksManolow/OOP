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
void Warrior::loadFromStream(std::istream& in)
{
    Hero::loadFromStream(in);
}
void Warrior::writeToStream(std::ostream& out)const
{
    out << "Warrior" << '\n';
    Hero::writeToStream(out);
}