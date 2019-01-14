#include <iostream>

#include "expression.h"
#include "token.h"

using namespace std;

int main()
{
	char ans;			//'y' or 'n'
	char st[100];	//string for parse

	cout << "Enter arithmetic expression" << endl
		<< "Use spaces between numbers and operations" << endl
		<< "You can use floating point numbers" << endl
		<< "Please don't use parentheses" << endl << endl;

	do
	{
		cout << "Expression: ";
		cin.getline(st, 100);
		expression* eptr = new expression(st);
		eptr->parse();
		cout << "Result: "
			<< eptr->solve() << endl;
		delete eptr;
		cout << endl << "One more expression (y/n)? ";
		cin >> ans;
	} while (ans == 'y');

	return 0;
}