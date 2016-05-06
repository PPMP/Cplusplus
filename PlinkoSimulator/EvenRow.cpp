#include "EvenRow.h"
#include <stdlib.h>

//left just returns number and right + 1

int EvenRow::passThru(int pegNumber)
{
	int determinePosition;
	determinePosition = rand()%2;

	//edge check
	if(pegNumber == -1)
	{ 
		return 0;
	}
	else if(pegNumber == 8)
	{
		return 8;
	}

	//left or right check
	if(determinePosition == 0)
	{
		return pegNumber;
	}
	else
	{
		return pegNumber + 1;
	}
}