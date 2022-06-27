#ifndef COMPUTERSHOP_H
#define COMPUTERSHOP_H
#include "Computer.h"

class ComputerShop
{
private:
    char* name;
    size_t size;
    Computer* listCoputer;

    char* allocateMemory(char* s)
public:
    ComputerShop(char* , size_t , Computer* );
    ~ComputerShop();
    void addComputer(Computer );
    void print() const;
    void buyComputer(char* brand);
};

#endif