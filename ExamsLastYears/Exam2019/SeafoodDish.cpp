#include"SeafoodDish.h"
SeafoodDish::SeafoodDish():Dish()
{
    seafood = NULL;
}
SeafoodDish::SeafoodDish(size_t _size, char** _ingredientsNames, double _cookTime, char* _seafood):Dish(_size,_ingredientsNames, _cookTime)
{
    seafood = allocateMemory(_seafood);
}
SeafoodDish::SeafoodDish(const SeafoodDish& other):Dish(other)
{
    seafood = allocateMemory(other.seafood);
}
SeafoodDish& SeafoodDish::operator=(const SeafoodDish& other)
{
    if (this != &other)
    {
        deleteMemory(seafood);
        Dish::operator=(other);
        seafood = allocateMemory(other.seafood);
    }
    return *this;
}
SeafoodDish::~SeafoodDish()
{
   deleteMemory(seafood);
}
void SeafoodDish::print()
{
    Dish::print();
    std::cout << "Seafood: " << seafood << std::endl;
}