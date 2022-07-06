#include "Dictionary.h"
#include<cstring>

void Dictionary::init(Record* data, int size)
{
    mSize = size;
    for (int i = 0; i < mSize; i++)
    {
        mData[i] = data[i];
    }
}
void Dictionary::print() const
{
    for (int i = 0; i < mSize; i++)
    {
        mData[i].print();
    }
}
void Dictionary::add(const Record& newPair)
{
    mData[mSize++] = newPair;
}
void Dictionary::remove(const char* word)
{
    for (int i = 0; i < mSize; i++)
    {
        if(mData[i].mWord == word)
        {
            for (int j = i; j < mSize - 1; j++)
            {
                mData[j] = mData[j + 1];
            }
            mSize--;
            break;
        }
    }
}
char* Dictionary::findMeaning(const char* word)
{   
    int index = 0;
    for (int i = 0; i < mSize; i++)
    {
        if(mData[i].mWord == word)
        {
            index = i;
        }
    }
    return mData[index].mMeaning;
}
char* Dictionary::getByIndex(int index)
{   
    return mData[index].mMeaning;
}
void Dictionary::sort()
{
    for (int i = 0; i < mSize; i++)
    {
        for (int j = i; j < mSize; j++)
        {
            if(strcmp(mData[i].mWord, mData[j].mWord) > 0)
            {
                Record temp = mData[i];
                mData[i] = mData[j];
                mData[j] = temp;
            }
        }
    }
}
void Dictionary::deleteDynamic()
{
    for (int i = 0; i < mSize; i++)
    {
        mData[i].deleteDynamic();
    }
    
}
    