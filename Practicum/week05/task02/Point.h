#ifndef POINT_H
#define POINT_H
class Point
{
private:
    double x;
    double y;
public:
    Point(double _x = 0, double _y = 0): x(_x), y(_y)
    { }
    void initPoint();
    double getX() const;
    double getY() const;
};
#endif