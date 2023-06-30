#include <iostream>
#include <cmath>
#include "Point.cpp"
using namespace std;

class Line : public Point{
private:
	Point A;
	Point B;

public:
	Line()
	{
	}
	Line(Point A, Point B)
	{
	}
	double distance()
	{
		return sqrt(pow((A.getX() - B.getX()), 2) + pow((A.getY() - B.getY()), 2));
	}
};