#include<iostream>
#include"Person.h"
int main()
{
    char* EGN = "0123456789";
    char* name = "aleks";
    Person a(EGN, name);
    a.print();
    return 0;
}