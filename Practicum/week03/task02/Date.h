#ifndef DATE_H
#define DATE_H
#include<iostream>
#include<fstream>
#include"Time.h"

struct Date
{

    int mYear;
    char* mMonth;
    int mDay;
    Time mTime;

    Date readDate(std::ifstream& );
    void writeDate(std::ofstream& );
};
#endif