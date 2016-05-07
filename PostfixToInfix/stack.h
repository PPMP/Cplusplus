#include <string>
using namespace std;

typedef string stack_element;

////////////////////////////////////////////////////////////////////////
// Class Name:  stack_node
// Precondition: a string data and stack_node next has not been declared
// Postcondition: string data and stack_node next is declared
// Description:  declares string symbol and stack_node next
////////////////////////////////////////////////////////////////////////

class stack_node
{
public:
	stack_element data;
	stack_node *next;
};

////////////////////////////////////////////////////////////////////////
// Class Name:  stack
// Precondition: function prototypes and data types for stack has not been declared
// Postcondition: function prototypes and data types for stack has been declared
// Description: declares function prototypes and data types for stack
////////////////////////////////////////////////////////////////////////

class stack
{  
   public:
	stack();
	~stack();
	void push(string data);
	string pop();

	private:
	stack_node *top;
};

