#include <iostream>
using namespace std;

class Animal {
private:
	string name;
	double speed;
	int feet;
public:
	Animal(string name, double speed, int feet)
	{
		this->name = name;
		this->speed = speed;
		this->feet = feet;
	}
	void display()
	{
		if (feet)
			cout << name << " has " << feet << " feet!\n";
		else
			cout << name << " has " << "0 feet!\n";
	}
	double getSpeed()
	{
		return speed;
	}
	string getName()
	{
		return name;
	}
};

int main() {
	Animal Cat("Cat", 48, 4);
	Animal Bird("Bird", 390, 2); 
	Animal Fish("Fish", 12, 0);

	Cat.display();
	Bird.display();
	Fish.display();
	cout << endl;

	cout << "Speed comparision:\n";
	if (Bird.getSpeed() > Cat.getSpeed() && Cat.getSpeed() > Fish.getSpeed())
		cout << Bird.getName() << " > " << Cat.getName() << " > " << Fish.getName();

	else if (Bird.getSpeed() < Cat.getSpeed() && Cat.getSpeed() < Fish.getSpeed())
		cout << Fish.getName() << " > " << Cat.getName() << " > " << Bird.getName();

	else if (Bird.getSpeed() > Cat.getSpeed() && Bird.getSpeed() < Fish.getSpeed())
		cout << Fish.getName() << " > " << Bird.getName() << " > " << Cat.getName();

	else if (Bird.getSpeed() < Cat.getSpeed() && Bird.getSpeed() > Fish.getSpeed())
		cout << Cat.getName() << " > " << Bird.getName() << " > " << Fish.getName();

	else if (Bird.getSpeed() > Fish.getSpeed() && Cat.getSpeed() < Fish.getSpeed())
		cout << Bird.getName() << " > " << Fish.getName() << " > " << Cat.getName();

	else if (Bird.getSpeed() < Cat.getSpeed() && Cat.getSpeed() > Fish.getSpeed())
		cout << Cat.getName() << " > " << Fish.getName() << " > " << Bird.getName();
}