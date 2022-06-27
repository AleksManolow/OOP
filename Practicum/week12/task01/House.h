#ifndef __HOUSE_H
#define __HOUSE_H
#include"Building.h"
#include<cstring>
class House:public Building
{
private:
    int floor;
    char* ownerName;
public:
    House();
    House(double, double, char*, int , char* );
    House(const House& );
    House& operator=(const House& );
    ~House();

    double averageFloorHeight();

    void loadFromStream(std::istream& is);
    void writeToStream(std::ostream& os);
};

#endif