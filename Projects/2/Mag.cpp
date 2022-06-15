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
void Mag::loadFromStream(std::istream& in)
{
    Hero::loadFromStream(in);
}
void Mag::writeToStream(std::ostream& out) const
{
    out << "Mag" << '\n';
    Hero::writeToStream(out);
}