#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

class Customer {
public:
	void setName(string nameValue)
	{
		name = nameValue;
	}

	string getName()
	{
		return name;
	}

	void setNumber(int numberValue)
	{
		number = numberValue;
	}

	int getNumber()
	{
		return number;
	}

	void setUnitPrice(int unitPriceValue)
	{
		unitPrice = unitPriceValue;
	}

	int getUnitPrice()
	{
		return unitPrice;
	}


	virtual void setPayment() = 0;

	double getPayment()
	{
		return payment;
	}

protected:
	string name;
	int number;
	int unitPrice;
	double payment;
};

class Ordinary : public Customer{
public:
	void setPayment()
	{
		payment = (number * unitPrice * 1.1);
	}
};

class Loyal : public Customer {
public:
	void setYear(int yearValue)
	{
		year = yearValue;
	}

	int getYear()
	{
		return year;
	}

	void setPayment()
	{
		double promotion = (year * 0.05) < 0.5 ? (year * 0.05) : 0.5;
		payment = (number * unitPrice * (1 - promotion) * 1.1);
	}

private:
	int year;
};

class Special : public Customer{
public:
	void setPayment()
	{
		payment = (number * unitPrice * 0.5 * 1.1);
	}
};

class Payments {
public:
	Payments()
	{
		loadFile();
	}
	~Payments()
	{
		writeFile();
		delete[] ordinaries;
		delete[] loyals;
		delete[] specials;
	}

	void loadFile()
	{
		ifstream inFile("customer.txt", ios::in);
		if (!inFile)
		{
			cerr << "customer.imp could not be opened!\n";
			exit(1);
		}
		
		inFile >> x >> y >> z;
		/*cout << x << y << z;*/
		
		ordinaries = new Ordinary[x];
		string nameBuf;
		int numberBuf;
		int unitPriceBuf;
		int yearBuf;
		for (int i = 0; i < x; i++)
		{
			inFile.ignore();
			getline(inFile, nameBuf, '\n');
			
			ordinaries[i].setName(nameBuf);
			
			inFile >> numberBuf;
			//cout << numberBuf << endl;
			ordinaries[i].setNumber(numberBuf);
			
			inFile >> unitPriceBuf;
			ordinaries[i].setUnitPrice(unitPriceBuf);
			//cout << "up: " << ordinaries[i].getUnitPrice() << endl;
		}

		loyals = new Loyal[y];
		for (int i = 0; i < y; i++)
		{
			inFile.ignore();
			getline(inFile, nameBuf, '\n');
			loyals[i].setName(nameBuf);
			inFile >> numberBuf;
			loyals[i].setNumber(numberBuf);
			inFile >> unitPriceBuf;
			loyals[i].setUnitPrice(unitPriceBuf);
			inFile >> yearBuf;
			loyals[i].setYear(yearBuf);
		}

		specials = new Special[z];
		for (int i = 0; i < z; i++)
		{
			inFile.ignore();
			getline(inFile, nameBuf, '\n');
			specials[i].setName(nameBuf);
			inFile >> numberBuf;
			specials[i].setNumber(numberBuf);
			inFile >> unitPriceBuf;
			specials[i].setUnitPrice(unitPriceBuf);
		}
	}

	void compTotal()
	{
		for (int i = 0; i < x; i++)
		{ 
			ordinaries[i].setPayment();
			//cout << ordinaries[i].getPayment() << " ";
			total += ordinaries[i].getPayment();
		}
		/*cout << total << endl;*/
		for (int i = 0; i < y; i++)
		{
			loyals[i].setPayment();
			total += loyals[i].getPayment();
		}
		for (int i = 0; i < z; i++)
		{
			specials[i].setPayment();
			total += specials[i].getPayment();
		}
	}

	void writeFile()
	{
		ofstream outFile("payment.txt", ios::out);

		if (!outFile)
		{
			cerr << "payment.out could not be opened\n";
			exit(1);
		}

		outFile << x << " " << y << " " << z;
		outFile << endl;
		for (int i = 0; i < x; i++)
		{
			outFile << "name: " << ordinaries[i].getName() << endl;
			outFile << ordinaries[i].getPayment() << endl;
		}
		for (int i = 0; i < y; i++)
		{
			outFile << loyals[i].getName() << endl;
			outFile << loyals[i].getPayment() << endl;
		}
		for (int i = 0; i < z; i++)
		{
			outFile << specials[i].getName() << endl;
			outFile << specials[i].getPayment() << endl;
		}
		outFile << total << endl;
	}

private:
	int x;
	int y;
	int z;
	double total = 0;
	Ordinary* ordinaries;
	Loyal* loyals;
	Special* specials;
};

/*self-testing*/
int main() {
	Payments payment; /*load file by constructor*/
	payment.compTotal();
	/*file will be write when destructor is executed*/
	return 0;
}