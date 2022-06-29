#ifndef __CLOTHES_H
#define __CLOTHES_H
#include<iostream>
#include<cstring>
class Clothes
{
private:
    char* color;
    char* size;
    double price;
protected:
    char* allocateMemory(char* s);
    void deleteMemory(char* s);
public:
    Clothes();
    Clothes(char* ,char* ,double );
    Clothes(const Clothes& );
    Clothes& operator=(const Clothes& );
    virtual ~Clothes();

    char* getColor() const {    return color;}
    double getPrice() const {    return price;}
};

#endif