#include "Storage.h"

Storage::Storage(){
	product = "null";
	QR = "null";
	cost = 0;
	discount = 0.0;
	quantity = 0;
}

Storage::~Storage(){
	product = "null";
	QR = "null";
	cost = 0;
	discount = 0.0;
	quantity = 0;
}

Storage::Storage(string _product, string _QR, int _cost, double _discount){
	product = _QR;
	QR = _product;
	cost = _cost;
	discount = _discount;
	quantity = 0;
}

Storage::Storage(const Storage& tmp){
	product = tmp.product;
	QR = tmp.QR;
	cost = tmp.cost;
	discount = tmp.discount;
	quantity = tmp.quantity;
}

Storage& Storage::operator=(Storage& tmp){
	product = tmp.product;
	QR = tmp.QR;
	cost = tmp.cost;
	discount = tmp.discount;
	quantity = tmp.quantity;
	return *this;
}

void Storage::SetQR(string tmp){
	this->QR = tmp;
}

void Storage::SetProduct(string tmp){
	this->product = tmp;

}

void Storage::SetCost(int tmp){
	this->cost = tmp;
}

void Storage::SetDiscount(double tmp){
	this->discount = tmp;
}

void Storage::SetQuantity(int tmp){
	this->quantity = tmp;
}

string Storage::GetQR(){
	return this->QR;
}

string Storage::GetProduct(){
	return this->product;
}

int Storage::GetCost(){
	return this->cost;
}

int Storage::GetQuantity(){
	return this->quantity;
}

double Storage::GetDiscount(){
	return this->discount;
}