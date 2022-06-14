#include"Monster.h"

Monster::Monster():armor(15, "Lyspite")
{
    force = 25;
    mana = 25;
    health = 30;
}
void Monster::print() const
{
    std::cout << "---------MONSTER---------" << std::endl;
    std::cout << "Forse:"<< force << std::endl;
    std::cout << "Mana:"<< mana << std::endl;
    std::cout << "Health:" << health << std::endl;
    armor.print();
    std::cout << "-------------------------" << std::endl;
}
void Monster::loadFromStream(std::istream& in)
{
    in >> force;
    in >> mana;
    in >> health;
    armor.loadFromStream(in);
}
void Monster::writeToStream(std::ostream& out) const
{
    out << force << '\n';
    out << mana << '\n';
    out << health << '\n';
    out << armor.getPercent() << '\n';\
    out << armor.getName() << '\n';
}