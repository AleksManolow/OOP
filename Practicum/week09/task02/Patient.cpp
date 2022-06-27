#include "Patient.h"

char* Patient::allocateMemory(char* s)
{   
    int len = strlen(s);
    char* result = new char[len + 1];
    strcpy(result, s);
    return result;
}

void Patient::deleteMemory(char* s)
{
    if (s != NULL)
    {
        delete[] s;
    }
}

Patient::Patient()
{
    name = NULL;
    data = NULL;
    numberOfVisits = 0;
}

Patient::Patient(char* _name, char* _data , unsigned _numberOfVisits)
{
    name = allocateMemory(_name);
    data = allocateMemory(_data);
    numberOfVisits = _numberOfVisits;
}

Patient::Patient(const Patient& other)
{
    name = allocateMemory(other.name);
    data = allocateMemory(other.data);
    numberOfVisits = other.numberOfVisits;
}

Patient& Patient::operator=(const Patient& other)
{
    if (this != &other)
    {
        deleteMemory(name);
        deleteMemory(data);

        name = allocateMemory(other.name);
        data = allocateMemory(other.data);
        numberOfVisits = other.numberOfVisits;
    }
    return *this;
}

Patient::~Patient()
{
    deleteMemory(name);
    deleteMemory(data);
}

unsigned Patient::getNumberOfVisits()
{
    return numberOfVisits;
}
std::ostream& Patient::operator<<(std::ostream& out)
{
    out << strlen(name) << ' ' << name << '\n';
    out << data << '\n';
    out << numberOfVisits << '\n';

    return out;
}
void Patient::print()
{
    std::cout << "Name: ";
    std::cout << name << std::endl;
    
    std::cout << "Data: ";
    std::cout << data << std::endl;
    
    std::cout << "Number Of Visits: ";
    std::cout << numberOfVisits << std::endl;
}