#include"Newspaper.h"
Newspaper::Newspaper():PrintedEdition()
{
    edNum = 0;
}
Newspaper::Newspaper(char* _name, int _volume, int _edNum):PrintedEdition(_name, _volume), edNum(_edNum)
{

}
Newspaper::Newspaper(const Newspaper& other):PrintedEdition(other.name, other.volume), edNum(other.edNum)
{
    
}
Newspaper& Newspaper::operator=(const Newspaper& other)
{
    if (this != &other)
    {
        PrintedEdition::operator=(other);
        edNum = other.edNum;
    }
    return *this; 
}
Newspaper::~Newspaper()
{

}
std::ostream& operator<<(std::ostream& os, const Newspaper& printedEdition)
{
	os << "------- NEWSPAPER --------" << '\n';
	os << "Id: " << printedEdition.ID << '\n';
	os << "Edition's name: " << printedEdition.name << '\n';
	os << "Number of pages: " << printedEdition.volume << '\n';
	os << "Edition's number: " << printedEdition.edNum << '\n';
	os << "--------------------------" << '\n';
	return os;
}