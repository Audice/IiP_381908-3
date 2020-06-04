#include "ProcCenter.h"

// Инициализатор
ProcCenter::ProcCenter(const char* fileName)
{
	bufSize = 100;
	client = new Client[bufSize];
	ifstream fin;
	fin.open(fileName);
	fin >> *this;
	fin.close();
}

// Деструкто
ProcCenter::~ProcCenter()
{
	delete[] client;
	client = 0;
	bufSize = 0;
	count = 0;
}

// Увеличение размера буфера
void ProcCenter::newBuf()
{
	Client* newClient;
	newClient = new Client[2 * bufSize];
	for (int i = 0; i < count; i++)
		newClient[i] = client[i];
	delete[] client;
	client = newClient;
}

// Добавление нового клиента
void ProcCenter::newClient(const Client& cl, const char* fileName)
{
	if (count == bufSize)
		newBuf();
	client[count] = cl;
	count++;
	ofstream fout;
	fout.open(fileName);
	fout << *this;
	fout.close();
}

// Перегрузка операции индексации
Client& ProcCenter::operator[](int i) {
	if (i >= 0 && i < count)
		return client[i];
}

// Вывод в поток
ostream& operator<<(ostream& out, const ProcCenter& list)
{
	out << list.count;
	out << endl;
	for (int i = 0; i < list.count; i++)
	{
		out << list.client[i].getName() << endl;
		out << list.client[i].getCardNum() << endl;
		out << list.client[i].getPin() << endl;
		out << list.client[i].getSum() << endl;
		out << endl;
	}
	return out;
}

// Ввод в поток 
istream& operator>>(istream& in, ProcCenter& list)
{
	in >> list.count;
	string n1 = "", n2 = "", n3 = "";
	int cardNum, pin, sum;
	for (int i = 0; i < list.count; i++)
	{
		in >> n1 >> n2 >> n3;
		list.client[i].setName(n1 + " " + n2 + " " + n3);
		in >> cardNum >> pin >> sum;
		list.client[i].setCardNum(cardNum);
		list.client[i].setPin(pin);
		list.client[i].setSum(sum);
	}
	return in;
}
