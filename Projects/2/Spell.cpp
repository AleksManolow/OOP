#include"Spell.h"

Spell::Spell(): Treasure(20, "Ognena topka")
{

}

void Spell::print() const
{
    std::cout << "SPELL:";
    Treasure::print();
}
void Spell::loadFromStream(std::istream& in)
{
    Treasure::loadFromStream(in);
}
void Spell::writeToStream(std::ostream& out)
{
    out << "Spell" <<'\n';
    Treasure::writeToStream(out);

}