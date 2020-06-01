#include "Client.h"

// ����������� �� ���������
Client::Client()
{
	name = "";
	cardNum = 0;
	pin = 0;
	sum = 0;
}

// �������������
Client::Client(string _name, int _cardNum, int _pin, int _sum)
{
	name = _name;
	cardNum = _cardNum;
	pin = _pin;
	sum = _sum;
}

// ����������
Client::~Client()
{
	name = "";
	cardNum = 0;
	pin = 0;
	sum = 0;
}

// ���������� �������� ������������
Client& Client::operator=(const Client& client)
{
	name = client.name;
	cardNum = client.cardNum;
	pin = client.pin;
	sum = client.sum;
	return *this;
}

// ����� � �����
ostream& operator<<(ostream& out, const Client& client)
{
	out << client.name << endl;
	out << client.cardNum << endl;
	out << client.pin << endl;
	out << client.sum << endl;
	return out;
}

// ���� � ����� 
istream& operator>>(istream& in, Client& client)
{
	string n1 = "";
	string n2 = "";
	string n3 = "";
	in >> n1 >> n2 >> n3;
	client.name = n1 + " " + n2 + " " + n3;
	in >> client.cardNum >> client.pin >> client.sum;
	return in;
}