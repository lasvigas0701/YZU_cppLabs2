#include <iostream>
using namespace std;

class Person {
private:
	string name;
	int age;
	string address;
public:
	Person() {};
	Person(string n, int a, string add)
	{
		setName(n);
		setAge(a);
		setAddress(add);
	}
	void setName(string n)
	{
		name = n;
	}
	string getName()
	{
		return name;
	}
	void setAge(int a)
	{
		age = a;
	}
	int getAge()
	{
		return age;
	}
	void setAddress(string add)
	{
		address = add;
	}
	string getAddress()
	{
		return address;
	}
};

class Employee : public Person {
private:
	double salary;
	static int count;
public:
	Employee() { count++; };
	Employee(string name, int age, string address, double salary)
	{
		setName(name);
		setAge(age);
		setAddress(address);
		setSalary(salary);
		count++;
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
		cout << "Salary: " << getSalary() << endl << endl;
	}
	static int getCount()
	{
		return count;
	}
};
int Employee::count = 0;

class Manager : public Employee {
private:
	double bonus;
public:
	Manager(string name, int age, string address, double salary, double bonus)
	{
		setName(name);
		setAge(age);
		setAddress(address);
		setSalary(salary);
		setBonus(bonus);
	}
	void setBonus(double bonus)
	{
		this->bonus = bonus;
	}
	double getBonus()
	{
		return bonus;
	}
	void display()
	{
		cout << "Name: " << getName() << endl;
		cout << "Age: " << getAge() << endl;
		cout << "Address: " << getAddress() << endl;
		cout << "Salary: " << getSalary() + getBonus() << endl << endl;
	}
};

#include <iostream>
int main() {
	Employee em1("Lin Jia - Hui", 24, "23, Da - an", 25000);
	Employee em2("Lee Zhe-Wei", 22, "12, Lin Shen street", 30000);
	Employee em3("Chen Zheng", 28, "2, Xinyi Street", 28000);

	em1.display();
	em2.display();
	em2.display();

	Manager ma1("Huang Shen", 32, "23 Yuan Dong street", 50000, 3000);

	ma1.display();

	cout << "Number of employee:" << Employee::getCount() << endl;
	
	return 0;
}