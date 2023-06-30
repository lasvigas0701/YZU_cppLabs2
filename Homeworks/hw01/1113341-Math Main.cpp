#include <iostream>
#include "Math.cpp"
using namespace std;

int main() {
	double a = -6, b = 8, c[10] = { 1, -2, 8, -5, 12, 9, 7, -4, 3, -6 };
	int n = 5;
	cout << "PI: " << Math::getPi() << endl;
	cout << "Absolute of A: " << Math::abs(a) << endl;
	cout << "Additon of A and B: " << Math::add(a, b) << endl;
	cout << "Subtraction of A and B: " << Math::sub(a, b) << endl;
	cout << "Minimum of A and B: " << Math::min(a, b) << endl;
	cout << "Maximum of A and B: " << Math::max(a, b) << endl;
	cout << "Average of A and B: " << Math::avg(a, b) << endl;
	cout << "A to the power of n is: " << Math::pow(a, n) << endl;
	cout << "Minimum of array c: " << Math::min(c, (sizeof(c)/sizeof(double))) << endl;
	cout << "Maximum of array c: " << Math::max(c, (sizeof(c) / sizeof(double))) << endl;
	cout << "Average of array c: " << Math::avg(c, (sizeof(c) / sizeof(double))) << endl;
}