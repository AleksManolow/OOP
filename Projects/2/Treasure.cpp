#include"Treasure.h"

Treasure::Treasure()
{
    percent = 0;
}
Treasure::Treasure(double _percent, std::string _name)
{
    percent = _percent;
    name = _name;
}
double Treasure::getPercent() const
{
    return percent;
}
std::string Treasure::getName() const
{
    return name;
}
void Treasure::setPercent(double _percent)
{
    percent = _percent;
}
void Treasure::setName(std::string _name)
{
    name = _name;
}
void Treasure::print() const
{
    std::cout << name << ' ' << percent << '%' << std::endl;
}