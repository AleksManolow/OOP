#include "Book.h"
const int N = 1024;
Book::Book()
{
    rating = 0;
}
Book::Book(String _author, String _title, String _nameFale, String _shortDescription, double _rating, String _ISBN)
{
    author = _author;
    title = _title;
    nameFale = _nameFale;
    shortDescription = _shortDescription;
    rating = _rating;
    ISBN = _ISBN;
}
Book::Book(const Book& other)
{
    author = other.author;
    title = other.title;
    nameFale = other.nameFale;
    shortDescription = other.shortDescription;
    rating = other.rating;
    ISBN = other.ISBN;
}
Book& Book::operator=(const Book& other)
{
    if (this != &other)
    {
        author = other.author;
        title = other.title;
        nameFale = other.nameFale;
        shortDescription = other.shortDescription;
        rating = other.rating;
        ISBN = other.ISBN;
    }
    return *this;
}
String Book::getAuthor() const
{
    return author;
}
String Book::getTitle() const
{
    return title;
}
String Book::getNameFile() const
{
    return nameFale;
}
String Book::getShortDescripion() const
{
    return shortDescription;
}
double Book::getRating() const
{
    return rating;
}
String Book::getISBN() const
{
    return ISBN;
}
bool Book::operator==(const Book& other) const
{
    if (author == other.author && title == other.title && nameFale == other.nameFale && 
    shortDescription == other.shortDescription && rating == other.rating && 
    ISBN == other.ISBN)
    {
        return true;
    }
    return false;
}
void Book::print()
{
    std::cout << author << std::endl;
    std::cout << title << std::endl;
    std::cout << nameFale << std::endl;
    std::cout << shortDescription << std::endl;
    std::cout << rating << std::endl;
    std::cout << ISBN << std::endl;
}
std::istream& operator>>(std::istream& is, Book& book)
{
    is >> book.author;
    is >> book.title;
    is >> book.nameFale;
    is >> book.shortDescription;
    is >> book.rating;
    is.ignore();
    is >> book.ISBN;

    return is;
}
std::ostream& operator<<(std::ostream& os, const Book& book)
{
    os << book.author << '\n';
    os << book.title << '\n';
    os << book.nameFale << '\n';
    os << book.shortDescription << '\n';
    os << book.rating << '\n';
    os << book.ISBN << '\n';
    return os;
}

