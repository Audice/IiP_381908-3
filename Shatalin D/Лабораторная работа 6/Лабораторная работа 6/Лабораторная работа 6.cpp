#include "Bankomat.h"

int main()
{
	setlocale(LC_ALL, "Russian");
	int card, pin;
	Bankomat bankomat("list.txt");
	Client client;
	int count = 0;
	int num;
	int sum;
	int s;
	int flag = 1, fl = 1, f = 1, k = 1;
	while (fl)
	{
		try
		{
			cout << "Введите номер карты: " << endl;
			cin >> card;
			fl = 0;
			client = bankomat.findClient(card);
			while (f)
			{
				try
				{
					cout << "Введите пин-код: " << endl;
					cin >> pin;
					f = 0;
					client = bankomat.getCard(card, pin);
				}
				catch (ExBankomat ex)
				{
					if (ex.type == wrongPin)
					{
						cout << "Неверный пин-код." << endl;
						f = 1;
						count++;
						if (count >= 3)
						{
							cout << "Карта заблокирована." << endl;
							fl = 0;
							f = 0;
							k = 0;
						}
					}
				}
			}
		}
		catch (ExBankomat ex)
		{
			if (ex.type == noCard)
			{
				cout << "Неверный номер карты." << endl;
				fl = 1;
				f = 1;
			}
		}
	}

	if (k != 0)
	{
		while (flag)
		{
			try
			{
				cout << "Выберете дальнейшее действие:" << endl;
				cout << endl;
				cout << "1. Выдать наличные." << endl;
				cout << "2. Принять наличные." << endl;
				cout << "3. Вернуть карту." << endl;
				cin >> num;
				switch (num)
				{
				case 1:
				{
					cout << "Введите сумму: ";
					cin >> s;
					bankomat.getNal(bankomat, client, s);
					sum = bankomat.bankAccount(client);
					cout << "Сумма на счете: " << sum << endl;
					break;
				}
				case 2:
				{
					cout << "Введите сумму: ";
					cin >> s;
					bankomat.setNal(bankomat, client, s);
					sum = bankomat.bankAccount(client);
					cout << "Сумма на счете: " << sum << endl;
					break;
				}
				case 3:
				{
					flag = 0;
					break;
				}
				}
			}
			catch (ExBankomat ex)
			{
				switch (ex.type)
				{
				case (noMoney):
				{
					cout << "На карте не достаточно средств." << endl;
					break;
				}
				case (wrongM):
				{
					cout << "Банкомат не может выдать данную сумму." << endl;
					break;
				}
				}
			}
		}
	}

	return 0;
}
