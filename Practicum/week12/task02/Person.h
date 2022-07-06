#ifndef PERSON_H
#define PERSON_H
#include<iostream>
#include<cstring>
class Person
{
private:
    char* EGN;
    char* name;

protected:
    char* allocateMemory(char* s);
    void deleteMemory(char* s);
public:
    Person();
    Person(char* , char* );
    Person(const Person& );
    Person& operator=(const Person& );
    ~Person();

    void print();
};

#endif