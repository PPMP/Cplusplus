#include "BottomSlot.h"
double BottomSlot::convertSlotToDollars(int current)
{ 
	//switch statement to convert to dollars
	switch(current)
	{
	case 0: 
		return 100.00;
		break;
	case 1: 
		return 500.00;
		break;
	case 2: 
		return 1000.00;
		break;
	case 3: 
		return 0;
		break;
	case 4: 
		return 10000.00;
		break;
	case 5: 
		return 0;
		break;
	case 6: 
		return 1000.00;
		break;
	case 7: 
		return 500.00;
		break;
	case 8: 
		return 100.00;
		break;
	default:
		break;
	}
}