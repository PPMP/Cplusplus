#pragma once
#include <string>
#include <vector>
using namespace std;



class Patron
{
public:
	friend class Library;
	string addPatron(string s, string p, string em);
	string getName(){return name;}
	void setName(string s){name=s;}
	string getPhoneNumber(){return phone;}
	void setPhoneNumber(string s){phone=s;}
	string getAddress(){return email;}
	void setAddress(string s){email=s;}
	void assignNewID(){lastpatronIDUsed++;id=lastpatronIDUsed;}
	friend bool compareByPatronName(Patron &, Patron &);
	string name;
private:
	string phone;
	string email;
	unsigned int id;
	static int lastpatronIDUsed;
	vector<int> BooksCheckedOut;
	
};