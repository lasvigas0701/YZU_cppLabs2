#include <iostream>
#include <cmath>
using namespace std;

class Point {
private:
	double X;
	double Y;
public:
	Point();
	Point(double x, double y);
	void setX(double x);
	double getX();
	void setY(double y);
	double getY();
	void setPoint(double x, double y);
	double distance(double x, double y);
	double distance(Point another);
};

Point::Point(){
	X = Y = 0;
}

Point::Point(double x, double y){
	setPoint(x, y);
}

void Point::setX(double x) {
	if (x < 0) X = 0;
	else X = x;
}

double Point::getX() {
	return X;
}

void Point::setY(double y) {
	if (y < 0) Y = 0;
	else Y = y;
}

double Point::getY() {
	return Y;
}

void Point::setPoint(double x, double y) {
	setX(x);
	setY(y);
}

double Point::distance(double x, double y) {
	return sqrt(pow((X - x), 2) + pow((Y - y), 2));
}

double Point::distance(Point another) {
	return sqrt(pow((X - another.X), 2) + pow((Y - another.Y), 2));
}
