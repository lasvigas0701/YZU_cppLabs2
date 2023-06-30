#include<iostream>
#include<algorithm>
using namespace std;

int main() {
	/*int a[3];
	for (int i = 0; i < 3; i++) {
		cin >> a[i];
	}

	sort(a, a + 3);
	for (int i = 0; i < 3; i++) {
		cout << a[i] << "  ";
	}*/

	int a, b, c;
	cin >> a >> b >> c;
	if (a > b && b > c)
		cout << c << " " << b << " " << a;
	else if (a > b && a > c && b < c)
		cout << b << " " << c << " " << a;
	else if (b > a && a > c)
		cout << c << " " << a << " " << b;
	else if (b > a && b > c && a < c)
		cout << a << " " << c << " " << b;
	else if (c > a && a > b)
		cout << b << " " << a << " " << c;
	else
		cout << a << " " << b << " " << c;

	return 0;
}