#include "Library.h"
#include "Patron.h"
#include "misc.h"
#include <fstream>
#include <algorithm>
using namespace std;


Library::Library()
{
	ifstream fin("libBooks.txt");
	string inputLine;
	if (fin.fail())
	{
		lastBookIDUsed = 0;
	}
	getline(fin, inputLine);
	lastBookIDUsed = stringToInt(inputLine);
	while (!fin.eof())
	{
		getline(fin, inputLine);
		if ((!fin.eof())&&(inputLine.length()!=0))
		{
			vector<string> token = tokenize(inputLine);
			addBook(token[1], token[2], token[3], stringToInt(token[0]), stringToInt(token[4]));
		}
		else
		{
			break;
		}
	}
	fin.close();
}

Library::~Library()
{
	ofstream fout("libBooks.txt");
	fout << lastBookIDUsed << endl;

	vector<Book>::iterator iter;

	iter = vBook.begin();

	while (iter != vBook.end())
	{
		if (!(*iter).isDeleted)
		{
			fout << (*iter).id << " ";
			fout << (*iter).name << ";";
			fout << (*iter).author << ";";
			fout << (*iter).subject << ";";
			fout << (*iter).checkOutBy << endl;

		}
		iter++;
	}
	fout.close();
}


string Library::addBook(string n, string a, string s, int idNumber, int chkedOut)
{
	Book newBook;
	newBook.name=n;
	newBook.author=a;
	newBook.subject=s;
	if (idNumber == 0)
	{
		lastBookIDUsed++;
		newBook.id = lastBookIDUsed;
		newBook.checkOutBy = 0;
	}
	else
	{
		newBook.id = idNumber;
		newBook.checkOutBy = chkedOut;
	}
	newBook.isDeleted = false;
	
	bookIdIndex[newBook.id] = vBook.size();
	vBook.push_back(newBook);
	return "Book added.";
}

string Library::removeBook(int id)
{
	
	if (bookIdIndex.find(id) == bookIdIndex.end())
	{
		throw (string)"ERROR: Invalid book ID.";
	}
	if (vBook[bookIdIndex[id]].isDeleted)
	{
		throw (string)"WARNING: This book is already removed.";
	}
	
	vBook[bookIdIndex[id]].isDeleted = true;
	return vBook[bookIdIndex[id]].name + " is deleted.";
}



string Library::displayBooksByName()
{
	// sort vBooks by Name
	string result;
	sort(vBook.begin(),vBook.end(),compareByName);
	result = displayBooks();
	sort(vBook.begin(), vBook.end());
	return result;
}


string Library::displayBooksByAuthor()
{
	// sort vBooks by Author
	string result;
	sort(vBook.begin(), vBook.end(), compareByAuthor);
	result = displayBooks();
	sort(vBook.begin(), vBook.end());
	return result;
}

int Library::bookCount()
{
	int result = 0;
	vector<Book>::iterator iter;

	iter = vBook.begin();

	while (iter != vBook.end())
	{
		if (!(*iter).isDeleted)
		{
			result++;
		}
		iter++;
	}

	return result;
}


string Library::displayBooks()
{
	string result;
	result+=padRight("Id",'.',10);
	result+=padRight("Name",'.',20);
	result+=padRight("Author",'.',20);
	result+=padRight("Subject",'.',20)+"\n";
	result+=padRight("",'-',70)+"\n";

	vector<Book>::iterator iter;

	iter = vBook.begin();

	while(iter!=vBook.end())
	{
		if (!(*iter).isDeleted)
		{
			result += padLeft(intToString((*iter).id), ' ', 8) + "  ";
			result += padRight((*iter).name, ' ', 20);
			result += padRight((*iter).author, ' ', 20);
			result += padRight((*iter).subject, ' ', 20) + "\n";
		}
		iter++;
	}

	return result;
}


int Patron::lastpatronIDUsed = 100;

string Library::addPatron(string name,string phone,string email)
{
	Patron newPatron;
	newPatron.assignNewID();
	newPatron.setName(name);
	newPatron.setPhoneNumber(phone);
	newPatron.setAddress(email);
	vPatron.push_back(newPatron);
	return "Patron added.";
}

string Library::displayPatrons()
{
	string result;

	result+=padRight("Id",'.',10);
	result+=padRight("Name",'.',20);
	result+=padRight("Phone Number",'.',20);
	result+=padRight("Email",'.',20)+"\n";
	result+=padRight("",'-',70)+"\n";

	vector<Patron>::iterator iter;

	iter = vPatron.begin();

	while(iter!=vPatron.end())
	{
		result+=padLeft(intToString( (*iter).id),' ',8)+"  ";
		result+=padRight( (*iter).getName(),' ',15);
		result+=padRight( (*iter).getPhoneNumber(),' ',22);
		result+=padRight( (*iter).getAddress(),' ',15)+"\n";
		iter++;
	}
	return result;
}

string Library::removePatron(int delId)
{
	vector<Patron>::iterator iter;

	iter = vPatron.begin();

	while(iter!=vPatron.end())
	{

		if((*iter).id==delId)
		{
			vPatron.erase(iter);
			return "Patron removed.";
		}

		iter++;
	}
	return "Patron ID not found.";
}

string Library::displayPatronsByName()
{
	// sort vPatrons by Name
	string result;
	sort(vPatron.begin(),vPatron.end(), compareByPatronName);
	result = displayPatrons();
	sort(vBook.begin(), vBook.end());
	return result;
}

string Library::addRandPatron(int count)
{
	for(int i=0;i<count;i++)
	{
		addPatron(randString(12), randNumberString(10), randString(20) +"@BroMail.com");
	}
	return "Random Patrons added.";
}

string Library::checkOut(int pID,int bID)
{
	string result;
	Book & curBook=getBookByID(bID);
	Patron curPatron=getPatronByID(pID);
	curBook.checkOutBy=pID;
	curPatron.BooksCheckedOut.push_back(bID);
	result=curBook.name + " has been checked out by "+curPatron.getName()+"\n";
	return result;
}


Patron & Library::getPatronByID(int key)
{
	vector<Patron>::iterator iter;
	
	for(iter=vPatron.begin();iter!=vPatron.end();iter++)
	{
		if((*iter).id==key)
		{
			return (*iter);
		}
	}
	return *(vPatron.end());
}

Book & Library::getBookByID(int key)
{
	vector<Book>::iterator iter;
	
	for(iter=vBook.begin();iter!=vBook.end();iter++)
	{
		if((*iter).id==key)
		{
			return (*iter);
		}
	}
	return *(vBook.end());
}

string Library::checkIn(int bID)
{
	string result;
	Book & curBook=getBookByID(bID);
	curBook.checkedIn.push_back(bID);
	result=curBook.name + " has been checked in\n";
	return result;
}

string Library::checkOutReport1()
{
	string result;

	vector<Book>::iterator iter;

	iter = vBook.begin();

	while(iter!=vBook.end())
	{
		result+=padLeft(intToString( (*iter).checkOutBy),' ',8)+"  ";
		result+=padLeft(( (*iter).name),' ',8)+"  ";
		iter++;
	}
	return result;

}

string Library::checkOutReport2()
{
	string result;

	vector<Patron>::iterator iter;

	iter = vPatron.begin();

	while(iter!=vPatron.end())
	{
		result+=padLeft(( (*iter).name),' ',8)+"  ";
		result+=padLeft(intToString( (*iter).id),' ',8)+"  ";
		iter++;
	}
	return result;

}