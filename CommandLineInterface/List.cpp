#include "List.h"
#include "misc.h"
#include <string>
#include <algorithm> 


int List::lastWordIDUsed = 100;

string List::ADDSTRING(string s)
{
	List list;
	list.name=s;
	list.assignNewID();
	addWordToVWord(list);
	return "STRING added.";
}

void List::addWordToVWord(List & b)
{
	pair<string,int> p;
	p.first=b.name;
	p.second = vWord.size();
	vWord.push_back(b);
}

string List::SHOWSTRINGS()
{
	string result;
	result+=padRight("Id",'.',10);
	result+=padRight("Name",'.',10);

	vector<List>::iterator iter;

	iter = vWord.begin();

	while(iter!=vWord.end())
	{ 
		result+= "\n" + padLeft(intToString( (*iter).id),' ',8)+"  ";
		result+=padRight( (*iter).name,' ',20);
		iter++;
	}

	return result;
}

string List::REMOVESTRING(int delId)
{
	vector<List>::iterator iter;

	iter = vWord.begin();

	while(iter!=vWord.end())
	{

		if((*iter).id==delId)
		{
			vWord.erase(iter);
			return "Word removed.";
		}

		iter++;
	}
	return "Word ID not found.";
}
int List::tokenizeSize(vector<string> vs)
{
	return vs.size();
}
int List::WORDCOUNT()
{
	int result = 0;
	for(int i=0; i!=vWord.size(); i++)
	{
		result += tokenizeSize(tokenize2(vWord[i].name));
	}
	return result;
}

string List::WORDLIST()
{
	string result;
	vector<string> vWords;
	vector<string> vBridge;

	for(int i=0; i!=vWord.size(); i++)
	{
		vBridge = tokenize2(vWord[i].name);
		vWords.insert(vWords.end(), vBridge.begin(), vBridge.end());
	}
	 
	sort(vWords.begin(),vWords.end());

	for(int i=0; i!=vWords.size();i++)
	{
		result += vWords[i] + "\n";
	}
	
	return result;
}

string List::randString(int numOfChars)
{
	string result;
	string result2;
	int random = rand()%2;
	for(int i=0;i<numOfChars;i++)
	{
		{
		result+='A'+rand()%26;
		}
	}

	for(int i=0;i<numOfChars;i++)
	{
		{
		result2+='A'+rand()%26;
		}
	}
	if(random == 0)
	{
		return result + " " + result2;
	}
	else if(random == 1)
	{
		return result;
	}
}

string List::TEST(int count)
{
	for(int i=0;i<count;i++)
	{
		ADDSTRING(randString(1+rand()%8));
	}
	return "Random Words added.";
}
