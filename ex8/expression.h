#pragma once
#include <string>

#include "stack.h"


class expression
{
private:
	Stack s;
	char* pStr;
	int len;

public:
	expression(char* ptr)
	{
		pStr = ptr;
		len = strlen(pStr);
	}

	void parse();
	float solve();			//get result
};