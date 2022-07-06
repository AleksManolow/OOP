#ifndef DEVELOPER_H
#define DEVELOPER_H
#include<iostream>

enum Position {
    JUNIOR_DEV,
    DEV,
    SENIOR_DEV,
    QA,
    MANAGER
};

struct Developer
{
    int mId;
    char* mFirstName;
    char* mLastName;
    Position mPosition;

    void initialize();
    void deleteDynamic();
    void loadFromStream(std::ifstream& );
    void writeToStream(std::ostream& );
    void print();
};

#endif