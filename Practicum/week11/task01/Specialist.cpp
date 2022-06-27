#include"Specialist.h"

Specialist::Specialist():Employee()
{
    specialty = NULL;
}
Specialist::Specialist(char* _name, char* _address, char* _EGN, char* _departament, double _salary, char* _specialty)
                    :Employee(_name, _address, _EGN, _departament, _salary)
{
    specialty = allocateMemory(_specialty);
}
Specialist::Specialist(const Specialist& other):Employee(other)
{
    specialty = allocateMemory(other.specialty);
}
Specialist& Specialist::operator=(const Specialist& other)
{
    if (this != &other)
    {
        Employee::operator=(other);
        deleteMemory(other.specialty);

        specialty = allocateMemory(other.specialty);
    }
    return *this;
}
Specialist::~Specialist()
{
    deleteMemory(specialty);
}
void Specialist::print()
{
    Employee::print();
    std::cout << specialty << std::endl;
}