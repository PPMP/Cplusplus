#pragma once
#include <string>
#include <vector>
using namespace std;



class Book
{
public:
	bool lessThan(Book otherBook);  // a.lessThan(b)
	bool operator <(Book otherBook);// a<b
	friend class Library;
	friend bool compareByAuthor(Book &, Book &);
	friend bool compareByName(Book &, Book &);
private:
	string name;
	string author;
	string subject;
	unsigned int id;
	bool isDeleted;
	int checkOutBy; 
	vector<int> checkedIn;
};
