#include <iostream>
#include <iomanip>
using namespace std;

class Employee {
private:
	string name;
	double salary;
	int age;
	static int count;
public:
	Employee(string name, int age, double salary)
	{
		this->name = name;
		this->salary = salary;
		this->age = age;
		count++;
	}
	Employee(const Employee& employee)
	{
		this->name = employee.name;
		this->salary = employee.salary;
		this->age = employee.age;
		count++;
	}
	void display()
	{
		cout << left << setw(19) << name << setw(7) << age << salary << endl;
	}
	double getSalary()
	{
		return salary;
	}
	static int getCount()
	{
		return count;
	}
};
int Employee::count = 0;

int main() {
	Employee LJH("Lin Jia-Hui", 28, 40000);
	Employee LS("Le Sang", 24, 38000);
	Employee YZW("Yang Zhe-Wei", 26, 45000);

	cout << "> EMPLOYEE LIST:\n";
	cout << left << setw(19) << "Name" << setw(7) << "Age" << "Salary\n";
	cout << "-----------------------------------\n";
	LJH.display();
	LS.display();
	YZW.display();
	cout << endl;

	cout << "> EMPLOYEE LIST AFTER SORTING:\n";
	cout << left << setw(19) << "Name" << setw(7) << "Age" << "Salary\n";
	cout << "-----------------------------------\n";

	if (LS.getSalary() < LJH.getSalary() && LJH.getSalary() < YZW.getSalary())
	{
		LS.display();
		LJH.display();
		YZW.display();
	}
	else if (LS.getSalary() > LJH.getSalary() && LJH.getSalary() > YZW.getSalary())
	{
		YZW.display();
		LJH.display();
		LS.display();
	}
	else if (LS.getSalary() < LJH.getSalary() && LS.getSalary() > YZW.getSalary())
	{
		LJH.display();
		LS.display();
		YZW.display();
	}
	else if (LS.getSalary() > LJH.getSalary() && LS.getSalary() < YZW.getSalary())
	{
		YZW.display();
		LS.display();
		LJH.display();
	}
	else if (LS.getSalary() < YZW.getSalary() && LJH.getSalary() > YZW.getSalary())
	{
		LJH.display();
		YZW.display();
		LS.display();
	}
	else if (LS.getSalary() > YZW.getSalary() && LJH.getSalary() < YZW.getSalary())
	{
		LS.display();
		YZW.display();
		LJH.display();
	}
	cout << endl;
}