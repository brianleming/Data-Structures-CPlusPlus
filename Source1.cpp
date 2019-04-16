#include "MyStack.h"
#include <iostream>
using namespace std;
int main()
{

	stackType<string>stack1(9);
	
	stack1.push("Please?");
	stack1.push("Assignment");
	stack1.push("This");
	stack1.push("On");
	stack1.push("A+");
	stack1.push("An");
	stack1.push("Have");
	stack1.push("I");
	stack1.push("May");

	for (int i = 0; i < 9; i++)
	{
	cout << stack1.top() << " ";
	stack1.pop();
	}
	
	cout << endl;
return 0;
}
