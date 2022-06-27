#ifndef DOCTOR_H
#define DOCTER_H
#include "Patient.h"

class Doctor
{
private:
    char* name;
    size_t numberOfPatients;
    Patient* patients;
    unsigned idN;

    char* allocateMemory(char* s);
public:
    Doctor(char*, size_t , Patient* , unsigned );
    ~Doctor();

    double avarageVisit();
    int numberOfPatientsWhoMadeMore(int visits);
    void print();

    Patient operator[](int index);
    std::ostream& operator<<(std::ostream& out);
};

#endif