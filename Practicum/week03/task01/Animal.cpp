#include "Animal.h"
#include<iostream>
#include<cstring>

const int MAX = 1024;
void Animal::initialize()
{
    int typeNum;
    std::cout << "Enter type: ";
    std::cin >> typeNum;

    if (typeNum < 0 || typeNum > 7)
    {
        throw "type not supported!";
    }
    mType = (Type) typeNum;
    std::cin.ignore();

    char input[MAX];
    std::cout << "Enter name: ";
    std::cin>> input;
    mName = new char [strlen(input) + 1];
    strcpy(mName, input);

    std::cout << "Enter age: ";
    std::cin >> mAge;
}
void Animal::deleteDynamic()
{
    delete[] mName;
}
void Animal::loadFromStream(std::istream& in)
{
    int typeNum;
    in >> typeNum;
    if (typeNum < 1 || typeNum > 7)
    {
        throw "Not supported type\n";
    }
    mType = (Type)typeNum;

    int sizeName;
    in >> sizeName;
    mName = new char [sizeName + 1];
    
    char name[MAX];
    in >> name;
    mName = new char[strlen(name) + 1];
    strcpy(mName, name);

    in >> mAge;

}
void Animal::writeToStream(std::ostream& out)
{
    out << (int)mType << '\n';
    out << strlen(mName) << " " << mName << '\n';
    out << mAge << '\n';
}