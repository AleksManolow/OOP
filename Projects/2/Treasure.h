#ifndef Treasure_H
#define Treasure_H

#include<iostream>
#include<string>

class Treasure
{
private:
    double percent; 
    std::string name;
public:
    Treasure();
    Treasure(double _percent, std::string _name);
    virtual ~Treasure() = default;

    double getPercent() const;
    std::string getName() const;

    void setPercent(double _percent);
    void setName(std::string _name);

    virtual void print() const;

};

#endif