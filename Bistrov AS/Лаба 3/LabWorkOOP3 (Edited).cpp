#include <iostream>
#include <math.h>
#include "Header.h"   

using namespace std;

int main()
{
	int a1, b1;

	Load a;

	do

	{

		cout << "Enter first count" << endl;

		cin >> a1;

		if (a1 == 0)

			cout << "Enter a number!=0" << endl;

	} while (a1 == 0);

	a.SetCompA(a1);

	do

	{

		cout << "Enter second count" << endl;

		cin >> b1;

		if (b1 == 0)

			cout << "Enter a number!=0" << endl;

	} while (b1 == 0);

	a.SetCompB(b1);
	a.output();
};