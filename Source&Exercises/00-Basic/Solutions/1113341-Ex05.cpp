#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

struct profile {
	string fullname;
	double score;
	string grade;
};

string getGrade(double score) {
	string letter;
	if (score > 9.0)
		letter = "A";
	else if (score >= 8.0)
		letter = "B+";
	else if (score >= 7.0)
		letter = "B";
	else if (score >= 6.0)
		letter = "C+";
	else if (score >= 5.0)
		letter = "C";
	else if (score >= 4.5)
		letter = "D+";
	else if (score >= 4.0)
		letter = "D+";
	else
		letter = "F";

	return letter;
}

int main() {
	int n;
	cout << "Input n: ";
	cin >> n;
	
	profile* info = new profile[n];
	for (int i = 0; i < n; i++) {
		cout << "Student #" << i + 1 << ": ";
		cin.ignore();
		getline(cin, info[i].fullname);
		cin >> info[i].score;
	}
	cout << left << setw(20) << "FULL NAME" << setw(10) << "SCORE" << setw(10) << "GRADE" << endl;
	cout << "--------------------------------------------\n";
	for (int i = 0; i < n; i++) {
		info[i].grade = getGrade(info[i].score);
		cout << left << setw(20) << info[i].fullname << setw(10) << info[i].score << setw(10) << info[i].grade << endl;
	}

	delete[] info;
	return 0;
}