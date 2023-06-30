#include <iostream>
using namespace std;

class Student : public Person {
public:
	Student(string name, int age, string address, double gpa)
	{
		setName(name);
		setAge(age);
		setAddress(address);
		setGpa(gpa);
	}
	void setGpa(double gpa)
	{
		this->gpa = gpa;
	}
	double getGpa()
	{
		return gpa;
	}
	void display()
	{
		cout << "Name: " << getName() << endl;
		cout << "Age: " << getAge() << endl;
		cout << "Address: " << getAddress() << endl;
		cout << "GPA: " << getGpa() << endl << endl;
	}

private:
	double gpa;
};