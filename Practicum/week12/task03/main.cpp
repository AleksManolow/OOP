#include<iostream>
#include"Assistant.h"
int main()
{
    Assistant a("Gosho",78451,250.40);
    std::cout << a.getName() << std::endl;
    std::cout << a.getFN() << std::endl;
    std::cout << a.getSalary() << std::endl;

    return 0;
}