#include"Weapon.h"

Weapon::Weapon():Treasure(20, "Obiknowen mech")
{

}

void Weapon::print() const
{
    std::cout << "WEAPON:";
    Treasure::print();
}
