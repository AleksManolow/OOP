#ifndef ANIMAL_H
#define ANIMAL_H
#include<iostream>

enum Type
{
    MAMMAL, 
    REPTILE, 
    FISH, 
    BIRD, 
    AMPHIBIAN, 
    IVERTEBRATES, 
    INSECT
};

struct Animal
{
    Type mType;
    char* mName;
    unsigned mAge;

    void initialize();
    void deleteDynamic();
    void loadFromStream(std::istream& );
    void writeToStream(std::ostream& );

};
#endif