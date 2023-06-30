#include <iostream>
using namespace std;

class Math {
private:
	static double pi;
public:
	static double getPi();
	static double abs(double a);
	static double add(double a, double b);
	static double sub(double a, double b);
	static double min(double a, double b);
	static double min(double a[], int n);
	static double max(double a, double b);
	static double max(double a[], int n);
	static double pow(double x, double n);
	static double avg(double a, double b);
	static double avg(double a[], int n);
};

double Math::pi = 3.14159;

double Math::getPi()
{
	//pi = 3.14159;
	return pi;
}

double Math::abs(double a)
{
	return a > 0 ? a : -a;
}

double Math::add(double a, double b) 
{ 
	return a + b; 
}

double Math::sub(double a, double b)
{ 
	return a - b;
}

double Math::min(double a, double b) 
{ 
	return a < b ? a : b; 
}

double Math::min(double a[], int n)
{
	double min = a[0];
	for (int i = 0; i < n; i++)
		if (a[i] < min)
			min = a[i];
	return min;
}

double Math::max(double a, double b)
{ 
	return a > b ? a : b; 
}

double Math::max(double a[], int n)
{
	double max = a[0];
	for (int i = 0; i < n; i++)
		if (a[i] > max)
			max = a[i];
	return max;
}

double Math::pow(double x, double n)
{
	double buf = 1;
	for (int i = 1; i <= n; i++)
		buf *= x;
	return buf;
}

double Math::avg(double a, double b)
{
	return (a + b) / 2;
}

double Math::avg(double a[], int n)
{
	double buf = 0;
	for (int i = 0; i < n; i++)
		buf += a[i];
	return buf / n;
}