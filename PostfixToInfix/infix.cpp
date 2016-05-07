#include <iostream>
#include "stack.h"
#include <algorithm>
#include <cctype>
using namespace std;

int main()
{
   stack myStack;
   string postFix, inFix, leftOper, rightOper, expression, Ans;
   int errorCheck;

   do
   {
	  errorCheck = 0;

      cout << "Enter postfix expression with a space between each character: ";
      getline(cin, postFix);

      for(int i = 0; i < postFix.length(); i++)
      {
         string checkOper = postFix.substr(i, 1);

         if(checkOper == "+" || checkOper == "-" || checkOper == "*" || checkOper == "/")
         {
            rightOper = myStack.pop();

            if (rightOper == "\0")
            {
               cout << "Too many operators and not enough operands." << endl;
               errorCheck = 1;
               break;
            } 

            leftOper = myStack.pop();

            if (leftOper == "\0")
            {
               cout << "Too many operators and not enough operands." << endl;
               errorCheck = 1;
               break;
            } 

            expression = "(" + leftOper + " " + checkOper + " " + rightOper + ")";
            myStack.push(expression);

         } 
         else if (checkOper == " ") //Checks if there a space in the expression
         {
            continue;
         }
         else  
         {
            myStack.push(checkOper);
         }
      }

      if (!errorCheck)
      {
         inFix = myStack.pop();
         if (myStack.pop() == "\0")
         {
			inFix.erase(std::remove(inFix.begin(), inFix.end(), ' '), inFix.end());
            cout << "The infix expression is " << inFix << endl;
         }
         else
         {
            cout << "Too many operands and not enough operators." << endl;
            while(myStack.pop() != "\0");
         }
      } 

      cout << "Do you want to convert another postfix expression (Y/N) : ";
      cin >> Ans;
      getchar(); 
      cout << endl;
    }
    while(Ans == "Y" || Ans == "y");
 
    return 0;
}