#include"Clothes.h"
char* Clothes::allocateMemory(char* s)
{
    char* result = new char[strlen(s) + 1];
    strcpy(result, s);
    return result;
}
void Clothes::deleteMemory(char* s)
{
    if (s != NULL)
    {
        delete[] s;
    }
}
Clothes::Clothes()
{
    color = NULL;
    size = NULL;
    price = 0;
}
Clothes::Clothes(char* _color, char* _size, double _price):price(_price)
{
    color = allocateMemory(_color);
    size = allocateMemory(_size);
}
Clothes::Clothes(const Clothes& other):price(other.price)
{
    color = allocateMemory(other.color);
    size = allocateMemory(other.size);
}
Clothes& Clothes::operator=(const Clothes& other)
{
    if (this != &other)
    {
        deleteMemory(color);
        deleteMemory(size);

        color = allocateMemory(other.color);
        size = allocateMemory(other.size);
        price = other.price;
    }
    return *this;
}
Clothes::~Clothes()
{
    deleteMemory(color);
    deleteMemory(size);
}
