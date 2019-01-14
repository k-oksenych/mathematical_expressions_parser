#include <iostream>

#include "expression.h"

using namespace std;

void expression::parse()
{
	char* value = new char[20];			//substring from our whole expression
	Token* lastval;
	Token* lastop;

	for (int i = 0; i < len;)
	{
		if (pStr[i] == ' ')
		{
			value[0] = '\0';
			++i;
		}

		int k = 0;

		while (pStr[i] != ' ' && i < len)	//get the substring
		{
			value[k] = pStr[i];
			++i;
			++k;
		}
		value[k] = '\0';

		if (value[0] >= '0' && value[0] <= '9')
		{
			Number* num = new Number(atof(value));

			s.push(num);
		}
		else if (value[0] == '+' || value[0] == '-' || value[0] == '*' || value[0] == '/')
		{
			if (s.gettop() == 1)
			{
				Operator* op = new Operator(value[0]);

				s.push(op);	
			}
			else
			{
				lastval = s.pop();
				lastop = s.pop();					

				if ((value[0] == '*' || value[0] == '/') && (lastop->getOperator() == '+' || lastop->getOperator() == '-'))
				{
					s.push(lastop);
					s.push(lastval);
				}
				else
				{
					char ch = lastop->getOperator();
					Number* n = new Number(0);

					switch (ch)
					{
					case '+': *n = s.pop()->getNumber() + lastval->getNumber(); break;
					case '-': *n = s.pop()->getNumber() - lastval->getNumber(); break;
					case '*': *n = s.pop()->getNumber() * lastval->getNumber(); break;
					case '/': *n = s.pop()->getNumber() / lastval->getNumber(); break;
					default: cout << "Unknown operator P" << endl; exit(1);
					}
					s.push(n);
				}

				Operator* o = new Operator(value[0]);
				s.push(o);
			}
		}
		else 
		{
			cout << "Unknown symbol" << endl;
			exit(1);
		}
	}
}


float expression::solve()
{
	Token* lastval;

	while (s.gettop() > 1)
	{
		lastval = s.pop();

		char ch = s.pop()->getOperator();
		Number* n = new Number(0);

		switch (ch)
		{
		case '+': *n = s.pop()->getNumber() + lastval->getNumber(); break;
		case '-': *n = s.pop()->getNumber() - lastval->getNumber(); break;
		case '*': *n = s.pop()->getNumber() * lastval->getNumber(); break;
		case '/': *n = s.pop()->getNumber() / lastval->getNumber(); break;
		default: cout << "Unknown operator O" << endl; exit(1);
		}
		s.push(n);
	}

	return s.pop()->getNumber(); //last operator in the stack is our result
}