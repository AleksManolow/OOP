#include"Book.h"
Book::Book():PrintedEdition()
{
    author = NULL;
}
Book::Book(char* _name, int _volume, char* _author):PrintedEdition(_name, _volume)
{
    author = allocateMemory(_author);
}
Book::Book(const Book& other):PrintedEdition(other)
{
        author = allocateMemory(other.author);
}
Book& Book::operator=(const Book& other)
{
    if (this != &other)
    {
        PrintedEdition::operator=(other);
        deleteMemory(author);

        author = allocateMemory(other.author);
    }
    
    return *this;
}
Book::~Book()
{
    deleteMemory(author);
}
std::ostream& operator<<(std::ostream& os, const Book& printedEdition)
{
    os << "---------- BOOK ----------" << '\n';
	os << "Id: " << printedEdition.ID << '\n';
	os << "Edition's name: " << printedEdition.name << '\n';
	os << "Number of pages: " << printedEdition.volume << '\n';
	os << "Author's name: " << printedEdition.author << '\n';
	os << "--------------------------" << '\n';
	return os;

    return os;
}