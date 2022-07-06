#include"Manager.h"

Manager::Manager():Specialist()
{
    departamentInfo = NULL;
    size = 0;
    employees = NULL;
}
Manager::Manager(char* _name, char* _address, char* _EGN, char* _departament, double _salary, char* _specialty, 
    char* _departamentInfo, size_t _size, Employee** _employees):Specialist(_name, _address, _EGN, _departament, _salary, _specialty)
{
    departamentInfo = allocateMemory(_departamentInfo);
    size = _size;
    employees = new Employee*[size];
    for (int i = 0; i < size; i++)
    {
        employees[i] = new Employee();
        employees[i] = _employees[i];
    }
}
Manager::Manager(const Manager& other):Specialist(other)
{
    departamentInfo = allocateMemory(other.departamentInfo);
    employees = new Employee*[other.size];
    for (int i = 0; i < size; i++)
    {
        employees[i] = new Employee();
        employees[i] = other.employees[i];
    }
}
Manager Manager::operator=(const Manager& other)
{
    if (this != &other)
    {
        Specialist::operator=(other);
        deleteMemory(other.departamentInfo);
        for (int i = 0; i < size; i++)
        {
            delete employees[i];
        }
        delete[] employees;

        departamentInfo = allocateMemory(other.departamentInfo);
        employees = new Employee*[other.size];
        for (int i = 0; i < size; i++)
        {
            employees[i] = new Employee();
            employees[i] = other.employees[i];
        }
    }
    return *this;
}
Manager::~Manager()
{
    deleteMemory(departamentInfo);
    if (employees != NULL)
    {
        for (int i = 0; i < size; i++)
        {
            delete employees[i];
        }
        delete[] employees;
        
    }
}