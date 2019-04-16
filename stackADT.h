#pragma once
#include <iostream>

using namespace std;
template <class Type>
class stackADT
{
public:
	virtual void initializeStack() = 0;   // Method to initialize the stack
	virtual bool isEmptyStack() const = 0;
	virtual bool isFullStack() const = 0;
	virtual void push(const Type& newItem) = 0;
	virtual Type top() const = 0; // to return the top element of the stack.
	virtual void pop() = 0;
};
