#include"Person.h"
char* Person::allocateMemory(char* s)
{
    char* result = new char[strlen(s) + 1];
    strcpy(result, s);

    return result;
}
void Person::deleteMemory(char* s)
{
    if (s != NULL)
    {
        delete[] s;
    }
    
}
Person::Person()
{
    EGN = NULL;
    name = NULL;
}
Person::Person(char* _EGN, char* _name)
{
    EGN = allocateMemory(_EGN);
    name = allocateMemory(_name);
}
Person::Person(const Person& other)
{
    EGN = allocateMemory(other.EGN);
    name = allocateMemory(other.name);
}
Person& Person::operator=(const Person& other)
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
Person::~Person()
{
    deleteMemory(EGN);
    deleteMemory(name);
}
void Person::print()
{
    std::cout << EGN << std::endl;
    std::cout << name << std::endl;
    
}