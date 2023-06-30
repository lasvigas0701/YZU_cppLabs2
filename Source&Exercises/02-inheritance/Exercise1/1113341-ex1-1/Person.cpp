#include <iostream>
using namespace std;

class Person {
public:
	Person();
	Person(string name, int age, string address);
	void setName(string name);
	void setAge(int age);
	void setAddress(string address);
	string getName();
	int getAge();
	string getAddress();
	void display();

private:
	string name;
	int age;
	string address;
};

Person::Person() {}
Person::Person(string name, int age, string address)
{
	setName(name);
	setAge(age);
	setAddress(address);
}
void Person::setName(string name)
{
	this->name = name;
}
void Person::setAge(int age)
{
	this->age = age;
}
void Person::setAddress(string address)
{
	this->address = address;
}
string Person::getName()
{
	return name;
}
int Person::getAge()
{
	return age;
}
string Person::getAddress()
{
	return address;
}
void Person::display()
{
	cout << "Name: " << getName() << endl;
	cout << "Age: " << getAge() << endl;
	cout << "Address: " << getAddress() << endl;
}