#include <iostream>
#include <math.h>
#include "Header.h"

using namespace std;

int main()
{
	cout << "Choose Complex or Standart type by pressing:" << endl;
	cout << "0-Standart" << endl;
	cout << "1-Complex" << endl;

	int choise;
	cin >> choise;

	if (choise==0)
	{
		int a1, a2, b1, b2;

		fraction* dr1 = new fraction();

		fraction* dr2 = new fraction();

		do

		{

			cout << "Enter the numerator first fraction" << endl;

			cin >> a1;

			if (a1 == 0)

				cout << "Enter a number!=0" << endl;

		} while (a1 == 0);

		do

		{

			cout << "Enter the denominator first fraction" << endl;

			cin >> b1;

			if (b1 == 0)

				cout << "Enter a number!=0" << endl;

		} while (b1 == 0);

		do

		{

			cout << "Enter the numerator second fraction" << endl;

			cin >> a2;

			if (a2 == 0)

				cout << "Enter a number!=0" << endl;

		} while (a2 == 0);

		do

		{

			cout << "Enter the denominator second fraction" << endl;

			cin >> b2;

			if (b2 == 0)

				cout << "Enter a number!=0" << endl;

		} while (b2 == 0);

		dr1->SetCH(a1);

		dr1->SetZN(b1);

		dr2->SetCH(a2);

		dr2->SetZN(b2);

		cout << endl;

		cout << *dr1 / *dr2 << endl;

		cout << *dr1 * *dr2 << endl;

		cout << *dr1 + *dr2 << endl;

		cout << *dr1 - *dr2 << endl;

	}
	else
	{
		int a, b;

		fraction* c1 = new fraction();
		fraction* c2 = new fraction();

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

		cout << "Complex count is: " << a<< "+"<< b << "*i" << endl;
		
	}
}