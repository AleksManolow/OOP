#ifndef __EMPLOYEE_H
#define __EMPLOYEE_H
#include<iostream>
#include<cstring>

class Employee
{
private:
    char* name;
    char* address;
    char* EGN;
    char* department;
    double salary;

public:
    char* allocateMemory(char* );
    void deleteMemory(char* );
    
    Employee();
    Employee(char* _name, char* _address, char* _EGN, char* _departament, double _salary);
    Employee(const Employee&);
    Employee& operator=(const Employee&);
    ~Employee();

    void print();
};

#endif