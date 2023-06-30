#include <iostream>
#include <algorithm>
using namespace std;

class Fraction
{
public:
	Fraction()
	{
	}

	Fraction(int n, int d)
	{
		setNum(n);
		setDen(d);
	}

	void setNum(int n)
	{
		num = n;
	}

	void setDen(int d)
	{
		if (d == 0)
		{
			cout << "denominator cannot be 0!\n";
			exit(100); /*if denmoinator is 0, end the program*/
		}
		den = d;
	}

	int getNum()
	{
		return num;
	}

	int getDen()
	{
		return den;
	}

	Fraction operator-()
	{
		num = (-num);
		return *this;
	}

	Fraction operator+(Fraction frac)
	{
		Fraction buf;
		if (this->den == frac.den)
		{
			buf.setDen(den);
			buf.setNum(this->num + frac.num);
		}
		else
		{
			buf.setDen(this->den * frac.den);
			buf.setNum((this->num * frac.den) + (frac.num * this->den));
		}
		return buf;
	}

	Fraction operator-(Fraction frac)
	{
		Fraction buf;
		if (this->den == frac.den)
		{
			buf.setDen(den);
			buf.setNum(this->num - frac.num);
		}
		else
		{
			buf.setDen(this->den * frac.den);
			buf.setNum((this->num * frac.den) - (frac.num * this->den));
		}
		return buf;
	}
	
	Fraction operator*(Fraction frac)
	{
		Fraction buf(this->num * frac.num, this->den * frac.den);
		return buf;
	}

	Fraction operator/(Fraction frac)
	{
		Fraction buf(this->num * frac.den, this->den * frac.num);
		return buf;
	}

	bool operator<(Fraction op2)
	{
		if (den == op2.den)
			return num < op2.num;

		int op1Num = num * op2.den, op2Num = op2.num * den;

		return op1Num < op2Num;
	}

	bool operator>(Fraction op2)
	{
		int op1Num = num * op2.den, op2Num = op2.num * den;

		return op1Num > op2Num;
	}

	bool operator==(Fraction op2)
	{
		int op1Num = num * op2.den, op2Num = op2.num * den;

		return op1Num == op2Num;
	}

	bool operator!=(Fraction op2)
	{
		return !(*this == op2);
	}

	bool operator<=(Fraction op2)
	{
		return ((*this < op2) || (*this == op2));
	}

	bool operator>=(Fraction op2)
	{
		return ((*this > op2) || (*this == op2));
	}

	friend ostream& operator<<(ostream& output, const Fraction& frac)
	{
		//frac.simplify();
		if (frac.num % frac.den == 0)
			output << frac.num / frac.den;
		else
			output << frac.num << "/" << frac.den;
		
		return output;
	}

	friend istream& operator>>(istream& input, Fraction& frac)
	{
		input >> frac.num >> frac.den;
		return input;
	}

	Fraction operator+=(Fraction op2)
	{
		*this = *this + op2;
		return *this;
	}
	
	Fraction operator-=(Fraction op2)
	{
		*this = *this - op2;
		return *this;
	}

	Fraction operator++()
	{
		this->num += den;
		return *this;
	}

	Fraction operator--()
	{
		this->num -= den;
		return *this;
	}

	Fraction operator++(int)
	{
		Fraction temp = *this;
		this->setNum(this->num + this->den);
		return temp;
	}

	Fraction operator--(int)
	{
		Fraction temp = *this;
		this->setNum(this->num - this->den);
		return temp;
	}

	Fraction operator=(Fraction op2)
	{
		this->num = op2.num;
		this->den = op2.den;
		return *this;
	}

Fraction simplify()
	{
		int r = 0, bufN = num, bufD = den;
		while (bufD != 0)
		{
			r = bufN % bufD;
			bufN = bufD;
			bufD = r;
		}

		den /= bufN;
		num /= bufN;

		return *this;
	}
private:
	int num;
	int den;
};

template<typename T>
T maxmum(T a, T b)
{
	return a > b ? a : b;
}

template<typename T>
T minimum(T a, T b)
{
	return a < b ? a : b;
}

template<typename T>
T smallest(T a[], int n) /*n is the number of elements of array a*/
{
	T buf = a[0];
	for (int i = 0; i < n; i++)
		if (buf > a[i])
			buf = a[i];

	return buf;
}

template<typename T>
T largest(T a[], int n) /*n is the number of elements of array a*/
{
	T buf = a[0];
	for (int i = 0; i < n; i++)
		if (buf < a[i])
			buf = a[i];

	return buf;
}

template<typename T>
T* sorting(T a[], int n) /*n is the number of elements of array a*/
{
	sort(a, a + n);
	return a;
}

/*self-testing code
int main()
{
	Fraction arr[3];
	for (int i = 0; i < 3; i++)
		cin >> arr[i];
	//int arr[] = { 1, -2, 3, -4 };
	sorting(arr, 3);
	for (int i = 0; i < 3; i++)
		cout << arr[i] << " ";

	return 0;
}*/