#include"Student.h"
Student::Student():Person()
{
    FN = 0;
}
Student::Student(char* _name, int _FN):Person(_name)
{
    FN = _FN;
}
Student::Student(const Student& other):Person(other)
{
    FN = other.FN;
}
Student& Student::operator=(const Student& other)
{
    if (this != &other)
    {
        Person::operator=(other);
        FN = other.FN;
    }
    return *this;
}
Student::~Student()
{

}