#include"Hero.h"

Hero::Hero(double _forse , double _mana, double _health):armor(), weapon(), spell()
{
    force = _forse;
    mana = _mana;
    health = _health;

}
void Hero::print() const
{
    std::cout << "Indicators of the hero!" << std::endl;
    std::cout << "Forse:"<< force << std::endl;
    std::cout << "Mana:"<< mana << std::endl;
    std::cout << "Health:" << health << std::endl;
    armor.print();
    weapon.print();
    spell.print();
}

double Hero::getForse() const
{
    return force;
}
double Hero::getMana() const
{
    return mana;
}
double Hero::getHealth() const
{
    return health;
}
Armor Hero::getArrmor() const
{
    return armor;
}
Weapon Hero::getWeapon() const
{
    return weapon;
}
Spell Hero::getSpell() const
{
    return spell;
}

void Hero::setForse(double _forse)
{
    force = _forse;
}
void Hero::setMana(double _mana)
{
    mana = _mana;
}
void Hero::setHealth(double _health)
{
    health = _health;
}
void Hero::setArrmor(Treasure* _armor)
{
    armor.setName(_armor->getName());
    armor.setPercent(_armor->getPercent());
}
void Hero::setWeapon(Treasure* _weapon)
{
    weapon.setName(_weapon->getName());
    weapon.setPercent(_weapon->getPercent());
}
void Hero::setSpell(Treasure* _spell)
{
    spell.setName(_spell->getName());
    spell.setPercent(_spell->getPercent());
}
void Hero::loadFromStream(std::istream& in)
{
    in >> force;
    in >> mana;
    in >> health;
    armor.loadFromStream(in);
    weapon.loadFromStream(in);
    spell.loadFromStream(in);
}
void Hero::writeToStream(std::ostream& out) const
{
    out << force << '\n';
    out << mana << '\n';
    out << health << '\n';
    out << armor.getPercent() << '\n';\
    out << armor.getName() << '\n';
    out << weapon.getPercent() << '\n';\
    out << weapon.getName() << '\n';
    out << spell.getPercent() << '\n';\
    out << spell.getName() << '\n';
}