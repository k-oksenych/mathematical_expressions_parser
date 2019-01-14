#include <iostream>

#include "token.h"

using namespace std;

Operator::Operator(char ch)
{
	operation = ch;
}

char Operator::getOperator()
{
	return operation;
}

float Operator::getNumber()
{
	return 0.0;
}

Number::Number(float f)
{
	number = f;
}

char Number::getOperator()
{
	return '0';
}

float Number::getNumber()
{
	return number;
}