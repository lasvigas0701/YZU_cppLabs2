#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

class revenueDetail {
public:
	void setRoomCode(string roomCodeValue)
	{
		roomCode = roomCodeValue;
	}

	string getRoomCode()
	{
		return roomCode;
	}

	void setNights(int nightValue)
	{
		numberOfNight = nightValue;
	}

	int getNights()
	{
		return numberOfNight;
	}

	virtual void compRevenue() = 0;

	double getRevenue()
	{
		return revenue;
	}
protected:
	string roomCode;
	int numberOfNight;
	double revenue;
};

class Deluxe : public revenueDetail{
public:
	void setServiceFee(int serviceFeeValue)
	{
		serviceFee = serviceFeeValue;
	}

	int getServiceFee()
	{
		return serviceFee;
	}

	void setExtraFee(int extraFeeValue)
	{
		extraFee = extraFeeValue;
	}

	int getExtraFee()
	{
		return extraFee;
	}

	void compRevenue() 
	{
		revenue = (numberOfNight * 7500 + serviceFee) * 1.15 + extraFee;
	}
private:
	int serviceFee;
	int extraFee;
};

class Premium : public revenueDetail {
public:
	void setServiceFee(int serviceFeeValue)
	{
		serviceFee = serviceFeeValue;
	}

	int getServiceFee()
	{
		return serviceFee;
	}

	void compRevenue()
	{
		revenue = (numberOfNight * 5000 + serviceFee) * 1.05;
	}
private:
	int serviceFee;
};

class Business : public revenueDetail {
public:
	void compRevenue()
	{
		revenue = (numberOfNight * 3000);
	}
};

class LastMonth {
public:
	LastMonth()
	{
		loadFile();
	}
	~LastMonth()
	{
		delete[] deluxe;
		delete[] premium;
		delete[] business;
	}

	void loadFile()
	{
		ifstream inFile("rooms-last.txt", ios::in);
		if (!inFile)
		{
			cerr << "rooms-last.imp could not be opened!\n";
			exit(1);
		}

		string codeBuf;
		int nightsBuf;
		int serviceBuf;
		int extraBuf;

		inFile >> d >> p >> b;
		deluxe = new Deluxe[d];
		for (int i = 0; i < d; i++)
		{
			inFile.ignore();
			getline(inFile, codeBuf, '\n');
			deluxe[i].setRoomCode(codeBuf);
			inFile >> serviceBuf;
			deluxe[i].setServiceFee(serviceBuf);
			inFile >> extraBuf;
			deluxe[i].setExtraFee(extraBuf);
			inFile >> nightsBuf;
			deluxe[i].setNights(nightsBuf);
		}

		premium = new Premium[p];
		for (int i = 0; i < p; i++)
		{
			inFile.ignore();
			getline(inFile, codeBuf, '\n');
			premium[i].setRoomCode(codeBuf);
			inFile >> serviceBuf;
			premium[i].setServiceFee(serviceBuf);
			inFile >> nightsBuf;
			premium[i].setNights(nightsBuf);
		}

		business = new Business[b];
		for (int i = 0; i < b; i++)
		{
			inFile.ignore();
			getline(inFile, codeBuf, '\n');
			business[i].setRoomCode(codeBuf);
			inFile >> nightsBuf;
			business[i].setNights(nightsBuf);
		}
	}

private:
	int d;
	int p;
	int b;

public:
	Deluxe* deluxe;
	Premium* premium;
	Business* business;
};

class Current{
public:
	Current()
	{
		loadFile();
	}
	~Current()
	{
		writeFile();
		delete[] deluxe;
		delete[] premium;
		delete[] business;

	}

	void loadFile()
	{
		ifstream inFile("rooms-current.txt", ios::in);
		if (!inFile)
		{
			cerr << "rooms-current.imp could not be opened!\n";
			exit(1);
		}

		string codeBuf;
		int nightsBuf;
		int serviceBuf;
		int extraBuf;

		inFile >> d >> p >> b;
		deluxe = new Deluxe[d];
		for (int i = 0; i < d; i++)
		{
			inFile.ignore();
			getline(inFile, codeBuf, '\n');
			deluxe[i].setRoomCode(codeBuf);
			inFile >> serviceBuf;
			deluxe[i].setServiceFee(serviceBuf);
			inFile >> extraBuf;
			deluxe[i].setExtraFee(extraBuf);
			inFile >> nightsBuf;
			deluxe[i].setNights(nightsBuf);
		}

		premium = new Premium[p];
		for (int i = 0; i < p; i++)
		{
			inFile.ignore();
			getline(inFile, codeBuf, '\n');
			premium[i].setRoomCode(codeBuf);
			inFile >> serviceBuf;
			premium[i].setServiceFee(serviceBuf);
			inFile >> nightsBuf;
			premium[i].setNights(nightsBuf);
		}

		business = new Business[b];
		for (int i = 0; i < b; i++)
		{
			inFile.ignore();
			getline(inFile, codeBuf, '\n');
			business[i].setRoomCode(codeBuf);
			inFile >> nightsBuf;
			business[i].setNights(nightsBuf);
		}
	}

	void writeFile()
	{
		LastMonth buffer;
		ofstream outFile("revenue.txt", ios::out);
		if (!outFile)
		{
			cerr << "revenue.out could not be opened!\n";
			exit(1);
		}

		outFile << d << " " << p << " " << b << endl;

		for (int i = 0; i < d; i++)
		{
			outFile << deluxe[i].getRoomCode() << endl;
			deluxe[i].compRevenue();
			outFile << deluxe[i].getRevenue() << endl;
			buffer.deluxe[i].compRevenue();
			if (deluxe[i].getRevenue() > buffer.deluxe[i].getRevenue() * 1.25)
				excellent.push_back(deluxe[i].getRoomCode());
		}

		for (int i = 0; i < p; i++)
		{
			outFile << premium[i].getRoomCode() << endl;
			premium[i].compRevenue();
			outFile << premium[i].getRevenue() << endl;
			buffer.premium[i].compRevenue();
			if (premium[i].getRevenue() > buffer.premium[i].getRevenue() * 1.25)
				excellent.push_back(premium[i].getRoomCode());
		}

		for (int i = 0; i < p; i++)
		{
			outFile << business[i].getRoomCode() << endl;
			business[i].compRevenue();
			outFile << business[i].getRevenue() << endl;
			buffer.business[i].compRevenue();
			if (business[i].getRevenue() > buffer.business[i].getRevenue() * 1.25)
				excellent.push_back(business[i].getRoomCode());
		}

		outFile << "==============\nExcellent Room:\n";
		for (int i = 0; i < excellent.size(); i++)
			outFile << excellent[i] << endl;
	}

private:
	int d;
	int p;
	int b;
	Deluxe* deluxe;
	Premium* premium;
	Business* business;
	vector<string> excellent;
};

int main() {
	Current current;
	return 0;
}