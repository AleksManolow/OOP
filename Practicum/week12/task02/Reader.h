#ifndef __READER_H
#define __READER_H
#include"Person.h"
class Reader:public Person
{
private:
    char* ID;
public:
    Reader();
    Reader(char* ,char* ,char* );
    Reader(const Reader& );
    Reader& operator=(const Reader& );
    ~Reader();

    void print();
};




#endif