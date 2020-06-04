#include "Storage.h"

class Ñashbox{
private:
	Storage* Goods;
public:
	Ñashbox();
	~Ñashbox();
	Storage& operator[](const int tmp);
	string Scan();
	int FindItem(string s);
	void discription(int i);
	void SetT(Storage tmp[]);
	void PrintChek();
	void DeleteItem(string s);
	void AddItem(string s);
};