#include"Weapon.h"

Weapon::Weapon():Treasure(20, "Obiknowen mech")
{

}

void Weapon::print() const
{
    std::cout << "WEAPON:";
    Treasure::print();
}

void Weapon::loadFromStream(std::istream& in)
{
    Treasure::loadFromStream(in);
}
void Weapon::writeToStream(std::ostream& out)
{
    out << "Weapon" <<'\n';
    Treasure::writeToStream(out);

}