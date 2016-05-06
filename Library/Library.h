#pragma once
#include "Book.h"
#include "Patron.h"
#include <vector>
#include <map>
using namespace std;

class Library
{
public:
	Library();
	~Library();
	string displayBooks();
	string displayBooksByName();
	string displayPatronsByName();
	string displayBooksByAuthor();
	int bookCount();
	string addBook(string n, string a, string s, int idNumber=0, int chkedOut=0);
	string addPatron(string name,string phone, string email);
	string displayPatrons();
	string removeBook(int id);
	string removePatron(int delId);
	string clearBooks() 
	{ 
		lastBookIDUsed = 0; 
		vBook.clear(); 
		return "All books cleared.";
	}
	string clearPatrons(){vPatron.clear();return "Patrons cleared.";}
	int patronCount(){return vPatron.size();}
	string addRandPatron(int count);
	string checkOut(int pID,int bID);
	string checkIn(int bID);
	string checkOutReport1();
	string checkOutReport2();
private:
	map<int, int> bookIdIndex;
	vector<Book> vBook;
	vector<Patron> vPatron;
	int lastBookIDUsed;
	Book & getBookByID(int id);
	Patron & getPatronByID(int id);
};