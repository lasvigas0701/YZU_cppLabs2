#include <iostream>
using namespace std;

class Teacher : public Person {
public:
	Teacher(string name, int age, string address, double salary)
	{
		setName(name);
		setAge(age);
		setAddress(address);
		setSalary(salary);
	}
	void setSalary(double salary)
	{
		this->salary = salary;
	}
	double getSalary()
	{
		return salary;
	}
	void display()
	{
		cout << "Name: " << getName() << endl;
		cout << "Age: " << getAge() << endl;
		cout << "Address: " << getAddress() << endl;
		cout << "Salary: " << getSalary() << "\tTWD\n\n";
	}

private:
	double salary;
};