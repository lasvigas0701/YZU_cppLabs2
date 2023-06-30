#include <iostream>
#include <cmath>
using namespace std;

class Shape {
public:
	double perimeter()
	{
		cout << "No define ";
		return -1; /*if derived class doesn't define perimeter, return -1*/
	}
	double area()
	{
		cout << "No define ";
		return -1; /*if derived class doesn't define area, return -1*/
	}
};

class Triangle : public Shape {
private:
	double a;
	double b;
	double c;

public:
	Triangle(double a, double b, double c)
	{
		this->a = a;
		this->b = b;
		this->c = c;
	}
	bool isTriangle()
	{
		return (a + b > c) && (a + c > b) && (b + c > a);
	}
	double perimeter()
	{
		if (isTriangle())
			return a + b + c;
		else
		{
			cout << "This is not a triangle\n";
			return 0;
		}
	}
	double area()
	{
		if (isTriangle())
		{
			double s = perimeter() / 2;
			return sqrt(s * (s - a) * (s - b) * (s - c));
		}
		else
		{
			cout << "This is not a triangle\n";
			return 0;
		}
	}
};

class Circle : public Shape {
private:
	double r;
public:
	Circle(double r)
	{
		this->r = r;
	}
};

class Rectangle : public Shape {
private:
	double width;
	double height;
public:
	Rectangle(double width, double height)
	{
		this->width = width;
		this->height = height;
	}
	bool isSquare()
	{
		return (width == height);
	}
	double perimeter()
	{
		return (width + height) * 2;
	}
	double area()
	{
		return width * height;
	}
};

int main() {
	// Examine Triangle class
	Triangle tri(3, 4, 5);
	if (tri.isTriangle()) {
		cout << "This is a triangle" << endl;
		cout << "Perimeter: " << tri.perimeter() << endl;
		cout << "Area:" << tri.area() << endl;
	}
	else {
		cout << "This is not a triangle" << endl;
	}

	// Examine Rectangle class
	Rectangle rec(8, 8);
	if (rec.isSquare()) {
		cout << "This is a square" << endl;
	}
	else {
		cout << "This is not a square" << endl;
	}
	cout << "Perimeter: " << rec.perimeter() << endl;
	cout << "Area: " << rec.area() << endl;
	// Examine Circle class
	Circle c(2.4);
	cout << "Perimeter: " << c.perimeter() << endl;
	cout << "Area: " << c.area() << endl;
	return 0;
}