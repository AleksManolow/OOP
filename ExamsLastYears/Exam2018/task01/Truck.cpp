#include"Truck.h"

Truck::Truck():Vehicle()
{

}
Truck::Truck(char* _brand):Vehicle(_brand, 140)
{

}
Truck::Truck(const Truck& other):Vehicle(other)
{

}
Truck& Truck::operator=(const Truck& other)
{
    if (this != &other)
    {
        Vehicle::operator=(other);
    }
    return *this;
}

