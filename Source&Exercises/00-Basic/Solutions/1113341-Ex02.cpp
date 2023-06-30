#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;
	double S0{1}, S1{1}, S2{1};
	for (int i = 2; i <= n; i++) {
		S0 *= i;
		S1 += (1.0 / i);
		S2 += (1.0 / S0);
	}

	cout << "\nS0 = " << n << "! = " << S0 << endl;
	cout << "\nS1 = " << S1 << endl;
	cout << "\nS2 = " << S2 << endl;
	
	return 0;
}