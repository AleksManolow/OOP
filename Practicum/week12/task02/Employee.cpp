#include"Employee.h"
Employee::Employee():Person()
{
    position = NULL;
}
Employee::Employee(char* _EGN, char* _name , char* _posiotion):Person(_EGN, _name)
{
    position = allocateMemory(_posiotion);
}
Employee::Employee(const Employee& other):Person(other)
{
    position = allocateMemory(other.position);
}
Employee& Employee::operator=(const Employee& other)
{
    if (this != &other)
    {
        Person::operator=(other);
        deleteMemory(position);

        position = allocateMemory(other.position);
    }
    
    return *this;
}
Employee::~Employee()
{
    deleteMemory(position);
}
void Employee::print()
{
    Person::print();
    std::cout << position << std::endl;
}