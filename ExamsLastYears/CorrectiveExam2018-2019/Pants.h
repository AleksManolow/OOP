#ifndef __PANTS_H
#define __PANTS_H
#include"Clothes.h"

class Pants:public Clothes
{
private:
    double legLength;
public:
    Pants();
    Pants(char* ,char* ,double ,double );
    Pants(const Pants& );
    Pants& operator=(const Pants& );
    ~Pants();
};

#endif