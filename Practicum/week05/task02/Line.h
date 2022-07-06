#ifndef LINE_H
#define LINE_H

#include "Point.h"
#define EPS 0.000001

class Line
{
private:
    Point a;
    Point b;
public:
    Line(const Point& _a, const Point& _b): a(_a), b(_b) 
    { }
    void readLine();
    bool isParallelWith(const Line& other);
    bool contains(const Point& p);
    //Point* intersection(const Line& other);
    //void write(std::ostream& out);
};

#endif