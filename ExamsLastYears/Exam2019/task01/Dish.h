#ifndef __DISH_H
#define __DISH_H
#include<iostream>
#include<cstring>

class Dish
{
private:
    size_t capacity;
    size_t sizeOfIngredient;
    char** ingredientsNames;
    double cookTime;
protected:
    char* allocateMemory(char* s);
    void deleteMemory(char* s);
public:
    Dish();
    Dish(size_t ,char** , double );
    Dish(const Dish& );
    Dish& operator=(const Dish& );
    ~Dish();

    void print();
};

#endif