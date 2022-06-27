#include"Employee.h"

char* Employee::allocateMemory(char* s)
{
    int size = strlen(s);
    char* result = new char[size + 1];
    strcpy(result, s);
    return result;
}
void Employee::deleteMemory(char* s)
{
    if (s != NULL)
    {
        delete[] s;
    }
}
Employee::Employee()
{
    name = NULL;
    address = NULL;
    EGN = NULL;
    department = NULL;
    salary = 0.0;
}
Employee::Employee(char* _name, char* _address, char* _EGN, char* _departament, double _salary)
{
    name = allocateMemory(_name);
    address = allocateMemory(_address);
    EGN = allocateMemory(_EGN);
    department = allocateMemory(_departament);
    salary = _salary;
}
Employee::Employee(const Employee& other)
{
    name = allocateMemory(other.name);
    address = allocateMemory(other.address);
    EGN = allocateMemory(other.EGN);
    department = allocateMemory(other.department);
    salary = other.salary;
}
Employee& Employee::operator=(const Employee& other)
{
    if (this != &other)
    {
        deleteMemory(name);
        deleteMemory(address);
        deleteMemory(EGN);
        deleteMemory(department);

        name = allocateMemory(other.name);
        address = allocateMemory(other.address);
        EGN = allocateMemory(other.EGN);
        department = allocateMemory(other.department);
        salary = other.salary;
    }
    return *this;
    
}
Employee::~Employee()
{
    deleteMemory(name);
    deleteMemory(address);
    deleteMemory(EGN);
    deleteMemory(department);
}
void Employee::print()
{
    std::cout << name << std::endl;
    std::cout << address << std::endl;
    std::cout << EGN << std::endl;
    std::cout << department << std::endl;
    std::cout << salary << std::endl;
}