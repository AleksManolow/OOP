#ifndef __MEATDISH_H
#define __MEATDISH_H
#include"Dish.h"

class MeatDish: virtual public Dish
{
private:
    char* meat;

public:
    MeatDish();
    MeatDish(size_t , char** , double , char* );
    MeatDish(const MeatDish& );
    MeatDish& operator=(const MeatDish& );
    ~MeatDish();

    void print();
    char* getMeat() {return meat;};
};

#endif