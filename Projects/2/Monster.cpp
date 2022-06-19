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
double Monster::getForse() const
{
    return force;
}
double Monster::getMana() const
{
    return mana;
}
double Monster::getHealth() const
{
    return health;
}
Armor Monster::getArrmor() const
{
    return armor;
}
void Monster::setForse(double _forse)
{
    force = _forse;
}
void Monster::setMana(double _mana)
{
    mana = _mana;
}
void Monster::setHealth(double _health)
{
    health = _health;
}
void Monster::setArrmor(Armor& _armor)
{
    armor = _armor;
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