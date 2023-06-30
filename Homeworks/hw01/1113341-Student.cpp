#include <iostream>
#include <string>
using namespace std;

class Student
{
private:
	string ID;
	string Name;
	double Score;
public:
	Student();
	Student(string id, string name);
	void setID(string id);
	string getID();
	void setName(string name);
	string getName();
	void setScore(double score);
	double getScore();
	string getGrade();
};

Student::Student()
{
}

Student::Student(string id = "0000", string name = "abcd")
{
	setID(id);
	setName(name);
	setScore(0);
}

void Student::setID(string id) {
	ID = id;
}

string Student::getID() {
	return ID;
}

void Student::setName(string name) {
	Name = name;
}

string Student::getName() {
	return Name;
}

void Student::setScore(double score) {
	if (score < 0) Score = 0;
	else if (score > 10) Score = 10;
	else Score = score;
}

double Student::getScore() {
	return Score;
}

string Student::getGrade() {
	if (Score >= 9.0)
		return "A";
	else if (Score >= 8.0)
		return "B+";
	else if (Score >= 7.0)
		return "B";
	else if (Score >= 6.0)
		return "C+";
	else if (Score >= 5.0)
		return "C";
	else if (Score >= 4.5)
		return "D+";
	else if (Score >= 4.0)
		return "D";
	else
		return "F";
}