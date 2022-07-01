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
    name = NULL;
}
Person::Person(char* _name)
{
    name = allocateMemory(_name);
}
Person::Person(const Person& other)
{
    name = allocateMemory(other.name);
}
Person& Person::operator=(const Person& other)
{
    if (this != &other)
    {
        deleteMemory(name);

        name = allocateMemory(other.name);
    }
    return *this;   
}
Person::~Person()
{
    deleteMemory(name);
}