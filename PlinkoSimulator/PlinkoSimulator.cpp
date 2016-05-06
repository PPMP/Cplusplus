#include "PlinkoSimulator.h"
#include "PegBoard.h"
#include <iostream>

using namespace std;


double PlinkoSimulator::run(int dropPostion, int numberOfRuns)
{
	PegBoard pegBoard;
	double total = 0.0;
	for (int i = 0; i < numberOfRuns; i++)
	{
		total += pegBoard.dropOnce(dropPostion);
	} 
	return (total / numberOfRuns);
}

