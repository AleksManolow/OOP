#include "Building.h"

char* Building::allocateMemory(char* s)
{
    int size = strlen(s);
    char* result = new char[size + 1];
    strcpy(result, s);
    return result;
}
void Building::deleteMemory(char* s)
{
    if (s != NULL)
    {
        delete[] s;
    }
}
Building::Building()
{
    height = 0;
    area = 0;
    address = NULL;
}
Building::Building(double _height, double _area, char* _address)
{
    height = _height;
    area = _area;
    address = allocateMemory(_address);
}
Building::Building(const Building& other)
{
    height = other.height;
    area = other.area;
    address = allocateMemory(other.address);
}
Building& Building::operator=(const Building& other)
{
    if (this != &other)
    {
        deleteMemory(address);

        height = other.height;
        area = other.area;
        address = allocateMemory(other.address);
        
    }
    return *this;
}
Building::~Building()
{
    deleteMemory(address);
}
void Building::loadFromStream(std::istream& is)
{
    std::cout << "Enter height: ";
    is >> height ;
    std::cout << "Enter area: ";
    is >> area;
    is.ignore();
    std::cout << "Enter address: ";
    char input[1024];
    is >> input;
    address = allocateMemory(input);
}
void Building::writeToStream(std::ostream& os)
{
    std::cout << "Height: ";
    os << height << '\n';
    std::cout << "Area: ";
    os << area << '\n';
    std::cout << "Address: ";
    os << address << '\n';
}