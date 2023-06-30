#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
using namespace std;

class Product {
protected:
	string name;
	string brand;
	double price;
public:
	Product() {};
	Product(string name, string brand, double price)
	{
		this->name = name;
		this->brand = brand;
		this->price = price;
	}
	Product(const Product& product)
	{
		this->name = product.name;
		this->brand = product.brand;
		this->price = product.price;
	}
	void display()
	{
		cout << left << setw(20) << name << setw(13) << brand << setw(8) << price << endl;
	}
	double getPrice()
	{
		return price;
	}
};

class Laptop : public Product{
protected:
	int ram;
	int hdd;
public:
	Laptop(string name, string brand, int ram, int hdd, double price)
	{
		this->name = name;
		this->brand = brand;
		this->price = price;
		this->ram = ram;
		this->hdd = hdd;
	}
	void display()
	{
		cout << left << setw(20) << name << setw(13) << brand << setw(8) << price << endl;
	}
};

class Smartphone : public Product {
protected:
	string os;
	string camera;
public:
	Smartphone(string name, string brand, string os, string camera, double price)
	{
		this->name = name;
		this->brand = brand;
		this->price = price;
		this->os = os;
		this->camera = camera;
	}
	void display()
	{
		cout << left << setw(20) << name << setw(13) << brand << setw(8) << price << endl;
	}
};

class Order : public Product{
private:
	string name;
	string address;
	vector <Product> items;
	double delivery;
public:
	Order(){}
	void setName(string name)
	{
		this->name = name;
	}
	void setAddress(string address)
	{
		this->address = address;
	}
	void setDelivery(double delivery)
	{
		this->delivery = delivery;
	}
	void add(Product product)
	{
		items.push_back(product);
	}
	double getTotal()
	{
		double ttl{};
		for (int i = 0; i < items.size(); i++)
			ttl += items[i].getPrice();
		ttl += delivery;
		return ttl;
	}
	void display()
	{
		cout << "> ORDER DETAILS:\n";
		cout << "NAME: " << name << endl;
		cout << "ADDRESS: " << address << endl;
		cout << "-----------------------------------\n";
		for (int i = 0; i < items.size(); i++)
		{
			items[i].display();
		}
		cout << "-----------------------------------\n";
		cout << "DELIVERY FEE: " << delivery << " TWD\n";
		cout << "TOTAL: " << getTotal() << endl;
	}
};

int main() {
	Order od1;

	Laptop lt1{ "VivoBook", "Asus", 8, 512, 30000 };
	Laptop lt2{ "Swift 5", "Acer", 16, 512, 34000 };
	Smartphone sp1{ "Galaxy S23 Ultra", "Samsung", "Android", "12", 36900 };
	Smartphone sp2{ "iPhone 14 Pro", "iPhone", "iOS", "12", 38000 };
	Smartphone sp3{ "Xiaomi 13 Pro", "Xiaomi", "Android", "12", 34888 };

	string name;
	string addr;
	cout << "> INPUT ORDER:\nEnter name: ";
	getline(cin, name);
	od1.setName(name);
	cout << "Enter address: ";
	getline(cin, addr);
	od1.setAddress(addr);
	int pd;
	char add;
	do {
		int i = 0;
		cout << "\nPRODUCT LIST:\n";
		cout << left << setw(6) << "No." << setw(20) << "Name" << setw(13) << "Brand" << setw(8) << "Price" << endl;
		cout << "-----------------------------------------------\n";
		
		cout << left << setw(6) << "1"; lt1.display();
		cout << left << setw(6) << "2"; lt2.display();
		cout << left << setw(6) << "3"; sp1.display();
		cout << left << setw(6) << "4"; sp2.display();
		cout << left << setw(6) << "5"; sp3.display();
		
		cout << "\nChoose product (input 0 to stop choosing): ";
		cin >> pd;
		if (pd == 1)
		{
			od1.add(lt1);
		}
		else if (pd == 2)
		{
			od1.add(lt2);
		}
		else if (pd == 3)
		{
			od1.add(sp1);
		}
		else if (pd == 4)
		{
			od1.add(sp2);
		}
		else if (pd == 5)
		{
			od1.add(sp3);
		}
		cin.ignore();
		cout << "Add more product (Y/N) ? ";
		cin >> add;
	} while (add == 'Y');

	cout << "\nInput delivery fee: ";
	double fee;
	cin >> fee;
	cout << endl;
	od1.setDelivery(fee);

	od1.display();
	
	cout << "\nEND.";;
}