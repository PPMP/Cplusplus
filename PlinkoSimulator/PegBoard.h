#pragma once
#include "BottomSlot.h"
#include "OddRow.h"
#include "EvenRow.h"

class PegBoard
{
public:
	
	double dropOnce(int dropPosition);

private:
	OddRow row1;
	EvenRow row2;
	OddRow row3;
	EvenRow row4;
	OddRow row5;
	EvenRow row6;
	OddRow row7;
	EvenRow row8;
	OddRow row9;
	EvenRow row10;
	BottomSlot bottomSlot;
};