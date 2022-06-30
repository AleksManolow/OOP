#include"MeatDish.h"
MeatDish::MeatDish():Dish()
{
    meat = NULL;
}
MeatDish::MeatDish(size_t _size, char** _ingredientsNames, double _cookTime, char* _meat):Dish(_size,_ingredientsNames, _cookTime)
{
    meat = allocateMemory(_meat);
}
MeatDish::MeatDish(const MeatDish& other):Dish(other)
{
    meat = allocateMemory(other.meat);
}
MeatDish& MeatDish::operator=(const MeatDish& other)
{
    if (this != &other)
    {
        deleteMemory(meat);
        Dish::operator=(other);
        meat = allocateMemory(other.meat);
    }
    return *this;
}
MeatDish::~MeatDish()
{
   deleteMemory(meat);
}
void MeatDish::print()
{
    Dish::print();
    std::cout << "Meat: " << meat << std::endl;
}