#include"CoordinatesHero.h"

CoordinatesHero::CoordinatesHero()
{
    x = 0;
    y = 0;
}
int CoordinatesHero::getX()const
{
    return x;
}
int CoordinatesHero::getY()const
{
    return y;
}
void CoordinatesHero::setX(int _x)
{
    x = _x;
}
void CoordinatesHero::setY(int _y)
{
    y = _y;
}
void CoordinatesHero::loadFromStream(std::istream& in)
{
    in >> x;
    in >> y;
}
void CoordinatesHero::writeToStream(std::ostream& out) const
{
    out << x << '\n';
    out << y << '\n';

}