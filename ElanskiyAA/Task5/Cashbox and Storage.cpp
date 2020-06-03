#include "Cashbox.h"

int main() {
	setlocale(LC_CTYPE, "rus");
	Сashbox Kass;
	Storage* chek = new Storage[4],
	t1("0868", "OverWatch", 3500, 0.1),
	t2("0010", "Call of Duty", 4000, 0.2),
	t3("0228", "CS: GO", 1200, 0.15),
	t4("1568", "Dota 2", 25000, 0.05);
	chek[0] = t1;
	chek[1] = t2;
	chek[2] = t3;
	chek[3] = t4;
	bool ete = true, etee = true;
	int ind = 4, num, choice;
	string s;
	Kass.SetT(chek);
	system("cls");
	for (int i = 0; i < ind; i++)
	{
		Kass.discription(i);
	}
	do {
		do {
			system("cls");
			Kass.PrintChek();
			for (int i = 0; i < ind; i++)
			{
				Kass.discription(i);
			}
			cout << endl;
			cout << "1. Купить\n2. Выход" << endl;
			cin >> choice;
		} while (choice > 2 && choice < 1);
		switch (choice) {
		case 1: {
			do {
				do {
					etee = true;
					system("cls");
					Kass.PrintChek();
					for (int i = 0; i < ind; i++)
					{
						Kass.discription(i);
					}
					cout << endl << "1. Добавить в покупки\n2. Удолить из покупок\n3. Выход" << endl;
					cin >> choice;
				} while (choice > 3 && choice < 1);
				switch (choice) {
				case 1: {
					s = Kass.Scan();
					num = Kass.FindItem(s);
					if (num != -1)
						Kass.AddItem(s);
					else
					{
						system("pause");
					}
					system("cls");
					Kass.PrintChek();
					for (int i = 0; i < ind; i++)
					{
						Kass.discription(i);
					}
					cout << endl;
				}break;
				case 2: {
					s = Kass.Scan();
					num = Kass.FindItem(s);
					if (num != -1)
						Kass.DeleteItem(s);
					else
					{
						system("pause");
					}
					system("cls");
					Kass.PrintChek();
					for (int i = 0; i < ind; i++)
					{
						Kass.discription(i);
					}
					cout << endl;
				}break;
				case 3: {
					etee = false;
				}break;
				}
			} while (etee == true);
		} break;
		case 2: {
			ete = false;
			system("cls");
			Kass.PrintChek();
			system("pause");
		} break;
		}
	} while (ete == true);
}