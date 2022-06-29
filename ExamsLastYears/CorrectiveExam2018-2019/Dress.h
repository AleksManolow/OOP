#ifndef __DRESS_H
#define __DRESS_H
#include"Clothes.h"

class Dress:public Clothes
{
private:
    double skirtLength;
public:
    Dress();
    Dress(char* ,char* ,double ,double );
    Dress(const Dress& );
    Dress& operator=(const Dress& );
    ~Dress();
};

#endif