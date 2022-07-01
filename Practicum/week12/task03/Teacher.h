#ifndef __Teacher_H
#define __Teacher_H
#include"Person.h"
class Teacher:virtual public Person
{
private:
    double salary;
public:
    Teacher();
    Teacher(char* , double );
    Teacher(const Teacher& );
    Teacher& operator=(const Teacher& );
    ~Teacher();
    
    double getSalary() {   return salary;  }
};


#endif