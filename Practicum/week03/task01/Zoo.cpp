#include"Zoo.h"
#include<iostream>
#include<cstring>

const size_t MAX = 1024;
void Zoo::initialize()
{
    char input[MAX];
    std::cout << "Enter name zoo: ";
    std::cin >> input;
    mName = new char [strlen(input) + 1];
    strcpy(mName, input);

    std::cout << "Enter animals size: ";
    std::cin >> mCount;
    mCapacity = mCount;
    mAnimals = new Animal [mCount];
    try
    {
        for (int i = 0; i < mCount; i++)
        {
            mAnimals[i].initialize();
        }
    }
    catch(const char* e)
    {
        throw "Couldn't initialize animal!\n";
    }
}
void Zoo::deleteDynamic()
{
    delete[] mName;

    for (int i = 0; i < mCount; i++)
    {
        mAnimals[i].deleteDynamic();
    }
    delete[] mAnimals;
}
void Zoo::loadFromStream(std::istream& in)
{
    int nameSize;
    in >> nameSize;
    mName = new char [nameSize + 1];
    char input[MAX];
    in >> input;
    strcpy(mName, input);


    in >> mCapacity >>mCount;
    mAnimals = new Animal[mCapacity];
    try
    {
        for(int i = 0; i < this->mCount; i++)
        {
            this->mAnimals[i].loadFromStream(in);
        }
    }
    catch(const char* e)
    {
        throw "Couldn't load animal from stream!\n";
    }
}
void Zoo::writeToStream(std::ostream& out)
{
    out << strlen(mName) << " " << mName << std::endl;
    out << mCapacity << ' ' <<mCount << std::endl;
    for (int i = 0; i < mCount; i++)
    {
        mAnimals[i].writeToStream(out);
    }
}
bool Zoo::hasType(Type type)
{
    for (int i = 0; i < mCount; i++)
    {
        if (mAnimals[i].mType == type)
        {
            return true;
        }
    }
    return false;
}