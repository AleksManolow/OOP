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
void Person::loadFromStream(std::istream& in)
{
    Hero::loadFromStream(in);
}
void Person::writeToStream(std::ostream& out) const
{
    out << "Person" << '\n';
    Hero::writeToStream(out);
}