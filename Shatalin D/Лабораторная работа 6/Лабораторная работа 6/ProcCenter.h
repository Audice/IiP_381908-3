#pragma once
#include "Client.h"

class ProcCenter
{
private:
	Client* client; // ������ ��������
	int count; // ���������� ��������
	int bufSize; // ������ ������
	void newBuf(); // ���������� ������� ������
public:
	ProcCenter(const char* fileName); // �������������
	~ProcCenter(); // ����������
	int getCount() { return count; }
	Client getClient(int i) { return client[i]; }
	void newClient(const Client& cl, const char* fileName); // ���������� ������ ������� 

	Client& operator[](int i); // ���������� �������� ����������
	friend ostream& operator<<(ostream& out, const ProcCenter& list); // ����� � �����
	friend istream& operator>>(istream& in, ProcCenter& list); // ���� � �����
};

