#include <iostream>
#include <cmath>
#include "Point.cpp"
using namespace std;

class Triangle : public Point {
private:
	Point A;
	Point B;
	Point C;

public:
	Triangle()
	{
	}
	Triangle(Point A, Point B, Point C)
	{
	}
	bool isTriangle()
	{
		double lineAB = sqrt(pow((A.getX() - B.getX()), 2) + pow((A.getY() - B.getY()), 2));
		double lineAC = sqrt(pow((A.getX() - C.getX()), 2) + pow((A.getY() - C.getY()), 2));
		double lineBC = sqrt(pow((B.getX() - C.getX()), 2) + pow((B.getY() - C.getY()), 2));

		return (lineAB + lineAC > lineBC) && (lineBC + lineAC > lineAB) && (lineAB + lineBC > lineAC);
	}
	double perimeter()
	{
		double lineAB = sqrt(pow((A.getX() - B.getX()), 2) + pow((A.getY() - B.getY()), 2));
		double lineAC = sqrt(pow((A.getX() - C.getX()), 2) + pow((A.getY() - C.getY()), 2));
		double lineBC = sqrt(pow((B.getX() - C.getX()), 2) + pow((B.getY() - C.getY()), 2));
		return lineAB + lineBC + lineAC;
	}
	double area()
	{
		double p = perimeter() / 2;
		double lineAB = sqrt(pow((A.getX() - B.getX()), 2) + pow((A.getY() - B.getY()), 2));
		double lineAC = sqrt(pow((A.getX() - C.getX()), 2) + pow((A.getY() - C.getY()), 2));
		double lineBC = sqrt(pow((B.getX() - C.getX()), 2) + pow((B.getY() - C.getY()), 2));
		double a = sqrt(p * (p - lineAB) * (p - lineAC) * (p - lineBC));
		return a;
	}
};