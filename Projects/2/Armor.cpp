#include"Armor.h"

Armor::Armor():Treasure()
{
    
}
Armor::Armor(double _percent, std::string _name):Treasure(_percent, _name)
{
    
}
void Armor::print() const
{
    std::cout << "ARMOR:";
    Treasure::print();
}