#include<iostream>
using namespace std;

class Book {
private:
	string title;
	string author;
	int quantity;
public:
	Book();
	Book(string title);
	Book(string title, string author);
	string getTitle();
	void setTitle(string title);
	string getAuthor();
	void setAuthor(string author);
	int getQuantity();
	void setQuantity(int quantity);
};

Book::Book() {};

Book::Book(string title) 
{
	setTitle(title);
	author = "";
	quantity = 0;
}

Book::Book(string title, string author)
{
	setTitle(title);
	setAuthor(author);
	quantity = 0;
}

string Book::getTitle()
{
	return title;
}

void Book::setTitle(string title)
{
	this->title = title;
}

string Book::getAuthor()
{
	return author;
}

void Book::setAuthor(string author)
{
	this->author = author;
}

int Book::getQuantity()
{
	return quantity;
}

void Book::setQuantity(int quantity)
{
	this->quantity = quantity < 0 ? 0 : quantity;
}