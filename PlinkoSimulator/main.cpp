#include <iostream>
#include "PlinkoSimulator.h"
#include <time.h>
#include <stdlib.h>
using namespace std;


int main()
{
	srand((unsigned int)time(NULL));
	PlinkoSimulator plinkoSimulator;
	cout << "Drop Position\tAverage Money" << endl;
	for (int dropPosition = 0; dropPosition <= 4; dropPosition++)
	{
		cout << dropPosition<<"\t\t"<<plinkoSimulator.run(dropPosition,10000)<<endl;
	}
	
	return 0;
}