#include"Vehicle.h"
char* Vehicle::allocateMemory(char* s)
{
    char* result = new char[strlen(s) + 1];
    strcpy(result, s);
    return result;
}
void Vehicle::deleteMemory(char* s)
{
    if (s != NULL)
    {
        delete[] s;
    }
}
Vehicle::Vehicle()
{
    brand = NULL;
    maxSpeed = 0;
}
Vehicle::Vehicle(char* _brand, int _maxSpeed)
{
    brand = allocateMemory(_brand);
    maxSpeed = _maxSpeed;
}
Vehicle::Vehicle(const Vehicle& other)
{
    brand = allocateMemory(other.brand);
    maxSpeed = other.maxSpeed;
}
Vehicle& Vehicle::operator=(const Vehicle& other)
{
    if (this != &other)
    {
        deleteMemory(brand);

        brand = allocateMemory(other.brand);
        maxSpeed = other.maxSpeed;
    }
    return *this;
}
Vehicle::~Vehicle()
{
    deleteMemory(brand);
}