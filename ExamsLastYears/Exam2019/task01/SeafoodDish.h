#ifndef __SEAFOODDISH_H
#define __SEAFOODDISH_H
#include"Dish.h"
class SeafoodDish:virtual public Dish
{
private:
    char* seafood;
public:
    SeafoodDish(/* args */);
    SeafoodDish(size_t , char** , double , char* );
    SeafoodDish(const SeafoodDish& );
    SeafoodDish& operator=(const SeafoodDish& );
    ~SeafoodDish();

    void print();

    char* getSeafood() {return seafood;};
};

#endif