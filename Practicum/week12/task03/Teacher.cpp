#include"Teacher.h"
Teacher::Teacher():Person()
{
    salary = 0;
}
Teacher::Teacher(char* _name, double _salary):Person(_name)
{
    salary = _salary;
}
Teacher::Teacher(const Teacher& other):Person(other)
{
    salary = other.salary;
}
Teacher& Teacher::operator=(const Teacher& other)
{
    if (this != &other)
    {
        Person::operator=(other);
        salary = other.salary;
    }
    return *this;
}
Teacher::~Teacher()
{

}