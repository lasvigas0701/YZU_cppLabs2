#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

class Book {
private:
	string code;
	string name;
	string publisher;
	int numPage;
	double price;
public:
	void input();
	void output();
};

void Book::input() {
	cout << "Book Code: ";
	getline(cin, code);
	cout << "Book Name: ";
	getline(cin, name);
	cout << "Book publisher: ";
	getline(cin, publisher);
	cout << "Book numPage: ";
	cin >> numPage;
	cout << "Book Price: ";
	cin >> price;
	cin.ignore();
}

void Book::output() {
	cout << left << setw(10) << code << setw(10) << name << setw(10) << publisher << 
		setw(10) << numPage << setw(10) << price << endl;
}

int main() {
	int n;
	cout << "input n: ";
	cin >> n;
	cin.ignore();
	Book* books = new Book[n];
	for (int i = 0; i < n; i++) {
		books[i].input();
	}
	cout << "\nProduct Information: \n";
	for (int i = 0; i < n; i++) {
		books[i].output();
	}
	delete[] books;
}