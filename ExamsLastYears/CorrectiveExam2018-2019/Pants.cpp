#include"Pants.h"
Pants::Pants():Clothes()
{
    legLength = 0;
}
Pants::Pants(char* _color,char* _size ,double _prise ,double _legLength):Clothes(_color, _size, _prise),legLength(_legLength)
{

}
Pants::Pants(const Pants& other):Clothes(other),legLength(other.legLength)
{

}
Pants& Pants::operator=(const Pants& other)
{
    if (this != &other)
    {
        Clothes::operator=(other);
        legLength = other.legLength;
    }
    return *this;
}
Pants::~Pants()
{

}