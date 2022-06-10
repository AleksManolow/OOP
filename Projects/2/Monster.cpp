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