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
	ProcCenter* pc; // База клиентов
	int casCount; // Количество кассет
	int* cassette;// Массив, хранящий количество купюр разного номинала
	int max; // Максимальное количество купюр
public:
	Bankomat(const char* fileName); // Инициализатор
	~Bankomat(); // Деструктор
	Client getCard(int _cardNum, int _pin); // Принять карту клиента
	Client findClient(int _cardNum); // Поиск клиента по номеру карты
	Client CheckPin(int _cardNum, int _pin); // Провера пин-кода
	int bankAccount(Client& cl); // Счет клиента
	void getNal(Bankomat& b, Client& cl, int s); // Выдача клиенту наличных
	void setNal(Bankomat& b, Client& cl, int s); // Принять наличные
};