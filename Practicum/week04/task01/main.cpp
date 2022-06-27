#include<iostream>
#include"Dictionary.h"
int main()
{
    Record rec1, rec2, rec3;
    rec1.init("computer", "Similar to air conditioners. Works fine until you open up windows.");
    rec2.init("programmer", "A person who is paid to professionally scream at a computer.");
    rec3.init("cofveve", "It literally means covfefe.");
    Record records[] = {rec1, rec2, rec3};
    Dictionary dict;

    dict.init(records, 3);

    dict.sort();

    dict.print();
    
    dict.deleteDynamic();

    return 0;
}