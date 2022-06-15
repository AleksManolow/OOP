#ifndef __HERO_H
#define __HERO_H
#include"Armor.h"
#include"Weapon.h"
#include"Spell.h"

class Hero
{
private:
    double force;
    double mana;
    double health;

    Armor armor;
    Weapon weapon;
    Spell spell;

public:
    Hero(double ,double ,double );
    virtual ~Hero() = default;

    virtual void print() const;

    double getForse() const;
    double getMana() const;
    double getHealth() const;
    Armor getArrmor() const;
    Weapon getWeapon() const;
    Spell getSpell() const;

    void setForse(double );
    void setMana(double );
    void setHealth(double );
    void setArrmor(Armor& );
    void setWeapon(Weapon& );
    void setSpell(Spell& );

    virtual void loadFromStream(std::istream& in);
    virtual void writeToStream(std::ostream& out) const; 
};



#endif