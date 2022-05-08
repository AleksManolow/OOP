#ifndef BOOK_H
#define BOOK_H
#include<iostream>
#include"String.h"

class Book
{
private:
    String author;
    String title;
    String nameFale;
    String shortDescription;
    double rating;
    String ISBN;
public:
    Book();
    Book(String , String, String , String , double , String );
    Book(const Book& );
    Book& operator=(const Book& );

    String getAuthor() const;
    String getTitle() const;
    String getNameFile() const;
    String getShortDescripion() const;
    double getRating() const;
    String getISBN() const;

    void loadFromStream(std::istream& is);
    void writeToStream(std::ostream& os);
    bool operator==(const Book&) const;

    friend std::istream& operator>>(std::istream& is, Book&);
    friend std::ostream& operator<<(std::ostream& os, const Book&);
    
};

#endif