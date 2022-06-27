#ifndef PATIENT_H
#define PATIENT_H
#include<iostream>
#include<cstring>

class Patient
{
private:
    char* name;
    char* data;
    unsigned numberOfVisits;

    char* allocateMemory(char* );
    void deleteMemory(char* );
public:
    Patient();
    Patient(char* , char* , unsigned _numberOfVisits = 0);
    Patient(const Patient& );
    Patient& operator=(const Patient& );
    ~Patient();

    unsigned getNumberOfVisits();

    std::ostream& operator<<(std::ostream& );

    void print();
};

#endif