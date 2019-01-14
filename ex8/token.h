#pragma once

class Token
{
public:
	virtual float getNumber() = 0;
	virtual char getOperator() = 0;
};

class Operator : public Token
{
private:
	char operation;

public:
	Operator(char);
	char getOperator();
	float getNumber();	//dummy function
};

class Number : public Token
{
private:
	float number;

public:
	Number(float);
	float getNumber();
	char getOperator();	//dummy function
};