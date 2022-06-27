#include"People.h"

char* People::allocateMemory(char* s)
{
    char* result = new char[strlen(s) + 1];
    strcpy(result, s);

    return result;
}
void deleteMemory(char* s)
{
    if (s != NULL)
    {
        delete[] s;
    }
    
}
People::People()
{
    EGN = NULL;
    name = NULL;
}
People::People(char* _EGN, char* _name)
{
    EGN = allocateMemory(_EGN);
    name = allocateMemory(_name);
}
People::People(const People& other)
{
    EGN = allocateMemory(other.EGN);
    name = allocateMemory(other.name);
}
People& People::operator=(const People& other)
{
    if (this != &other)
    {
        deleteMemory(EGN);
        deleteMemory(name);

        EGN = allocateMemory(other.EGN);
        name = allocateMemory(other.name);
    }

    return *this;
}
People::~People()
{
    deleteMemory(EGN);
    deleteMemory(name);
}
void People::print()
{
    std::cout << EGN << std::endl;
    std::cout << name << std::endl;
    
}