#include"Reader.h"

Reader::Reader()
{
    ID = NULL;
}
Reader::Reader(char* _EGN, char* _name, char* _ID):Person(_EGN, _name)
{
    ID = allocateMemory(_ID);
}
Reader::Reader(const Reader& other):Person(other)
{
    ID = allocateMemory(other.ID);
}
Reader& Reader::operator=(const Reader& other)
{
    if (this != &other)
    {
        Person::operator=(other);
        deleteMemory(ID);

        ID = allocateMemory(other.ID);
    }
    
    return *this;
}
Reader::~Reader()
{
    deleteMemory(ID);
}

void Reader::print()
{
    Person::print();
    std::cout << ID << std::endl;
}