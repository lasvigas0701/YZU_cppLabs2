#include<iostream>
using namespace std;

class Point {
public:
	Point();
	Point(int x, int y)
	{
		setX(x);
		setY(y);
	}
	void setX(int x)
	{
		this->x = x;
	}
	void setY(int y)
	{
		this->y = y;
	}
	int getX()
	{
		return x;
	}
	int getY()
	{
		return y;
	}
	void setPoint(int x, int y)
	{
		setX(x);
		setY(y);
	}
private:
	int x;
	int y;
};