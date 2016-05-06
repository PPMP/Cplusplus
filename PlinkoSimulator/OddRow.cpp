#include "OddRow.h"
#include <stdlib.h>


//odd left is - 1 and right is just returning the number

int OddRow::passThru(int pegNumber)
{
	int determinePosition;
	determinePosition = rand()%2;
	if(determinePosition == 0)
	{
		return pegNumber - 1;
	}
	else
	{
		return pegNumber;
	}
}