#include <iostream>
using namespace std;

class Rectangle {
	int width;
	int length;
public:
	void input();
	void draw();
	double area();
	double perimeter();
};

void Rectangle::input(){
	cout << "width: ";
	cin >> width;
	cout << "length: ";
	cin >> length;
}

void Rectangle::draw() {
	for (int i = 0; i < length; i++) {
		for (int j = 0; j < width; j++) {
			cout << "* ";
		}
		cout << endl;
	}
}

double Rectangle::area() {
	return length * width;
}

double Rectangle::perimeter() {
	return 2 * (length + width);
}

int main() {
	Rectangle R1;
	R1.input();
	R1.draw();
	cout << "Area: " << R1.area() << "\nPerimeter: " << R1.perimeter() << endl;
}