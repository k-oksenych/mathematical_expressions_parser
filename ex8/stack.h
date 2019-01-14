#pragma once

#include "token.h"

class Stack
{
private:
	Token * atoken[100];	//contains types Operator* and Number*
	int top;				//amount of data saved

public:
	Stack()
	{
		top = 0;
	}

	void push(Token* t)
	{
		atoken[++top] = t;
	}

	Token* pop()
	{
		return atoken[top--];
	}

	int gettop()			//number of elements
	{
		return top;
	}
};