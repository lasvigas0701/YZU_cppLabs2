#include <iostream>
#include "Time.cpp"
using namespace std;

int main() {
	Time t1(23, 9, 18);
	Time t2(3, 56, 23);
	cout << "Time t1: " << t1.getTime() << endl;
	cout << "Time t2: " << t2.getTime() << endl;
	
	t1.setHour(5);
	t1.setMinute(12);
	t1.setMinute(45);
	cout << "Time t1: " << t1.getTime() << endl;
	
	t1.sub(4365);
	cout << "Time t1: " << t1.getTime() << endl;
	t2.add(3817);
	cout << "Time t2: " << t2.getTime() << endl;
	
	if (t1.compare(t2) < 0)
		cout << "t1 is less than t2" << endl;
	else if (t1.compare(t2) > 0)
		cout << "t1 is greater than t2" << endl;
	else
		cout << "t1 is equal to t2" << endl;
	
	return 0;
}