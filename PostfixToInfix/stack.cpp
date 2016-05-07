#include <iostream>
#include "stack.h"

////////////////////////////////////////////////////////////////////////
// Function Name:  stack
// Precondition: State of stack has not been initialize.
// Postcondition:  State has been initialize
// Description:  Default constructor that initializes top to 0
////////////////////////////////////////////////////////////////////////

stack::stack()
{
	cout <<"Default Constructor Invoked\n";
	top = 0;
}

////////////////////////////////////////////////////////////////////////
// Function Name:  ~stack
// Precondition:  Dynamic memory state allocated for stack 
// Postcondition: Dynamic memory has been de-allocated
// Description:  Destructor of the class which de-allocates dynamic memory
//               allocated by operator new
////////////////////////////////////////////////////////////////////////
stack::~stack()
{
	cout <<"Destructor Invoked\n";
	stack_node *temp;

	while(top!=0)
	{
		temp = top;
		top = top->next;
		delete temp;
	}
}

////////////////////////////////////////////////////////////////////////
// Function Name:  push
// Precondition:  string has not been pushed into the stack
// Postcondition: string has pushed into stack
// Description:  push function which inserts string into the stack
////////////////////////////////////////////////////////////////////////

void stack::push(string data)
{
   stack_node *temp;
   temp = new stack_node;
   temp->data = data;
   temp->next = (top != 0) ? top : 0;
   top = temp;
}

////////////////////////////////////////////////////////////////////////
// Function Name:  pop
// Precondition:  string has not been popped from stack and result is has
// not returned been returned.
// Postcondition: string has popped from stack and returned result.
// Description:  pop function which pops string from the stack and returns
// results.
////////////////////////////////////////////////////////////////////////

string stack::pop()
{
	stack_node *temp;

	if(top == 0)
	{
		return "\0";
	}

	temp = top;
	string result = temp -> data;

	if (top != 0)
	{
		temp = top;
		top = top->next;
		delete temp;
	}

	return result;
}
