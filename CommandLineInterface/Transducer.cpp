#include "Transducer.h"
#include <vector>
#include "misc.h"
using namespace std;


string Transducer::transduce(string command)
{
	string result;
	vector<string> token = tokenize(command);
	if((token[0]=="HELP")||(token[0]=="H"))
	{
		result="Commands:\n";
		result+="-------------------\n";
		result+="\tADDSTRING(AS)\n";
		result+="\tSHOWSTRING(SS)\n";
		result+="\tREMOVESTRING(RS)\n";
		result+="\tWORDCOUNT(WC)\n";
		result+="\tWORDLIST(WL)\n";
		result+="\tTEST(TST)\n";
		result+="\tHELP(H)\n";
		result+="\tQUIT(Q)\n";
	}
	else if((token[0]=="QUIT")||(token[0]=="Q"))
	{
		result="Goodbye.";
	}
	else if((token[0]=="ADDSTRING")||(token[0]=="AS"))
	{
		result = list.ADDSTRING(token[1]);
	}
	else if((token[0]=="SHOWSTRINGS")||(token[0]=="SS"))
	{
		result = list.SHOWSTRINGS();
	}
	else if((token[0]=="REMOVESTRING")||(token[0]=="RS"))
	{
		result = list.REMOVESTRING(stringToInt(token[1]));
	}
	else if((token[0]=="WORDCOUNT")||(token[0]=="WC"))
	{
		result="There are "+intToString(list.WORDCOUNT())+" words in the list.";
	}
	else if((token[0]=="WORDLIST")||(token[0]=="WL"))
	{
		result= list.WORDLIST();
	}
	else if((token[0]=="TEST")||(token[0]=="TST"))
	{
		result= list.TEST(stringToInt(token[1]));
	}
	else
	{
		result="Unrecognized Command!!!";
	}
	return result;
}
