#ifndef __MANAGER_H
#define __MANAGER_H
#include"Specialist.h"

class Manager:public Specialist
{
private:
    char* departamentInfo;
    size_t size;
    Employee** employees;
    
public:
    Manager();
    Manager(char* _name, char* _address, char* _EGN, char* _departament, double _salary, char* _specialty, 
        char* _departamentInfo, size_t _size, Employee** _employees);
    Manager(const Manager&);
    Manager operator=(const Manager&);
    ~Manager();
};


#endif