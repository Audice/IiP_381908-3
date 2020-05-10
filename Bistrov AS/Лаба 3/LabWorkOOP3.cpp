#include <iostream>
#include <math.h>
#include "Header.h"

using namespace std;

int main()
{
	int a, b;

	Load* c1 = new Load();
	Load* c2 = new Load();

	do

	{

		cout << "Enter first count" << endl;

		cin >> a;

		if (a == 0)

			cout << "Enter a number!=0" << endl;

	} while (a == 0);

	do

	{

		cout << "Enter second count" << endl;

		cin >> b;

		if (b == 0)

			cout << "Enter a number!=0" << endl;

	} while (b == 0);

	c1->SetCompA(a);
	c2->SetCompB(b);

	void output(int a, int b);

	cout << "Complex count is: " << a << "+" << b << "*i" << endl;


}

