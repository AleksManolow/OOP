#include"Dress.h"
Dress::Dress():Clothes()
{
    skirtLength = 0;
}
Dress::Dress(char* _color,char* _size ,double _prise ,double _skirtLength):Clothes(_color, _size, _prise),skirtLength(_skirtLength)
{

}
Dress::Dress(const Dress& other):Clothes(other),skirtLength(other.skirtLength)
{

}
Dress& Dress::operator=(const Dress& other)
{
    if (this != &other)
    {
        Clothes::operator=(other);
        skirtLength = other.skirtLength;
    }
    return *this;
}
Dress::~Dress()
{

}