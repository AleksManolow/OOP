#include"Armor.h"

Armor::Armor():Treasure()
{
    
}
void Armor::print() const
{
    std::cout << "ARMOR:";
    Treasure::print();
}