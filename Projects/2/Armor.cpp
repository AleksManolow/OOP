#include"Armor.h"

Armor::Armor():Treasure()
{
    
}
Armor::Armor(double _percent, String _name):Treasure(_percent, _name)
{
    
}
void Armor::print() const
{
    std::cout << "ARMOR:";
    Treasure::print();
}
void Armor::loadFromStream(std::istream& in)
{
    Treasure::loadFromStream(in);
}
void Armor::writeToStream(std::ostream& out)
{
    out << "Armor" <<'\n';
    Treasure::writeToStream(out);

}