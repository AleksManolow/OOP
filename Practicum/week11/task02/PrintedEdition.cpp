#include"PrintedEdition.h"
int PrintedEdition::IDCounter = 0;
char* PrintedEdition::allocateMemory(char* s)
{
    char* result = new char[strlen(s) + 1];
    strcpy(result, s);
    return result;
}
void PrintedEdition::deleteMemory(char* s)
{
    if (s != NULL)
    {
        delete[] s;
    }
}
PrintedEdition::PrintedEdition()
{
    name = NULL;
    volume = 0;
    IDCounter++;
    ID = IDCounter;
}
PrintedEdition::PrintedEdition(char* _name,int _volume):volume(_volume)
{
    name = allocateMemory(_name);
}
PrintedEdition::PrintedEdition(const PrintedEdition& other):volume(other.volume)
{
    name = allocateMemory(other.name);
}
PrintedEdition& PrintedEdition::operator=(const PrintedEdition& other)
{
    if (this != &other)
    {
        deleteMemory(name);

        name = allocateMemory(other.name);
        volume = other.volume;
        ID = other.ID;
    }

    return *this;
}
PrintedEdition::~PrintedEdition()
{
    deleteMemory(name);
}
std::ostream& operator<<(std::ostream& os, const PrintedEdition& printedEdition)
{
    os << "----- PRINTED EDITION -----" << '\n';
	os << "Id: " << printedEdition.ID << '\n';
	os << "Edition's name: " << printedEdition.name << '\n';
	os << "Number of pages: " << printedEdition.volume << '\n';
    os << "----- -------------- -----" << '\n';
    return os;
}