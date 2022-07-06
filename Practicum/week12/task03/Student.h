#ifndef __STUDENT_H
#define __STUDENT_H
#include"Person.h"
class Student:virtual public Person
{
private:
    int FN;
public:
    Student();
    Student(char* , int );
    Student(const Student& );
    Student& operator=(const Student& );
    ~Student();
    
    int getFN() {   return FN;  }
};


#endif