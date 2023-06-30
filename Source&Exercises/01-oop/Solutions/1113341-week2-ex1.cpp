#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

class Student {
	string ID;
	string name;
	int age;
	double score;
public:
	Student(string I, string N);
	void input();
	void output();
};

Student::Student(string I, string N){
	ID = I; name = N;
}
void Student::input() {
	cout << "Student ID: ";
	getline(cin, ID);
	cout << "Student Name: ";
	getline(cin, name);
	cout << "Student Age: ";
	cin >> age;
	cout << "Student Score: ";
	cin >> score;
}

void Student::output() {
	cout << "\nStudent Information: \n";
	cout << left << setw(10) << ID << setw(10) << name << setw(5) << age << setw(5) << score << endl;
}

int main() {
	Student s1("111", "abc"), s2("222", "xyz");
	s1.input();
	s1.output();
}