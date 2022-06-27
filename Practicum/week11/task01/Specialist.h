#ifndef __SPECIALIST_H
#define __SPECIALIST_H
#include"Employee.h"
class Specialist:public Employee
{
private:
    char* specialty;
public:
    Specialist();
    Specialist(char* _name, char* _address, char* _EGN, char* _departament, double _salary, char* _specialty);
    Specialist(const Specialist&);
    Specialist& operator=(const Specialist& );
    ~Specialist();

    void print();
};

#endif