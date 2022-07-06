#include "Computer.h"
#include <cstring>
#include <iostream>

char* Computer::allocateMemory(char* s)
{
    int len = strlen(s);
    char* result = new char[len + 1];
    strcpy(result, s);
}
void Computer::deleteMemory(char* s)
{
    delete[] s;
}
Computer::Computer()
{
    brand = new char[20];
    processor = new char[20];
    video = new char[20];
    hardDrive = new char[20];
}
Computer::Computer(char* _brand, char* _processor, char* _video, char* _hardDrive, double _price, unsigned _quantity)
{
    brand = allocateMemory(_brand);
    processor = allocateMemory(_processor);
    video = allocateMemory(_video);
    hardDrive = allocateMemory(_hardDrive);
    price = _price;
    quantity = _quantity;
}
Computer::Computer(const Computer& other)
{
    brand = allocateMemory(other.brand);
    processor = allocateMemory(other.processor);
    video = allocateMemory(other.video);
    hardDrive = allocateMemory(other.hardDrive);
    price = other.price;
    quantity = other.quantity;
}
Computer& Computer::operator=(Computer const &otherComputer)
{
    if(this != &otherComputer)
    {
        delete[] brand;
        delete[] processor;
        delete[] video;
        delete[] hardDrive;

        brand = allocateMemory(otherComputer.brand);
        processor = allocateMemory(otherComputer.processor);
        video = allocateMemory(otherComputer.video);
        hardDrive = allocateMemory(otherComputer.hardDrive);
        price = otherComputer.price;
        quantity = otherComputer.quantity;
    }
    return *this;
}
Computer::~Computer()
{
    deleteMemory(brand);
    deleteMemory(processor);
    deleteMemory(video);
    deleteMemory(hardDrive);
}
void Computer::print() const
{
    std::cout << brand << std::endl;
    std::cout << processor << std::endl;
    std::cout << video << std::endl;
    std::cout << hardDrive << std::endl;
    std::cout << price << std::endl;
    std::cout << quantity << std::endl;
}
void Computer::create()
{
    std::cout << "Enter brand: ";
    std::cin >> brand;

    std::cout << "Enter processor: ";
    std::cin >> processor;

    std::cout << "Enter video: ";
    std::cin >> video;

    std::cout << "Enter hardDrive: ";
    std::cin >> hardDrive;

    std::cout << "Enter price: ";
    std::cin >> price;

    std::cout << "Enter quantity: ";
    std::cin >> quantity;
}