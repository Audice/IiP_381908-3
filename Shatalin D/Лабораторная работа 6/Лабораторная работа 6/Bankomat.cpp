#include "Bankomat.h"

// �������������
Bankomat::Bankomat(const char* fileName)
{
	pc = new ProcCenter(fileName);
	casCount = 6;
	cassette = new int[casCount];
	max = 2000;
	double percent = 0.8; // ��������� �������� ��������
	for (int i = 0; i < casCount; i++)
		cassette[i] = max * percent;

}

// ����������
Bankomat::~Bankomat()
{
	delete[] cassette;
	casCount = 0;
	delete pc;
}

// ������� ����� �������
Client Bankomat::getCard(int _cardNumber, int _pin)
{
	Client cl;
	for (int i = 0; i < pc->getCount(); i++)
		if (_cardNumber == pc->getClient(i).getCardNum())
			cl = CheckPin(_cardNumber, _pin);
		else throw ExBankomat(noCard);
	return cl;;
}

// �������� ���-����
Client Bankomat::CheckPin(int _cardNum, int _pin)
{
	Client cl = findClient(_cardNum);
	if (_pin == cl.getPin())
		return cl;
	else throw ExBankomat(wrongPin);
}


// ����� ������� �� ������ �����
Client Bankomat::findClient(int _cardNum)
{
	for (int i = 0; i < pc->getCount(); i++)
		if (_cardNum == pc->getClient(i).getCardNum())
			return pc->getClient(i);
		else throw ExBankomat(noCard);
}

// ���� �������
int Bankomat::bankAccount(Client& cl)
{
	return cl.getSum();
}

// ������ ������� ��������
void Bankomat::getNal(Bankomat& b, Client& cl, int s)
{
	if (s <= cl.getSum())
	{
		int sum = s;
		while (sum / 5000 != 0)
		{
			if (b.cassette[0] != 0)
			{
				b.cassette[0] -= 1;
				sum = sum % 5000;
			}
		}
		while (sum / 2000 != 0)
		{
			if (b.cassette[1] != 0)
			{
				b.cassette[1] -= 1;
				sum = sum % 2000;
			}
		}
		while (sum / 1000 != 0)
		{
			if (b.cassette[2] != 0)
			{
				b.cassette[2] -= 1;
				sum = sum % 1000;
			}
		}
		while (sum / 500 != 0)
		{
			if (b.cassette[3] != 0)
			{
				b.cassette[3] -= 1;
				sum = sum % 500;
			}
		}
		while (sum / 200 != 0)
		{
			if (b.cassette[4] != 0)
			{
				b.cassette[4] -= 1;
				sum = sum % 200;
			}
		}
		while (sum / 100 != 0)
		{
			if (b.cassette[5] != 0)
			{
				b.cassette[5] -= 1;
				sum = sum % 100;
			}
		}
		if (sum == 0)
			cl.setSum(cl.getSum() - s);
		else throw ExBankomat(wrongM);
	}
	else throw ExBankomat(noMoney);
}

// ������� ��������
void Bankomat::setNal(Bankomat& b, Client& cl, int s)
{
	int sum = s;
	while (sum / 5000 != 0 && b.cassette[0] != max)
	{
		if (b.cassette[0] != 0)
		{
			b.cassette[0] += 1;
			sum = sum % 5000;
		}
	}
	while (sum / 2000 != 0 && b.cassette[1] != max)
	{
		if (b.cassette[1] != 0)
		{
			b.cassette[1] += 1;
			sum = sum % 2000;
		}
	}
	while (sum / 1000 != 0 && b.cassette[2] != max)
	{
		if (b.cassette[2] != 0)
		{
			b.cassette[2] += 1;
			sum = sum % 1000;
		}
	}
	while (sum / 500 != 0 && b.cassette[3] != max)
	{
		if (b.cassette[3] != 0)
		{
			b.cassette[3] += 1;
			sum = sum % 500;
		}
	}
	while (sum / 200 != 0 && b.cassette[4] != max)
	{
		if (b.cassette[4] != 0)
		{
			b.cassette[4] += 1;
			sum = sum % 200;
		}
	}
	while (sum / 100 != 0 && b.cassette[5] != max)
	{
		if (b.cassette[5] != 0)
		{
			b.cassette[5] += 1;
			sum = sum % 100;
		}
	}
	if (sum == 0)
		cl.setSum(cl.getSum() + s);
	else throw ExBankomat(wrongM);
}