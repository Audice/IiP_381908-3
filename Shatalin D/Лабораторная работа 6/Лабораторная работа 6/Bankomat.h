#pragma once
#include "ProcCenter.h"

enum ExceptionType { noCard, wrongPin, noMoney, wrongM };
struct ExBankomat {
	ExceptionType type;
	ExBankomat(ExceptionType _type) {
		type = _type;
	}
};

class Bankomat
{
private:
	ProcCenter* pc; // ���� ��������
	int casCount; // ���������� ������
	int* cassette;// ������, �������� ���������� ����� ������� ��������
	int max; // ������������ ���������� �����
public:
	Bankomat(const char* fileName); // �������������
	~Bankomat(); // ����������
	Client getCard(int _cardNum, int _pin); // ������� ����� �������
	Client findClient(int _cardNum); // ����� ������� �� ������ �����
	Client CheckPin(int _cardNum, int _pin); // ������� ���-����
	int bankAccount(Client& cl); // ���� �������
	void getNal(Bankomat& b, Client& cl, int s); // ������ ������� ��������
	void setNal(Bankomat& b, Client& cl, int s); // ������� ��������
};