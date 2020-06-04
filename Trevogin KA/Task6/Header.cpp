#pragma warning(disable : 4996)
#include <conio.h>
#include "Header.h"
#include "Header1.h"
#include "Header2.h"
#include "windows.h"

int Pole::otrisovka(int x, int y, int nap,int facx,int facy)
{
	aple ybl;
	zmei* tul = new zmei[200];
	int la = 0,but,_long=4;
	string b = "^>v<o@";
	char* e=new char[facy] ;
	char* re = new char[facy];
	ybl.random(facx,facy);
	for (int i = 1; i < _long; i++)
	{
		int d;
		tul[i].set_x(x+i);
		d= tul[i].get_x();
	}
	string* a = new string[facx];
	for (int i = 0; i < facy; i++)
	{
		if (i==0 || i==facy-1)
		{
			re[i] = ' ';
		}
		else
		{
			re[i] = '_';
		}
		a[0] = a[0] + re[i];
	}
	for (int i = 1; i <facx-1; i++)
	{
		for (int j = 0; j < facy; j++)
		{
			if (j==0 ||j==facy-1)
			{
				e[j] = '|';
			}
			else
			{
				e[j] = ' ';
			}
			a[i]+= e[j];
		}
		
	}
	for (int i = 0; i < facy - 1; i++)
	{
		if (i == 0)
		{
			re[i] = ' ';
		}
		else
		{
			re[i] = '=';
		}
		a[facx-1] += re[i];
	}
	for (int i = 0; i < _long; i++)
	{
		if (i == 0)
		{
			a[x].replace(y, 1, b, nap, 1);
		}
		else
		{
			a[tul[i].get_x()].replace(y, 1, b, 4, 1);

		}
	}
	a[ybl.get_x()].replace(ybl.get_y(), 1, b, 5, 1);
	/*=====DO=====*/
	do
	{
			system("cls");
			cout << "Shetchik:"<<la<<endl;
			for (int i = 0; i < facx; i++)
			{
				cout << a[i] << endl;
			}
			if (tul[0].get_x() == ybl.get_x() && tul[0].get_y() == ybl.get_y())
			{
				int k;
				_long++;
				la++;
				ybl.random(facx,facy);
				do
				{
					for (int i = 0; i < _long; i++)
					{
						if (tul[i].get_x() == ybl.get_x() && tul[i].get_y() == ybl.get_y())
						{
							ybl.random(facx, facy);
							k = 1;
						}
						else
						{
							k = 0;
						}
					}
				} while (k==1);
			}
			for (int i = _long - 1; i > 0; i--)
			{
				int j;
				j = i - 1;
				tul[i].set_x(tul[j].get_x());
				tul[i].set_y(tul[j].get_y());
			}

			Sleep(500 - (la * 10));
			while (_kbhit())
			{
				getch();
				but = getch();
				switch (but)
				{
				case 72:nap = 0; break;
				case 80:nap = 2; break;
				case 75:nap = 3; break;
				case 77:nap = 1; break;
				}
			}
			if (nap == 0)
			{
				tul[0].set_x(tul[0].get_x() - 1);
			}
			else
			{
				if (nap == 1)
				{
					tul[0].set_y(tul[0].get_y() + 1);
				}
				else
				{
					if (nap == 2)
					{
						tul[0].set_x(tul[0].get_x() + 1);
					}
					else
					{
						if (nap == 3)
						{
							tul[0].set_y(tul[0].get_y() - 1);
						}
					}
				}
			}
			for (int i = 1; i < facx-1; i++)
			{
				a[i].replace(0, facy-1, e, 0, facy-1);
			}
			Sleep(500-(la*10));
			if (_kbhit())
			{
				getch();
				but = getch();
			}
			a[ybl.get_x()].replace(ybl.get_y(), 1, b, 5, 1);
			a[tul[0].get_x()].replace(tul[0].get_y(), 1, b, nap, 1);
			for (int i = 1; i < _long; i++)
			{
				int s, ss;
				s = tul[i].get_x();
				ss = tul[i].get_y();
				a[tul[i].get_x()].replace(tul[i].get_y(), 1, b, 4, 1);

			}
			for (int i = 1; i < _long; i++)
			{
				if (tul[0].get_x() == tul[i].get_x() && tul[0].get_y() == tul[i].get_y())
				{
					return la;
				}
			}

	} while ((tul[0].get_x() >0) && (tul[0].get_y() > 0) && (tul[0].get_x() < facx-1) && (tul[0].get_y() < facy-1));
	return la;
}
