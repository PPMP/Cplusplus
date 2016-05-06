#include "Patron.h"

bool compareByPatronName(Patron & b1, Patron & b2)
{
	return b1.name<b2.name;
}