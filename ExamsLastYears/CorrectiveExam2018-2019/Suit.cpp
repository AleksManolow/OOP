#include"Suit.h"
Suit::Suit():Clothes()
{

}
Suit::Suit(char* _color,char* _size ,double _prise):Clothes(_color, _size, _prise)
{

}
Suit::Suit(const Suit& other):Clothes(other)
{

}
Suit& Suit::operator=(const Suit& other)
{
    if (this != &other)
    {
        Clothes::operator=(other);
    }
    return *this;
}
Suit::~Suit()
{

}