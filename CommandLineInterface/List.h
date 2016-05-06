#pragma once
#include <vector>
using namespace std;

class List
{
public:	
	string ADDSTRING(string s);
	string SHOWSTRINGS();
	string REMOVESTRING(int delId);
	int WORDCOUNT();
	string WORDLIST();
	int tokenizeSize(vector<string> vs);
	string TEST(int count);
	string randString(int numOfChars);
	void assignNewID(){lastWordIDUsed++;id=lastWordIDUsed;}
private:
	string name;
	unsigned int id;
	static int lastWordIDUsed;
	vector<List> vWord;
	void addWordToVWord(List & b);
};