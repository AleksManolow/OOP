#include"Suitcase.h"
char* Suitcase::allocateMemory(char* s)
{
    char* result = new char[strlen(s) + 1];
    strcpy(result, s);
    return result;
}
void Suitcase::deleteMemory(char* s)
{
    if (s != NULL)
    {
        delete[] s;
    }
}
Suitcase::Suitcase()
{
    color = NULL;
    name = NULL;
    address = NULL;
    phoneNumber = 0;

    capacity = 10;

}
Suitcase::Suitcase(char* _color,char* _name ,char* _address , unsigned _phoneNumber, std::list<Clothes*> _listOfClothes)
{
    color = allocateMemory(_color);
    name = allocateMemory(_name);
    address = allocateMemory(_address);
    phoneNumber = _phoneNumber;
    capacity = 10;
    for (Clothes* item : _listOfClothes)
    {
        listOfClothes.push_back(item);
    }
}
Suitcase::Suitcase(const Suitcase& other)
{
    color = allocateMemory(other.color);
    name = allocateMemory(other.name);
    address = allocateMemory(other.address);
    phoneNumber = other.phoneNumber;
    capacity = other.capacity;
    for (Clothes* item : other.listOfClothes)
    {
        listOfClothes.push_back(item);
    }
}
Suitcase& Suitcase::operator=(const Suitcase& other)
{
    if (this != &other)
    {
        deleteMemory(color);
        deleteMemory(name);
        deleteMemory(address);
        for (Clothes* item : listOfClothes)
        {
            delete item;
        }

        color = allocateMemory(other.color);
        name = allocateMemory(other.name);
        address = allocateMemory(other.address);
        phoneNumber = other.phoneNumber;
        capacity = other.capacity;
        for (Clothes* item : other.listOfClothes)
        {
            listOfClothes.push_back(item);
        }
    }
    return *this;
}
Suitcase::~Suitcase()
{
    deleteMemory(color);
    deleteMemory(name);
    deleteMemory(address);
    for (Clothes* item : listOfClothes)
    {
        delete item;
    }
}
bool Suitcase::isThereRoomForGarment()
{
    if (listOfClothes.size() + 1 < capacity)
    {
        return true;
    }
    return false;
}
void Suitcase::add(Clothes* clothes)
{
    if (isThereRoomForGarment())
    {
        listOfClothes.push_back(clothes);
    }
}
void Suitcase::remove(int index)
{
    int i = 0;
    for (auto item : listOfClothes)
    {
        
        if (i == index)
        {
            listOfClothes.remove(item);
        }
        i++;
    }
}