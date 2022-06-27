#include"House.h"

House::House():Building()
{
    floor = 0;
    ownerName =NULL;
}
House::House(double _height, double _area, char* _address, int _floor, char* _ownerName):Building(_height, _area, _address)
{
    floor = _floor;
    ownerName = allocateMemory(_ownerName);
}
House::House(const House& other):Building(other)
{
    floor = other.floor;
    ownerName = allocateMemory(other.ownerName);
}
House& House::operator=(const House& other)
{
    if (this != &other)
    {
        Building::operator=(other);
        deleteMemory(other.ownerName);

        floor = other.floor;
        ownerName = allocateMemory(other.ownerName);
    }
    
    return *this;
}
House::~House()
{
    deleteMemory(ownerName);
}
double House::averageFloorHeight()
{
    return Building::getHeight() / (double)floor; 
}
void House::loadFromStream(std::istream& is)
{
    Building::loadFromStream(is);
    std::cout << "Enter floor: ";
    is >> floor;
    is.ignore();
    std::cout << "Enter owner name: ";
    char input[1024];
    is >> input;
    ownerName = allocateMemory(input);
}
void House::writeToStream(std::ostream& os)
{
    Building::writeToStream(os);
    std::cout << "Floor: ";
    os << floor << '\n';
    std::cout << "Owner name: ";
    os << ownerName << '\n';
}