#include <iostream>
#include "Header.h"
#include "windows.h"
#include "Header1.h"
using namespace std;
int main()
{
	int facx, facy;
	cout << "visota\n";
	cin >> facx;
	cout << "shirina\n";
	cin >> facy;
	zmei c;
	Pole a;
	facx= a.otrisovka(c.get_x(), c.get_y(), c.get_orientation(),facx,facy);
	system("cls");
	cout << "Game Over \n"<<"Rez:"<<facx;
}