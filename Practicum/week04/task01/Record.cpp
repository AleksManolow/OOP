#include<iostream>
#include<cstring>
#include"Record.h"

void Record::init(const char* word, const char* meaning)
{
    mWord = new char [strlen(word) + 1];
    strcpy(mWord, word);
    
    mMeaning = new char [strlen(meaning) + 1];
    strcpy(mMeaning, meaning);
}
Record Record::copy() const
{
    char* wordCopy  = new char [strlen(mWord) + 1];
    strcpy(wordCopy, mWord);

    char* meaningCopy = new char [strlen(mMeaning) + 1];
    strcpy(meaningCopy, mMeaning );

    return {wordCopy, meaningCopy};
}
void Record::print() const
{
    std::cout << mWord << " - " << mMeaning << '\n';
}
void Record::deleteDynamic()
{
    delete[] mWord;
    delete[] mMeaning;
}