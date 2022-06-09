#include"Spell.h"

Spell::Spell(): Treasure(20, "Ognena topka")
{

}

void Spell::print() const
{
    std::cout << "SPELL:";
    Treasure::print();
}