#include <iostream>
using namespace std;

int recFib(int n) {
	if (n <= 1)
		return 1;
	else
		return recFib(n - 1) + recFib(n - 2);
}
int main() {
	int n;
	cin >> n;
	
	cout << recFib(n);
	
}