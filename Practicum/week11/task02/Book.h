#ifndef __BOOK_H
#define __BOOK_H
#include"PrintedEdition.h"
class Book:public PrintedEdition
{
private:
    char* author;
public:
    Book();
    Book(char* _name, int _volume, char* _author);
    Book(const Book& );
    Book& operator=(const Book& );
    ~Book();

    friend std::ostream& operator<<(std::ostream& os, const Book& printedEdition);
};


#endif