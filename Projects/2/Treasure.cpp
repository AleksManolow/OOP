#include"Treasure.h"

Treasure::Treasure()
{
    percent = 0;
}
Treasure::Treasure(double _percent, String _name)
{
    percent = _percent;
    name = _name;
}
double Treasure::getPercent() const
{
    return percent;
}
String Treasure::getName() const
{
    return name;
}
void Treasure::setPercent(double _percent)
{
    percent = _percent;
}
void Treasure::setName(String _name)
{
    name = _name;
}
void Treasure::print() const
{
    std::cout << "Name-"<< name << ' ' << "Percent-" << percent << '%' << std::endl;
}
void Treasure::loadFromStream(std::istream& in)
{
    in >> percent;
    in.ignore();
    in >> name;
}
void Treasure::writeToStream(std::ostream& out)
{
    out << percent << '\n';
    out << name << '\n';
}