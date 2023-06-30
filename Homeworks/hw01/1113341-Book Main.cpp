#include <iostream>
#include <string>
#include "Book.cpp"
using namespace std;
int main() {
	Book b1("C++ Primer, 5th Edition", "Stanley B. Lippman");
	Book b2("Object-Oriented Programming Simplified", "Hari Mohan Pandey");
	Book b3("Design Patterns in Modern C++","Dmitri Nesteruk");
	b1.setQuantity(5);
	b2.setQuantity(2);
	b3.setQuantity(4);
	string title;
	int quantity;
	while (true) {
		cout << "Please input book title: ";
		getline(cin, title);
		cout << "Please input quantity: ";
		cin >> quantity;
		
		if (title == b1.getTitle()) {
			if (quantity <= b1.getQuantity()) {
				cout << "Borrow Succeeded!\n";
				b1.setQuantity(b1.getQuantity() - quantity);
			}
			else
				cout << "The quantity is not enough, please try again!\n";
		}
		else if (title.compare(b2.getTitle()) == 0) {
			if (quantity <= b2.getQuantity()) {
				cout << "Borrow Succeeded!\n";
				b2.setQuantity(b2.getQuantity() - quantity);
			}
			else
				cout << "The quantity is not enough, please try again!\n";
		}
		else if (title.compare(b3.getTitle()) == 0) {
			if (quantity <= b3.getQuantity()) {
				cout << "Borrow Succeeded!\n";
				b3.setQuantity(b3.getQuantity() - quantity);
			}
			else
				cout << "The quantity is not enough, please try again!\n";	
		}
		else
			cout << "Book not found\n";

		cin.ignore();
	}
	return 0;
}