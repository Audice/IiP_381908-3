#include "complex.h"
#include "vector.h"
using namespace std;

int main() {
	setlocale(LC_ALL, "rus");
	int denominator1, numerator1, denominator2, numerator2, a, b=0, c, d, e, f;
	fraction first;
	fraction second;
	vector one;
	do {
		system("cls");
		cout << "�� ������ �������� �:\n1 ������������ �������\n2 ������\n3 ������� �������\n4 ���������\n404 - ����� �� ���������" << endl;
		cin >> c;
		switch (c) {
		case 1: {
			cout << "������ ��������� ������ �����: "; cin >> numerator1;
			first.setNumerator(numerator1);
			do {
				cout << "������ ����������� ������ �����: "; cin >> denominator1;
			} while (denominator1 == 0);
			first.setDenominator(denominator1);
			cout << "�������� �����: " << first.getNumerator() << "/" << first.getDenominator() << endl << endl;
			cout << "������ ��������� ������ �����: "; cin >> numerator2;
			second.setNumerator(numerator2);
			do {
				cout << "������ ����������� ������ �����: "; cin >> denominator2;
				second.setDenominator(denominator2);
			} while (denominator2 == 0);
			cout << "�������� �����: " << second.getNumerator() << "/" << second.getDenominator() << endl << endl;
			do {
				system("cls");
				complex some(first, second);
				cout << "����������� ����� = ";
				some.out();	cout << endl;
				cout << "1 ����������� ������ � ������ �����\n2 �������� ����������\n404 - ���������� ���" << endl;
				cin >> d;
				switch (d) {
				case 1: {
					complex some(first, second);
					complex tmp12;
					tmp12 = some;
					cout << "������, ����������� �����: ";
					tmp12.out();
					cout << " ��������� � ����� �������" << endl;
				}break;
				case 2: {
					complex some(first, second);
					complex some1;
					cin >> some1; cout << endl;
					cout << some1; cout << " - ����� ���������" << endl;
					some1 + some; cout << " - ����� � ����������" << endl;
					some1 - some; cout << " - �������� � ����������" << endl;
					some1 * some; cout << " - ������������ � ����������" << endl;
					some1 / some; cout << " - ������� � ���������" << endl;
					some1 + 2; cout << " - ����� � ������" << endl;
					some1 - 2; cout << " - �������� � ������" << endl;
					some1 * 2; cout << " - ������������ � ������" << endl;
					some1 / 2; cout << " - ������� � ������" << endl;
					if (some1 > some) {
						cout << "����� - ��������� ������" << endl;
					}
					else {
						cout << "�� ����� - ��������� ������" << endl;
					}
					if (some1 < some) {
						cout << "����� - ��������� ������" << endl;
					}
					else {
						cout << "�� ����� - ��������� ������" << endl;
					}
					if (some1 == some) {
						cout << "����� - ��������� ���������������" << endl;
					}
					else {
						cout << "�� ����� - ��������� ���������������" << endl;
					}
					if (some1 != some) {
						cout << "����� - ��������� �� ���������������" << endl;
					}
					else {
						cout << "�� ����� - ��������� �� ���������������" << endl;
					}
					if (some1 >= some) {
						cout << "����� - ��������� ������ ��� �����" << endl;
					}
					else {
						cout << "�� ����� - ��������� ������ ��� �����" << endl;
					}
					if (some1 <= some) {
						cout << "����� - ��������� ������ ��� �����" << endl;
					}
					else {
						cout << "�� ����� - ��������� ������ ��� �����" << endl;
					}
					some1 += some; cout << " - += ��������" << endl;
					some1 -= some; cout << " - -= ��������" << endl;
					some1 *= some; cout << " - *= ��������" << endl;
					some1 /= some; cout << " - /= ��������" << endl;
					some1 += 2; cout << " - += �����" << endl;
					some1 -= 2; cout << " - -= �����" << endl;
					some1 *= 2; cout << " - *= �����" << endl;
					some1 /= 2; cout << " - /= �����" << endl;
					}break;
				}
				system("pause");
			} while (d != 404);
		}break;      //���� � ������������ ����������
		case 2: {
			cout << "������ ��������� ������ �����: "; cin >> numerator1;
			first.setNumerator(numerator1);
			do {
				cout << "������ ����������� ������ �����: "; cin >> denominator1;
			} while (denominator1 == 0);
			first.setDenominator(denominator1);
			cout << "������ ��������� ������ �����: "; cin >> numerator2;
			second.setNumerator(numerator2);
			do {
				cout << "������ ����������� ������ �����: "; cin >> denominator2;
				second.setDenominator(denominator2);
			} while (denominator2 == 0);
			do {
				system("cls");
				cout << "� ��� ���� ����� �1: " << first.getNumerator() << "/" << first.getDenominator() << endl;
				cout << "��� ����  ����� �2: " << second.getNumerator() << "/" << second.getDenominator() << endl << endl;
				cout << "����� �������� ������ ���������?\n1 ��������\n2 ���������\n3 ���������\n4 �������\n404 - ��������� �� ������� ���" << endl << endl;
				cin >> a;
				switch (a) {
				case 1: {
					first.amount(first, second);
				}break;
				case 2: {
					first.subtraction(first, second);
				}break;
				case 3: {
					first.multiplication(first, second);
				}break;
				case 4: {
					first.division(first, second);
				}break;
				}
				system("pause");
			} while (a != 404);
		}break;      //���� � �������� ����������
		case 3: {
			system("cls");
			do {
				cout << "������ ��������� ������ �����: "; cin >> numerator1;
			} while (numerator1 == 0);
			first.setNumerator(numerator1);
			cout << "������ ����������� ������ �����: "; cin >> denominator1;
			first.setDenominator(denominator1);
			cout << "�������� �����: " << first.getNumerator() << "/" << first.getDenominator() << endl << endl;
			do {
				cout << "������ ��������� ������ �����: "; cin >> numerator2;
			} while (numerator2 == 0);
			second.setNumerator(numerator2);
			cout << "������ ����������� ������ �����: "; cin >> denominator2;
			second.setDenominator(denominator2);
			cout << "�������� �����: " << second.getNumerator() << "/" << second.getDenominator() << endl << endl;
		}break;      //���� ��� �������� ����� �����
		case 4: {
			cout << "������ ���������� ��������� �������:";
			cin >> e;
			one.setSizeMern(e);
			for (int i = 0; i < e; i++) {
				cin >> f;
				this->mass[i] = f;
				cout << "[" << i << "] = " << f;
			}
		}break;
		}
		system("pause");
	} while (c != 404);
	return 0;
}