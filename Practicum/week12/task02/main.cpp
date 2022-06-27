#include<iostream>
#include"People.h"
int main()
{
    char* EGN = "0123456789";
    char* name = "aleks";
    People a(EGN, name);
    a.print();
    return 0;
}