#include "Storage.h"

class �ashbox{
private:
	Storage* Goods;
public:
	�ashbox();
	~�ashbox();
	Storage& operator[](const int tmp);
	string Scan();
	int FindItem(string s);
	void discription(int i);
	void SetT(Storage tmp[]);
	void PrintChek();
	void DeleteItem(string s);
	void AddItem(string s);
};