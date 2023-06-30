#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

class Product {
private:
	string ID;
	string name;
	int quantity;
	double price;
public:
	void input();
	void output();
};

void Product::input() {
	cout << "Product ID: ";
	getline(cin, ID);
	cout << "Product Name: ";
	getline(cin, name);
	cout << "Product Quantity: ";
	cin >> quantity;
	cout << "Product Price: ";
	cin >> price;
	cin.ignore();
}

void Product::output() {
	cout << left << setw(10) << ID << setw(10) << name << setw(10) << price << setw(5) << quantity << endl;
}

int main() {
	int n;
	cout << "input n: ";
	cin >> n;
	cin.ignore();
	Product* products =new Product[n];
	for (int i = 0; i < n; i++) {
		products[i].input();
	}
	cout << "\nProduct Information: \n";
	for (int i = 0; i < n; i++) {
		products[i].output();
	}
	delete[] products;
}