#ifndef __BUILDING_H
#define __BUILDING_H

#include<iostream>
#include<cstring>
class Building
{
private:
    double height;
    double area;
    char* address;
protected:
    char* allocateMemory(char* s);
    void deleteMemory(char* s);
public:
    Building();
    Building(double, double, char*);
    Building(const Building& );
    Building& operator=(const Building& );
    ~Building();

    int getHeight() {   return height;  };

    void loadFromStream(std::istream& is);
    void writeToStream(std::ostream& os);
};

#endif