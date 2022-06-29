#ifndef __SUITCASE_H
#define __SUITCASE_H
#include<list>
#include"Clothes.h"
class Suitcase
{
private:
    char* color;
    char* name;
    char* address;
    unsigned phoneNumber;

    size_t capacity;
    std::list<Clothes*> listOfClothes;

    char* allocateMemory(char* s);
    void deleteMemory(char* s);
public:
    Suitcase();
    Suitcase(char* ,char* ,char* , unsigned , std::list<Clothes*> );
    Suitcase(const Suitcase& );
    Suitcase& operator=(const Suitcase& );
    ~Suitcase();

    bool isThereRoomForGarment();
    void add(Clothes* );
    void remove(int );

    
};


#endif