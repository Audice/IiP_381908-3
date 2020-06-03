#include"complex.h"
using namespace std;

void Complex::printi()
{

    cout << "(" << Re.getNumerator() << "/" << Re.getDenominator() << ")" << "+" << "(" << Im.getNumerator() << "/" << Im.getDenominator() << ")i" << endl;

}

Complex::Complex()
{
    this->Im = Fraction(0, 1);
    this->Re = Fraction(0, 1);

}

Complex::Complex(Fraction n, Fraction nr)
{
    this->Re = Fraction(n);
    this->Im = Fraction(nr);
}

Complex::Complex(const Complex& tmp)
{
    this->Im = Fraction(tmp.Im);
    this->Re = Fraction(tmp.Re);
}
Complex& Complex::operator = (const Complex& tmp)
{
    this->Im = tmp.Im;
    this->Re = tmp.Re;
    return *this;
}
Complex Complex::operator + (const Complex& tmp)const
{ 
    Complex osn;
    osn.Re = this->Re + tmp.Re;
    osn.Im = this->Im + tmp.Im;
    return osn;
}
Complex Complex::operator - (const Complex& tmp)const
{
    Complex osn;
    osn.Re = this->Re - tmp.Re;
    osn.Im = this->Im - tmp.Im;
    return osn;
}
Complex Complex::operator * (const Complex& tmp)const 
{
    //(a/b+a1/b1*i)*(c/d+c1/d1*i)=
    Complex osn;
    osn.Re=(this->Re*tmp.Re)-(this->Im*tmp.Re);
    osn.Im = (this->Re * tmp.Im)+(this->Im*tmp.Re);
    return osn;
}
Complex Complex::operator / (const Complex& tmp)const
{
    Complex osn;
    osn.Re = ((this->Re * tmp.Re)+(this->Im*tmp.Im))/((tmp.Re*tmp.Re)+(tmp.Im*tmp.Im));
    osn.Im = ((this->Im * tmp.Re) + (this->Re * tmp.Im)) / ((tmp.Re * tmp.Re) + (tmp.Im * tmp.Im));
    return osn;
}
Complex::~Complex()
{
    this->Im = Fraction(0,1);
    this->Re = Fraction(0, 1);

}
bool Complex::operator == (const Complex& tmp)
{
    bool f=0;
    Fraction* duc = new Fraction();
    Fraction* duc1 = new Fraction();
    if (this->Re.getNumerator()==tmp.Re.getNumerator()&&this->Re.getDenominator()==tmp.Re.getDenominator()&&
        this->Im.getNumerator() == tmp.Im.getNumerator() && this->Im.getDenominator() == tmp.Im.getDenominator())
    {
        cout << "они равны ";
        f == 1;
    }
    else
    {
        cout << "они не равны ";
        f == 0;
    }
    return f;
}
bool Complex::operator != (const Complex& tmp)
{
    bool f=0;
    Fraction* duc = new Fraction();
    Fraction* duc1 = new Fraction();
    if (this->Re.getNumerator() != tmp.Re.getNumerator() || this->Re.getDenominator() != tmp.Re.getDenominator() ||
        this->Im.getNumerator() != tmp.Im.getNumerator() || this->Im.getDenominator() != tmp.Im.getDenominator())
    {
        cout << "они не равны ";
        f == 1;
    }
    else
    {
        cout << "они  равны ";
        f == 0;
    }
    return f;
}
bool Complex::operator >= (const Complex& tmp)
{
    bool f=0;
    Fraction* duc = new Fraction();
    Fraction* duc1 = new Fraction();
    if (this->Re.getNumerator() >= tmp.Re.getNumerator() && this->Re.getDenominator() >= tmp.Re.getDenominator() )
    {
        cout << "1 big ";
        f == 1;
    }
    else
    {
        cout << "2 big ";
        f == 0;
    }
    return f;
}
bool Complex::operator <= (const Complex& tmp)
{
    bool f=0;
    Fraction* duc = new Fraction();
    Fraction* duc1 = new Fraction();
    if (this->Re.getNumerator() <= tmp.Re.getNumerator() && this->Re.getDenominator() <= tmp.Re.getDenominator() )
    {
        cout << "1 litel ";
        f == 1;
    }
    else
    {
        cout << "2 litel ";
        f == 0;
    }
    return f;
}
bool Complex::operator >(const Complex& tmp)
{
    bool f=0;
    Fraction* duc = new Fraction();
    Fraction* duc1 = new Fraction();
    if (this->Re.getNumerator() > tmp.Re.getNumerator() && this->Re.getDenominator() > tmp.Re.getDenominator())
    {
        cout << "1 big ";
        f == 1;
    }
    else
    {
        cout << "2 big ";
        f == 0;
    }
    return f;
}
bool Complex::operator < (const Complex& tmp)
{
    bool f=0;
    Fraction* duc = new Fraction();
    Fraction* duc1 = new Fraction();
    if (this->Re.getNumerator() < tmp.Re.getNumerator() && this->Re.getDenominator() < tmp.Re.getDenominator())
    {
        cout << "1 litel ";
        f == 1;
    }
    else
    {
        cout << "2 litel ";
        f == 0;
    }
    return f;
}
Complex Complex::operator + (const int& tmp)const
{
    Complex osn;
    osn.Re.Sum1(this->Re.getNumerator(), tmp, this->Re.getDenominator(),1);
    osn.Im.Sum1(this->Im.getNumerator(), tmp, this->Im.getDenominator(),1);
    return osn;
}
Complex Complex::operator - (const int& tmp)const
{
    Complex osn;
    osn.Re.Razn1 (this->Re.getNumerator(), tmp, this->Re.getDenominator(), 1);
    osn.Im.Razn1(this->Im.getNumerator(), tmp, this->Im.getDenominator(), 1);
    return osn;
}
Complex Complex::operator * (const int& tmp)const
{
    Complex osn;
    osn.Re.Multiplication1(this->Re.getNumerator(), tmp, this->Re.getDenominator(), 1);
    osn.Im.Multiplication1(this->Im.getNumerator(), tmp, this->Im.getDenominator(), 1);
    return osn;
}
Complex Complex::operator / (const int& tmp)const
{
    Complex osn;
   
    osn.Re.Division1(this->Re.getNumerator(), tmp, this->Re.getDenominator(), 1);
    osn.Im.Division1(this->Im.getNumerator(), tmp, this->Im.getDenominator(), 1);
    return osn;
}
Complex& Complex:: operator += (const Complex& tmp)
{
    Complex osn;
    osn.Re = this->Re + tmp.Re;
    osn.Im = this->Im + tmp.Im;
    *this = osn;
    return *this;
}
Complex& Complex::operator -= (const Complex& tmp)
{
    Complex osn;
    osn.Re = this->Re - tmp.Re;
    osn.Im = this->Im - tmp.Im;
    *this = osn;
    return *this;
}
Complex& Complex::operator *= (const Complex& tmp)
{
    Complex osn;
    osn.Re = this->Re * tmp.Re;
    osn.Im = this->Im * tmp.Im;
    *this = osn;
    return *this;
}
Complex& Complex::operator /= (const Complex& tmp)
{
    Complex osn;
    osn.Re = this->Re / tmp.Re;
    osn.Im = this->Im / tmp.Im;
    *this = osn;
    return *this;
}
Complex& Complex::operator += (const int& tmp)
{
    Complex osn;
    osn.Re.Sum1(this->Re.getNumerator(), tmp, this->Re.getDenominator(), 1);
    osn.Im.Sum1(this->Im.getNumerator(), tmp, this->Im.getDenominator(), 1);
    *this = osn;
    return *this;
}
Complex& Complex::operator -= (const int& tmp)
{
    Complex osn;
    osn.Re.Razn1(this->Re.getNumerator(), tmp, this->Re.getDenominator(), 1);
    osn.Im.Razn1(this->Im.getNumerator(), tmp, this->Im.getDenominator(), 1);
    cout << "(" << osn.Re.getNumerator() << "/" << osn.Re.getDenominator() << ")+(" << osn.Im.getNumerator() << "/" << osn.Im.getDenominator() << ")";
    *this = osn;
    return *this;
}
Complex& Complex::operator *= (const int& tmp)
{
    Complex osn;
    osn.Re.Multiplication1(this->Re.getNumerator(), tmp, this->Re.getDenominator(), 1);
    osn.Im.Multiplication1(this->Im.getNumerator(), tmp, this->Im.getDenominator(), 1);
    return *this;
}
Complex& Complex::operator /= (const int& tmp)
{
    Complex osn;

    osn.Re.Division1(this->Re.getNumerator(), tmp, this->Re.getDenominator(), 1);
    osn.Im.Division1(this->Im.getNumerator(), tmp, this->Im.getDenominator(), 1);
    *this = osn;
    return *this;
}
Complex& Complex :: operator++()
{
    Fraction b(3,7);
    Complex a;
   a.Re = this->Re + b;
    a.Im= this->Im+ b;
    *this = a;
    return *this;
}

ostream& operator<<(ostream& os, const Complex osn)
{
   return os << "(" << osn.Re.getNumerator() << "/" << osn.Re.getDenominator() << ")" << "+" << "(" << osn.Im.getNumerator() << "/" << osn.Im.getDenominator() << ")i" << endl;
}
