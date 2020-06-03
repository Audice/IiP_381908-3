#include"fraction.h"
using namespace std;
int Fraction::soc(int x, int y) const
{
    x = abs(x);
    y = abs(y);
    int o1 = 1, c;
    if (x < y)
    {
        c = x;
        x = y;
        y = c;
    }
    while (o1 > 0)
    {
        o1 = x % y;
        x = y;
        y = o1;
    }
    return x;
}
Fraction::~Fraction()
{


}
Fraction& Fraction::operator = (const Fraction& tmp)
{
    this->numerator = tmp.numerator;
    this->denominator = tmp.denominator;
    return *this;
}
void Sum1(int a, int b, int a1, int b1)
{

}

int Fraction::getNumerator() const
{
    return this->numerator;
}
void Fraction::setNumerator(int newnumerat)
{
    this->numerator = newnumerat;
}
void Fraction::Conversion(int nomer)
{
    cout << "дробь №" << nomer + 1 << " " << getNumerator() << "/" << getDenominator() << endl;
}

int Fraction::getDenominator() const
{
    return this->denominator;
}
void Fraction::setDenominator(int newdenominat)
{
    this->denominator = newdenominat;
}

Fraction Fraction::operator+(const Fraction& tmp) const
{
    Fraction a;
     
    return a.Sum1(this->getNumerator(), tmp.getNumerator(), this->getDenominator(), tmp.getDenominator());
}

Fraction Fraction::operator-(const Fraction& tmp) const
{
    Fraction a;
    return a.Razn1(this->getNumerator(), tmp.getNumerator(), this->getDenominator(), tmp.getDenominator());
}
Fraction Fraction::operator * (const Fraction& tmp)const
{
    Fraction osn;
    
    return osn.Multiplication1(this->getNumerator(), tmp.getNumerator(), this->getDenominator(), tmp.getDenominator());
}
Fraction Fraction::operator / (const Fraction& tmp)const
{
    Fraction osn;
   
    return osn.Multiplication1(this->getNumerator(), tmp.getNumerator(), this->getDenominator(), tmp.getDenominator());
}

void Fraction::Multiplication(int a[], int b[], int n)
{
    int russa = 1, azia = 1, NOD;
    cout << "умножение дробей = ";
    for (int i = 0; i < n; i++)
    {
        russa = russa * a[i];
        azia = azia * b[i];
    }
    if (russa == 0)
    {
        cout << "умножение  дробей = 0" << endl;
    }
    else
    {
        NOD = soc(russa, azia);
        russa = russa / NOD;
        azia = azia / NOD;
    }
    cout << russa << "/" << azia << endl;
}
void Fraction::Sum(int a[], int b[], int n)
{
    int sumsh = 1, sumz = a[0], k = b[0], NOD;
    for (int i = 0; i < n; i++)
    {
        sumz = sumz * b[i];
    }
    for (int i = 0; i < n - 1; i++)
    {
        sumsh = (sumsh * b[i + 1]) + (a[i + 1] * k);
        k = k * b[i + 1];
    }
    if (sumsh == 0)
    {
        cout << "сумма дробей = 0" << endl;
    }
    else
    {
        NOD = soc(sumsh, sumz);
        sumsh = sumsh / NOD;
        sumz = sumz / NOD;
        cout << "сложение дробей = " << sumsh << "/" << sumz << endl;
    }
}
Fraction Fraction::Sum1(int a, int b, int a1, int b1) const
{

    int c,d,NOD;
    c = a * b1 + a1 * b;
    d = a1 * b1;
    NOD = soc(c, d);
    c = c / NOD;
    d =  d/ NOD;
    Fraction* h = new Fraction();
    h->setNumerator(c);
    h->setDenominator(d);

    return *h;
}
Fraction Fraction:: Multiplication1(int a, int b, int a1, int b1)
{
    int c, d, NOD;
    c = a * a1;
    d = b * b1;
    NOD = soc(c, d);
    c = c / NOD;
    d = d / NOD;
    Fraction* h = new Fraction();
    h->setNumerator(c);
    h->setDenominator(d);
    return *h;
}
Fraction Fraction::Razn1(int a, int b, int a1, int b1)
{

    int c, d, NOD;
    c = a * b1 - a1 * b;
    d = b * b1;
   /* NOD = soc(c, d);
    c = c / NOD;
    d = d / NOD;*/
    Fraction* h = new Fraction();
    h->setNumerator(c);
    h->setDenominator(d);
    return *h;
}
void Fraction::Razn(int a[], int b[], int n)
{
    int sumsh = a[0], sumz = 1, k = b[0], NOD;
    for (int i = 0; i < n; i++)
    {
        sumz = sumz * b[i];
    }
    for (int i = 0; i < n - 1; i++)
    {
        sumsh = (sumsh * b[i + 1]) - (a[i + 1] * k);
        k = k * b[i + 1];
    }
    if (sumsh == 0)
    {
        cout << "разность дробей = 0" << endl;
    }
    else
    {
        NOD = soc(sumsh, sumz);
        sumsh = sumsh / NOD;
        sumz = sumz / NOD;
        cout << "разность дробей = " << sumsh << "/" << sumz << endl;
    }
}
Fraction Fraction::Division1(int a, int b, int a1, int b1)
{
    int c, d, NOD;
    c = a * b1;
    d = b * a1;
    NOD = soc(c, d);
    c = c / NOD;
    d = d / NOD;
    Fraction* h = new Fraction();
    h->setNumerator(c);
    h->setDenominator(d);
    return *h;
}
void Fraction::Division(int a[], int b[], int n)
{
    int russa = 1, azia = 1, NOD;
    cout << "деление  дробей = ";
    for (int i = 0; i < n; i++)
    {
        if (i == 0)
        {
            russa = russa * a[i];
            azia = azia * b[i];
        }
        else
        {
            russa = russa * b[i];
            azia = azia * a[i];
        }
    }
    if (russa == 0)
    {
        cout << "деление дробей = 0" << endl;
    }
    else
    {
        NOD = soc(russa, azia);
        russa = russa / NOD;
        azia = azia / NOD;
    }
    cout << russa << "/" << azia << endl;
}
Fraction::Fraction()
{
}
Fraction::Fraction(int a ,int b)
{
    this->numerator = a;
    this->denominator = b;
}