#include"Dish.h"
char* Dish::allocateMemory(char* s)
{
    char* result = new char[strlen(s) + 1];
    strcpy(result, s);
    return result;
}
void Dish::deleteMemory(char* s)
{
    if (s != NULL)
    {
        delete[] s;
    }
}
Dish::Dish()
{
    capacity = 100;
    ingredientsNames = new char* [capacity];
    sizeOfIngredient = 0;
    for (size_t i = 0; i < capacity; i++)
    {
        ingredientsNames[i] = NULL;
    }
    cookTime = 0;
}
Dish::Dish(size_t _sizeOfIngredient,char** _ingredientsNames , double _cookTime)
{
    capacity = 100;
    sizeOfIngredient = _sizeOfIngredient;
    ingredientsNames = new char* [capacity];
    for (size_t i = 0; i < sizeOfIngredient; i++)
    {
        ingredientsNames[i] = allocateMemory(_ingredientsNames[i]);
    }
    cookTime = _cookTime;
}
Dish::Dish(const Dish& other)
{
    capacity = 100;
    sizeOfIngredient = other.sizeOfIngredient;
    ingredientsNames = new char* [capacity];
    for (size_t i = 0; i < sizeOfIngredient; i++)
    {
        ingredientsNames[i] = allocateMemory(other.ingredientsNames[i]);
    }
    cookTime = other.cookTime;
}
Dish& Dish::operator=(const Dish& other)
{
    if (this != &other)
    {
        for (size_t i = 0; i < sizeOfIngredient; i++)
        {
            deleteMemory(ingredientsNames[i]);
        }
        delete[] ingredientsNames;

        capacity = 100;
        sizeOfIngredient = other.sizeOfIngredient;
        ingredientsNames = new char* [capacity];
        for (size_t i = 0; i < sizeOfIngredient; i++)
        {
            ingredientsNames[i] = allocateMemory(other.ingredientsNames[i]);
        }
        cookTime = other.cookTime;
    }
    return *this;
}
Dish::~Dish()
{
    for (size_t i = 0; i < sizeOfIngredient; i++)
    {
        deleteMemory(ingredientsNames[i]);
    }
    delete[] ingredientsNames;
}
void Dish::print()
{
    std::cout << "Engredients: " << std::endl;
    for (size_t i = 0; i < sizeOfIngredient; i++)
    {
        std::cout << ingredientsNames[i] << std::endl;
    }
    std::cout << "Time: " << cookTime <<" minutes. "<< std::endl;
    
}