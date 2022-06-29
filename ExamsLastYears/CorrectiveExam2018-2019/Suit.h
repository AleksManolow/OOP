#ifndef __Suit_H
#define __Suit_H
#include"Clothes.h"

class Suit:public Clothes
{
public:
    Suit();
    Suit(char* ,char* ,double );
    Suit(const Suit& );
    Suit& operator=(const Suit& );
    ~Suit();
};

#endif