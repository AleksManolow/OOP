#include"Developer.h"
#include <fstream>
#include <cstring>
#define INPUT_SIZE 1024
void Developer::initialize()
{
    mId = rand() % 9000 + 1000;

    char inputF[INPUT_SIZE];
    std::cin >> inputF;
    mFirstName = new char[strlen(inputF) + 1];
    strcpy(mFirstName, inputF);

    char inputL[INPUT_SIZE];
    std::cin >> inputL;
    mLastName = new char[strlen(inputL) + 1];
    strcpy(mLastName, inputL);

    int typeNum;
    std::cin >> typeNum;
    if(typeNum < 1 || typeNum > 5)
    {
        throw "Not supported type\n";
    }
    mPosition = (Position) typeNum;
}
void Developer::deleteDynamic()
{
    delete[] mFirstName;
    delete[] mLastName;
}
void Developer::loadFromStream(std::ifstream& in)
{
    in >> mId;

    int len;
    in >> len;
    mFirstName = new char[len + 1];
    in >> mFirstName;

    in >> len;
    mLastName = new char[len + 1];
    in >> mLastName;

    int position;
    in >> position;
    mPosition = (Position) position;
}
void Developer::writeToStream(std::ostream& out)
{
    out << mId << '\n';
    out << strlen(mFirstName) << ' ' << mFirstName << '\n';
    out << strlen(mLastName) << ' ' << mLastName << '\n';
    out << mPosition << '\n';
}
void Developer::print()
{
    std::cout << "------------- Developer -------------\n";

    writeToStream(std::cout);

    std::cout << "-------------------------------------\n";
}