#include <iostream>
#include <string>
#include <locale.h>
#include "windows.h"
#include"complex.h"
#include "fraction.h"
using namespace std;
int c;


int  NUMFRICTION()
{
	int a;
	if (c == 2)
	{
		Sleep(100);
		cout << "�";
		Sleep(100);
		cout << "�";
		Sleep(100);
		cout << "�";
		Sleep(100);
		cout << "�";
		Sleep(100);
		cout << "�";
		Sleep(100);
		cout << "�";
		Sleep(100);
		cout << "�";
		Sleep(100);
		cout << " ";
		Sleep(100);
		cout << "�";
		Sleep(100);
		cout << "�";
		Sleep(100);
		cout << "�";
		Sleep(500);
		cout << ".";
		Sleep(600);
		cout << ".";
		Sleep(600);
		cout << ".";
		Sleep(600);
		cout << ".";
		Sleep(600);
		cout << ". " << endl;
	}
	do
	{
		if (c == 2)
		{
			cout << "������ ���� ������ ���� ���������� ������" << endl;
		}
		else

		{
			cout << "������� ���������� ������ " << endl;
		}
		cin >> a;
		if (a < 2)
		{
			if (c == 2)
			{
				cout << "�� �� ������ ���� ." << a << " ��� ����� ����� ! ������� ��������� ���� � ������� �������� � 2 ������ " << endl;
				cout << "�������� ENTER ����� ����������� " << endl;
				getchar();
				getchar();
			}
			else
			{
				cout << "������� ��������� �����" << endl;
			}
		}

	} while (a < 2);
	return a;
}
void USER()
{
	int SIZE, wi, fu;
	SIZE = NUMFRICTION();
	Fraction* num = new Fraction[SIZE];
	int* ch = new int[SIZE];
	int* z = new int[SIZE];
	for (int i = 0; i < SIZE; i++)
	{
		cout << "���������� ���� ����� �" << i + 1 << endl;
		cout << "������� ��������� �����  " << endl;
		cin >> ch[i];
		cout << "������� �����������  ����� " << endl;
		cin >> z[i];
		if (z[i] == 0)
		{
			cout << "�� ���� ������ ������" << endl;
			return;
		}
		if (ch[i] < 0 && z[i] < 0)
		{
			ch[i] = ch[i] * (-1);
			z[i] = z[i] * (-1);
		}
		else
		{
			if (z[i] < 0)
			{
				ch[i] = ch[i] * (-1);
				z[i] = z[i] * (-1);
			}
		}
	}
	for (int i = 0; i < SIZE; i++)
	{
		num[i].setNumerator(ch[i]);
		num[i].setDenominator(z[i]);
	}
	do
	{
		cout << "1-����� " << endl << "2-��������"<<endl;
		cin >> fu;
		if (fu == 1)
		{

			for (int i = 0; i < SIZE; i++)
			{
				num[i].Conversion(i);
			}
			do
			{
				cout << "������� ENTER ����� ����������" << endl;
				getchar();
				getchar();
				cout << endl << "1 - �������� ������" << endl;
				Sleep(300);
				cout << "2-��������� ������ " << endl;
				Sleep(300);
				cout << "3-��������� ������ " << endl;
				Sleep(300);
				cout << "4-������� ������ " << endl;
				cin >> wi;
				switch (wi)
				{
				case 1:num->Sum(ch, z, SIZE); break;
				case 2:num->Razn(ch, z, SIZE); break;
				case 3:	num->Multiplication(ch, z, SIZE); break;
				case 4:num->Division(ch, z, SIZE); break;
				}

			} while (wi != 0);
		}
		if (fu == 2)
		{
			Complex a(num[0],num[1]), b(num[2], num[3]),c;
			a.printi();
			b.printi();
			int d;
			do
			{
				cout << "1-������������ 1 ���������\n2 - ����� \n3-��������\n4-��������� \n5-������� \n6-��������� \n7- +=,-=,*=,/="<<endl;
				cin >> d;
				switch (d)
				{
				case 1:c = a; c.printi(); break;
				case 2:c = a+b; c.printi(); a.printi(); b.printi(); break;
				case 3:c = a-b; c.printi(); break;
				case 4:c = a*b; c.printi(); break;
				case 5:c = a / b; c.printi(); break;
				case 6:b == a; break;
				case 7:a += b; a.printi(); break;
				case 8:a -= b; a.printi(); break;
				case 9:a *= b; a.printi(); break;
				case 10:a /= b; a.printi(); break;
				case 11:a != b; break;
				case 12:c = a + 2; c.printi(); break;
				case 13:c = a - 2; c.printi(); break;
				case 14:c = a * 2; c.printi(); break;
				case 15:c = a / 2; c.printi(); break;
				case 16:++a; cout << a;

				default:
					break;
				}
			} while (d == 0);
		}
	} while (fu != 0);
}
int main()
{
	Fraction g(6,9), gg(4,2);
	Complex F(g, gg), HE(g, gg);
	++F;
	cout << F;
	setlocale(LC_ALL, "Rus");

	do
	{
		cout << "������� ������" << endl << "1-�������" << endl << "2-�����������" << endl;
		cin >> c;
		USER();
	} while (c == 0);
}