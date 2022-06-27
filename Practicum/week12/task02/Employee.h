#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include"Person.h"
class Employee:public Person
{
private:
    char* position;

public:
    Employee();
    Employee(char* , char* , char* );
    Employee(const Employee& );
    Employee& operator=(const Employee& );
    ~Employee();

    void print();
};


#endif