#ifndef BOOK_H
#define BOOK_H
#include<iostream>
#include<cstring>
class Book
{
private:
    char* author;
    char* title;
    char* nameFale;
    char* shortDescription;
    double rating;
    char* ISBN;

    char* allocateMemory(char* s);
    void deleteMemory(char* s);
public:
    Book();
    Book(char* , char*, char* , char* , double , char* );
    Book(const Book& );
    Book& operator=(const Book& );
    ~Book();

    
    void setAuthor(char* );
    void setTitle(char* );
    void setNameFile(char* );
    void setShortDescripion(char* );
    void setRating(double );
    void setISBN(char* );

    char* getAuthor() const;
    char* getTitle() const;
    char* getNameFile() const;
    char* getShortDescripion() const;
    double getRating() const;
    char* getISBN() const;

    void print();
    friend std::istream& operator>>(std::istream& is, Book&);

};
std::ostream& operator<<(std::ostream& os, Book const&);

#endif