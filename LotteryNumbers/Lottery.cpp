#include <iostream>
#include <vector>
#include <cstdlib>
#include <string>
#include <time.h>
using namespace std;

class lotto
{
public:
	void quickPick()
	{
		cout << "GENERATED LOTTERY NUMBERS - Patorn Pongsanit \n\n" << endl;
		srand(time(0));
		for(int i=1; i<=69; i++)
		{
			cout << i << ". " << "Lottery numbers: ";
		for(int i=0; i<6; i++)
		{
		cout << (1+rand()%54) << " ";
		}
		cout << endl << endl;
		}
	}

private:
};

int main()
{
	lotto lottoObject;
	
	lottoObject.quickPick();
	
	return 0;
}