#include"Assistant.h"
Assistant::Assistant():Person(),Student(), Teacher()
{

}
Assistant::Assistant(char* _name, int _FN, double _salary)
:Person(_name), 
Student(_name, _FN), 
Teacher(_name, _salary)
{

}
Assistant::Assistant(const Assistant& other)
:Person(other),
Student(other), 
Teacher(other)
{

}
Assistant& Assistant::operator=(const Assistant& other)
{
    if (this != &other)
    {
        Person::operator=(other);
        Student::operator=(other);
        Teacher::operator=(other);
    }
    return *this;
}
Assistant::~Assistant()
{

}