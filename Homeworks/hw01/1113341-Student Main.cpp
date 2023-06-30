#include <iostream>
#include <iomanip>
#include "Student.cpp"
using namespace std;

int main() {
	Student s1("1111", "aaaa");
	Student s2("2222", "bbbb");
	Student s3("3333", "cccc");
	s1.setScore(7.2);
	s2.setScore(-0.7);
	s3.setScore(12.4);
	cout << right << setw(16) << "ID" << setw(7) << "NAME" << setw(8) << "SCORE" << setw(8) << "GRADE\n";
	cout << "Student 1: " << right << setw(5) << s1.getID() << setw(7) << s1.getName()
		<< setw(8) << s1.getScore() << setw(7) << s1.getGrade() << endl;
	cout << "Student 2: " << right << setw(5) << s2.getID() << setw(7) << s2.getName()
		<< setw(8) << s2.getScore() << setw(7) << s2.getGrade() << endl;
	cout << "Student 3: " << right << setw(5) << s3.getID() << setw(7) << s3.getName()
		<< setw(8) << s3.getScore() << setw(7) << s3.getGrade() << endl;
}