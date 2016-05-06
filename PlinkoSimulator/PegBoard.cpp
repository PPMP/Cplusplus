#include "PegBoard.h"


double PegBoard::dropOnce(int dropPosition)
{
	//convert drop position to which peg in first row will be hit

	int currentPuckPosition = 4 - dropPosition;

	currentPuckPosition = row1.passThru(currentPuckPosition);

	currentPuckPosition = row2.passThru(currentPuckPosition);

	currentPuckPosition = row3.passThru(currentPuckPosition);

	currentPuckPosition = row4.passThru(currentPuckPosition);

	currentPuckPosition = row5.passThru(currentPuckPosition);

	currentPuckPosition = row6.passThru(currentPuckPosition);

	currentPuckPosition = row7.passThru(currentPuckPosition);

	currentPuckPosition = row8.passThru(currentPuckPosition);

	currentPuckPosition = row9.passThru(currentPuckPosition);

	currentPuckPosition = row10.passThru(currentPuckPosition);

	return bottomSlot.convertSlotToDollars(currentPuckPosition);

}





