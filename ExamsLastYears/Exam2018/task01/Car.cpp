#include"Car.h"

Car::Car():Vehicle()
{

}
Car::Car(char* _brand):Vehicle(_brand, 240)
{

}
Car::Car(const Car& other):Vehicle(other)
{

}
Car& Car::operator=(const Car& other)
{
    if (this != &other)
    {
        Vehicle::operator=(other);
    }
    return *this;
}

