#include "Line.h"
#include <cmath>


void Line::readLine()
{
    a.initPoint();
    b.initPoint();
}
bool Line::isParallelWith(const Line& otherLine)
{
    double slope1 = (b.getY()  - a.getY()) / (b.getX() - a.getX());
	double slope2 = (otherLine.b.getY() - otherLine.a.getY()) / (otherLine.b.getX() - otherLine.a.getX());
    
	return fabs(slope1 - slope2) < EPS;
}
bool Line::contains(const Point& p)
{
    return (p.getX() * (a.getY() - b.getY()))
    + (p.getY() * (b.getX() - a.getX()))
    + (a.getX() * b.getY())
    - (b.getX() * a.getY()) == 0; 
}
//Point* Line::intersection(const Line& other)
//{

//}
//void Line::write(std::ostream& out)
//{

//}