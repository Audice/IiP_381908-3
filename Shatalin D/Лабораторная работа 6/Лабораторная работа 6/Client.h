#pragma once
#include <clocale>
#include <iostream>
#include <cmath>
#include <fstream>
#include <string>
using namespace std;

class Client
{
private:
	string name; // ��� �������
	int cardNum; // ����� �����
	int pin; // ���-���
	int sum; // ����� �� �����
public:
	Client(); // ����������� �� ���������
	Client(string _name, int _cardNum, int _pin, int _sum); // �������������
	~Client(); // ����������
	string getName() { return name; }
	int getCardNum() { return cardNum; }
	int getPin() { return pin; }
	int getSum() { return sum; }
	void setName(string _name) { name = _name; }
	void setCardNum(int _cardNum) { cardNum = _cardNum; }
	void setPin(int _pin) { pin = _pin; }
	void setSum(int _sum) { sum = _sum; }

	Client& operator=(const Client& client);  // ���������� �������� ������������
	friend istream& operator>>(istream& in, Client& client); // ���� � �����
	friend ostream& operator<<(ostream& out, const Client& client); // ����� � �����
};