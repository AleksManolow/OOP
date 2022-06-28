#include<iostream>
#include"Reader.h"
int main()
{
    char* EGN = "0123456789";
    char* name = "aleks";
    char* ID = "41651465165";
    Reader a(EGN, name, ID);
    a.print();
    
    return 0;
}