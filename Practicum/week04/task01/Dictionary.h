#ifndef DICTIONARY_H
#define DICTIONARY_H

#include"Record.h"
#define MAX_CAPACITY 500

class Dictionary
{
private:
    Record mData[MAX_CAPACITY];
    int mSize;

public:
    
    void init(Record*, int);
    void print() const;
    void add(const Record&);
    void remove(const char*);
    char* findMeaning(const char*);
    char* getByIndex(int index);
    void sort();
    void deleteDynamic();

};

#endif