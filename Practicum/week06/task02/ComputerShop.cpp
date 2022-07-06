#include <iostream>
#include<cstring>

#include "ComputerShop.h"

char* ComputerShop::allocateMemory(char* s)
{
    int len = strlen(s);
    char* result = new char[len + 1];
    strcpy(result, s);
}
ComputerShop::ComputerShop(char* _name, size_t _size , Computer* _listComputers)
{
    name = allocateMemory(_name);

    size = _size;

    for (int i = 0; i < size; i++)
    {
        listCoputer[i] = Computer(_listComputers);
    }
}
ComputerShop::~ComputerShop()
{
    if (name != NULL)
    {
        delete[] name;
    }
    if (listCoputer != NULL )
    {
        delete[] listCoputer;
    }
}
void ComputerShop::addComputer(Computer other)
{
    for (size_t i = 0; i < size; i++)
    {
        if (strcmp(listComputers[i].brand, other.brand) == 0 )
        {
            listCoputer[i].quantity++;
            return;
        }
    }
    
    Computer* newListComputers = new Computer[size + 1];
    for (int i = 0; i < size; i++)
    {
        newListCoputer[i] = listCoputer[i];
    }
    newListComputers[size++] = other;
    listCoputer = newListComputers;
}
void ComputerShop::print() const
{
    std::cout << name << std::endl;

    for (size_t i = 0; i < size; i++)
    {
        listCoputer[i].print();
    }
}
void ComputerShop::buyComputer(char* brand)
{
    for (int i = 0; i < size; i++)
    {
        if (strcmp(computers[i].brand, brand) == 0)
        {
            if (computers[i].quantity > 0)
            {
                computers[i].quantity--;
                std::cout << "Success" << std::endl;
            }
            else
            {
                std::cout << "Insufficient quantity" << std::endl;
            }

            return;
        }
    }

    std::cout << "Brand not found" << std::endl;
}