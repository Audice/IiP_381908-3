#pragma once
#include "Client.h"

class ProcCenter
{
private:
	Client* client; // Список клиентов
	int count; // Количество клиентов
	int bufSize; // Размер буфера
	void newBuf(); // Увеличение размера буфера
public:
	ProcCenter(const char* fileName); // Инициализатор
	~ProcCenter(); // Деструктор
	int getCount() { return count; }
	Client getClient(int i) { return client[i]; }
	void newClient(const Client& cl, const char* fileName); // Добавление нового клиента 

	Client& operator[](int i); // Перегрузка операции индексации
	friend ostream& operator<<(ostream& out, const ProcCenter& list); // Вывод в поток
	friend istream& operator>>(istream& in, ProcCenter& list); // Ввод в поток
};

