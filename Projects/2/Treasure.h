#ifndef Treasure_H
#define Treasure_H

#include<iostream>
#include"String.h"

class Treasure
{
private:
    double percent; 
    String name;
public:
    Treasure();
    Treasure(double _percent, String _name);
    virtual ~Treasure() = default;

    double getPercent() const;
    String getName() const;

    void setPercent(double _percent);
    void setName(String _name);

    virtual void print() const;
    virtual void loadFromStream(std::istream& in);
    virtual void writeToStream(std::ostream& out);

};

#endif