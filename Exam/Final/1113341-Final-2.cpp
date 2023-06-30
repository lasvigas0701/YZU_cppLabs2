#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <algorithm>
using namespace std;

class Employee
{
private:
	string name;
	int age;
	double salary;
	double bonus;
	double advance;
	double total;
public:
	Employee()
	{
	}
	Employee(string name, int age, double salary, double bonus, double advance)
	{
		this->name = name;
		this->age = age;
		setSalary(salary);
		setBonus(bonus);
		setAdvance(advance);
	}
	~Employee()
	{
	}
	string getName()
	{
		return name;
	}
	double getSalary()
	{
		return salary;
	}
	double getBonus()
	{
		return bonus;
	}
	double getAdvance()
	{
		return advance;
	}
	double getTotal()
	{
		return total;
	}
	void setSalary(double salary)
	{
		this->salary = salary;
	}
	void setBonus(double bonus)
	{
		this->bonus = bonus;
	}
	void setAdvance(double advance)
	{
		this->advance = advance;
	}
	void setTotal(double total)
	{
		this->total = total;
	}
	bool operator > (const Employee& employee)
	{
		int smaller = name.size() < employee.name.size() ? name.size() : employee.name.size();
		for (int i = 0; i < smaller; i++)
		{
			if (this->name[i] > employee.name[i])
				return true;
			else if (this->name[i] < employee.name[i])
				return false;
		}
		return false;
	}
	bool operator < (const Employee& employee)
	{
		int smaller = name.size() < employee.name.size() ? name.size() : employee.name.size();
		for (int i = 0; i < smaller; i++)
		{
			if (this->name[i] < employee.name[i])
				return true;
			else if (this->name[i] > employee.name[i])
				return false;
		}
		return false;
	}
	friend ostream& operator << (ostream& os, Employee& employee)
	{
		os << "Name: " << employee.name << "  Age: " << employee.age
			<< "  Salary: " << employee.salary << "  Bonus: " << employee.bonus
			<< "  Advance: " << employee.advance << "  Total: " << employee.total << endl;

		return os;
	}
};

int main()
{
	ofstream outFile("output.txt", ios::out);
	if (!outFile)
	{
		cerr << "output.txt could not be opened\n";
		exit(3);
	}
	int n;
	cin >> n;
	outFile << n << endl;

	string nameBuf;
	int ageBuf;
	double salaryBuf;
	double bonusBuf;
	double advanceBuf;
	double totalBuf;
	double revenueBuf;

	Employee empBuf;

	vector <Employee> employeeList;
	for (int i = 0; i < n; i++)
	{
		cin.ignore();
		getline(cin, nameBuf, '\n');
		cin >> ageBuf;
		cin >> salaryBuf;
		cin >> revenueBuf;
		cin >> advanceBuf;
		bonusBuf = revenueBuf * 0.1;
		totalBuf= salaryBuf + bonusBuf - advanceBuf;

		Employee empBuf(nameBuf, ageBuf, salaryBuf, bonusBuf, advanceBuf);
		empBuf.setTotal(totalBuf);
		employeeList.push_back(empBuf);
	}

	string* sortingName = new string[employeeList.size()];

	for (int i = 0; i < employeeList.size(); i++)
	{
		sortingName[i] = employeeList[i].getName();
	}
	sort(sortingName, sortingName + employeeList.size());
	double* outputTotal = new double[employeeList.size()];
	for (int i = 0; i < employeeList.size(); i++)
	{
		for (int j = 0; j < employeeList.size(); j++)
		{
			if (sortingName[i] == employeeList[j].getName())
				outputTotal[i] = employeeList[j].getTotal();
		}
	}
	cout << "===== output for each employee =====\n";
	for (int i = 0; i < employeeList.size(); i++)
	{
		cout << employeeList[i] << endl;
		outFile << sortingName[i] << endl;
		outFile << outputTotal[i] << endl;
	}

	delete[] sortingName;
	delete[] outputTotal;

	outFile.clear();
	outFile.close();
}