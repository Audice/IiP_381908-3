#include <string>
#include <iostream>

using namespace std;

class Storage{
private:
	string QR;
	string product;
	int cost;
	int quantity;
	double discount;
public:
	Storage();
	~Storage();
	Storage(string _product, string _QR, int _cost, double _discount);
	Storage(const Storage& tmp);
	Storage& operator=(Storage& tmp);
	void SetQR(string tmp);
	void SetProduct(string tmp);
	void SetCost(int tmp);
	void SetDiscount(double tmp);
	void SetQuantity(int tmp);
	string GetQR();
	string GetProduct();
	int GetCost();
	int GetQuantity();
	double GetDiscount();
};