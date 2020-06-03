#include "Cashbox.h"

�ashbox::�ashbox(){
	Storage t;
	Goods = new Storage[4];
	for (int i = 0; i < 4; i++){
		Goods[i] = t;
	}
}

�ashbox::~�ashbox(){
	Storage t;
	Goods = new Storage[4];
	for (int i = 0; i < 4; i++){
		Goods[i] = t;
	}
}

string �ashbox::Scan(){
	int i = 0, check, size;
	string s;
	char* c;
	cout << "����������� �������\n���:" << endl;
	cin >> s;
	i++;
	size = s.length();
	c = new char[size];
	for (int i = 0; i < size; i++){
		c[i] = s[i];
	}
	check = atoi(c);
	if (check > 0 && check <= 9999){
		return s;
	}
	else{
		if (s == "0000")
			return s;
	}
	return s = "������� �� ������";
}

int �ashbox::FindItem(string s){
	for (int i = 0; i < 4; i++){
		if (s == Goods[i].GetQR()){
			cout << "������� ������" << endl;
			return i;
		}
	}
	cout << "������� �� ������" << endl;
	return -1;
}

void �ashbox::discription(int i){
	cout << endl
		<< "///////////////////////////////////////////////////" << endl
		<< "* ��� ��������: "
		<< Goods[i].GetQR()
		<< "\n* ��� ��������: "
		<< Goods[i].GetProduct()
		<< "\n* ����:     "
		<< Goods[i].GetCost()
		<< "\n* ������:  "
		<< Goods[i].GetDiscount() * 100
		<< "%"
		<< "\n* ���� �� �������: "
		<< Goods[i].GetCost() - Goods[i].GetCost() * Goods[i].GetDiscount()
		<< endl << "////////////////////////////////////////////////////";
}

void �ashbox::SetT(Storage tmp[]){
	for (int i = 0; i < 4; i++){
		Goods[i] = tmp[i];
	}
}

Storage& �ashbox::operator[](const int tmp){
	return this->Goods[tmp];
}

void �ashbox::PrintChek(){
	if (Goods[0].GetQuantity() != 0 || Goods[1].GetQuantity() != 0 || Goods[2].GetQuantity() != 0 || Goods[3].GetQuantity() != 0)	{
		int res, g = 0;
		cout << "��� ���" << endl;
		cout << "*QR* **********��������***********����������**����**������**���� �� �������*" << endl;
		for (int i = 0; i < 4; i++){
			if (Goods[i].GetQuantity() != 0){
				cout << Goods[i].GetQR() << " ";
				cout.width(20);
				cout << Goods[i].GetProduct();
				cout.width(15);
				cout << Goods[i].GetQuantity();
				cout.width(10);
				cout << Goods[i].GetCost() * Goods[i].GetQuantity();
				cout.width(6);
				cout << Goods[i].GetDiscount() * 100 << "%";
				cout.width(11);
				res = (Goods[i].GetCost() - Goods[i].GetCost() * Goods[i].GetDiscount()) * Goods[i].GetQuantity();
				cout << res << endl;
				g += res;
			}
		}
		cout << "**********************************************************����� ����****" << g << endl;
	}
}

void �ashbox::DeleteItem(string s){
	for (int i = 0; i < 4; i++){
		if (s == Goods[i].GetQR() && Goods[i].GetQuantity() > 0){
			Goods[i].SetQuantity(Goods[i].GetQuantity() - 1);
			break;
		}
	}

}

void �ashbox::AddItem(string s){
	for (int i = 0; i < 4; i++){
		if (s == Goods[i].GetQR())
			Goods[i].SetQuantity(Goods[i].GetQuantity() + 1);
	}
}