#include"SurfAndTurf.h"
SurfAndTurf::SurfAndTurf():MeatDish(), SeafoodDish()
{

}
SurfAndTurf::SurfAndTurf(size_t _size, char** _ingredientsNames, double _cookTime, char* _meat, char* _seafood)
:Dish(_size, _ingredientsNames, _cookTime),
MeatDish(_size, _ingredientsNames, _cookTime, _meat), 
SeafoodDish(_size, _ingredientsNames, _cookTime, _seafood)
{

}
SurfAndTurf::SurfAndTurf(const SurfAndTurf& other)
:Dish(other),
MeatDish(other), 
SeafoodDish(other)
{

}
SurfAndTurf& SurfAndTurf::operator=(const SurfAndTurf& other)
{
    if (this != &other)
    {
        Dish::operator=(other);
        MeatDish::operator=(other);
        SeafoodDish::operator=(other);
    }
    return *this;
}
SurfAndTurf::~SurfAndTurf()
{

}
void SurfAndTurf::print()
{
    Dish::print();
    std::cout << "Meat: " << MeatDish::getMeat() << std::endl;
    std::cout << "SeaFood: " << SeafoodDish::getSeafood()<< std::endl;
}