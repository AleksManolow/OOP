#ifndef __MONSTER_H
#define __MONSTER_H
#include"Armor.h"

class Monster
{
private:
    double force;
    double mana;
    double health;

    Armor armor;
public:
    Monster();
    void print() const;

    double getForse() const;
    double getMana() const;
    double getHealth() const;
    Armor getArrmor() const;

    void setForse(double );
    void setMana(double );
    void setHealth(double );
    void setArrmor(Armor& );

    void loadFromStream(std::istream& in);
    void writeToStream(std::ostream& out) const;
};



#endif