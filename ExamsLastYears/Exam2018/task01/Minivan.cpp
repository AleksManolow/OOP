#include"Minivan.h"

Minivan::Minivan():Vehicle()
{

}
Minivan::Minivan(char* _brand):Vehicle(_brand, 160)
{

}
Minivan::Minivan(const Minivan& other):Vehicle(other)
{

}
Minivan& Minivan::operator=(const Minivan& other)
{
    if (this != &other)
    {
        Vehicle::operator=(other);
    }
    return *this;
}

