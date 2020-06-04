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
	string name; // Имя клиента
	int cardNum; // Номер карты
	int pin; // Пин-код
	int sum; // Сумма на счету
public:
	Client(); // Конструктор по умолчанию
	Client(string _name, int _cardNum, int _pin, int _sum); // Инициализатор
	~Client(); // Деструктор
	string getName() { return name; }
	int getCardNum() { return cardNum; }
	int getPin() { return pin; }
	int getSum() { return sum; }
	void setName(string _name) { name = _name; }
	void setCardNum(int _cardNum) { cardNum = _cardNum; }
	void setPin(int _pin) { pin = _pin; }
	void setSum(int _sum) { sum = _sum; }

	Client& operator=(const Client& client);  // Перегрузка операции присваивания
	friend istream& operator>>(istream& in, Client& client); // Ввод в поток
	friend ostream& operator<<(ostream& out, const Client& client); // Вывод в поток
};