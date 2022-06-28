#ifndef __PRINTEDEDITION_H
#define __PRINTEDEDITION_H
#include<iostream>
#include<cstring>
class PrintedEdition
{
protected:
    char* name;
    int volume;
    int ID;
    static int IDCounter; 
    char* allocateMemory(char* s);
    void deleteMemory(char* s);
public:
    PrintedEdition();
    PrintedEdition(char* ,int );
    PrintedEdition(const PrintedEdition& );
    PrintedEdition& operator=(const PrintedEdition& );
    ~PrintedEdition();

    friend std::ostream& operator<<(std::ostream& os, const PrintedEdition& printedEdition);

};


#endif