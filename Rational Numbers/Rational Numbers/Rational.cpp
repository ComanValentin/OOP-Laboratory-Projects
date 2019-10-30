#include "Rational.hpp"
//Forma Canonica
void Rational::FormaCanonica()
{
	int a, b;
	if (Num != 0 && Denom != 1)
	{
		if (Denom < 0)		//Verifica daca numitorul are '-'
		{
			Denom = -Denom;
			Num = -Num; //Aduce '-' la numarator
		}
		a = abs(Num);
		b = abs(Denom);
		while (a != b)		//Cel mai mare divizor comun
		{
			if (a > b)
				a -= b;
			else
				b -= a;
		}
		//simplificare
		Num /= a;
		Denom /= a;
	}
}



//Constructori Initializare si Copiere
Rational::Rational(int numarator, int numitor)
{
	if (numitor == 0) //Verifica daca numitorul e 0
		throw std::invalid_argument("Numitor diferit de 0!!!");
	Num = numitor;
	Denom = numarator;
	FormaCanonica();
}
Rational::Rational(const Rational& r)
{
	Num = r.Num;
	Denom = r.Denom;
	FormaCanonica();
}



//Set Numitor si Numarator
void Rational::setBoth(int n, int d)
{
	Num = n;
	Denom = d;
	FormaCanonica();
}
//Set Numarator
void Rational::setNumarator(int n)
{
	Num = n;
	FormaCanonica();
}
//Set Numitor
void Rational::setNumitor(int d)
{
	Denom = d;
	FormaCanonica();
}
//Get 
int Rational::getNumarator()
{
	return Num;
}
int Rational::getNumitor()
{
	return Denom;
}


Rational& Rational:: operator+=(const Rational& t)
{
	Num = Num * t.Denom + Denom * t.Num;
	Denom = Denom * t.Denom;
	FormaCanonica();
	return *this;
}
Rational& Rational:: operator+=(const int t)
{
	Num = Num + Denom * t;
	FormaCanonica();
	return *this;
}
Rational& Rational:: operator-=(const Rational& t)
{
	Num = Num * t.Denom - Denom * t.Num;
	Denom = Denom * t.Denom;
	FormaCanonica();
	return *this;
}
Rational& Rational:: operator-=(const int t)
{
	Num = Num - Denom * t;
	FormaCanonica();
	return *this;
}
Rational& Rational:: operator*=(const Rational& t)
{
	Num *= t.Num;
	Denom *= t.Denom;
	FormaCanonica();
	return *this;
}
Rational& Rational:: operator*=(const int t)
{
	Num *= t;
	FormaCanonica();
	return *this;
}
Rational& Rational::operator/=(const Rational& t)
{
	Num *= t.Denom;
	Denom *= t.Num;
	FormaCanonica();
	return *this;
}
Rational& Rational::operator/=(const int c)
{
	Denom *= c;
	FormaCanonica();
	return *this;
}


//El insusi
Rational& operator+(Rational& m)
{
	return m;
}
//Opusul
Rational& operator-(Rational& m)
{
	m.Num = -m.Num;
	return m;
}
//Supraincarcare operatori aritmetici binari
//Adunari
Rational& operator+(const Rational& a, const Rational& b)
{
	Rational sum(a.Num*b.Denom + a.Denom*b.Num, a.Denom*b.Denom);
	return sum;
}
Rational& operator+(const int a, const Rational& b)
{
	Rational sum(b.Num + a * b.Denom, b.Denom);
	return sum;
}
Rational& operator+(const Rational& a, const int b)
{
	Rational sum(a.Num + b * a.Denom, a.Denom);
	return sum;
}
//Scaderi
Rational& operator-(const Rational& a, const Rational& b)
{
	Rational sub(a.Num*b.Denom - a.Denom*b.Num, a.Denom*b.Denom);
	return sub;
}
Rational& operator-(const int a, const Rational& b)
{
	Rational sub(a * b.Denom - b.Num, b.Denom);
	return sub;
}
Rational& operator-(const Rational& a, const int b)
{
	Rational sub(a.Num - b * a.Denom, a.Denom);
	return sub;
}
//Inmultiri
Rational& operator*(const Rational& a, const Rational& b)
{
	Rational prod(a.Num*b.Num, a.Denom*b.Denom);
	return prod;
}
Rational& operator*(const int a, const Rational& b)
{
	Rational prod(a*b.Num, b.Denom);
	return prod;
}
Rational& operator*(const Rational& a, const int b)
{
	Rational prod(b*a.Num, a.Denom);
	return prod;
}
//Impartiri
Rational& operator/(const Rational& a, const Rational& b)
{
	Rational div(a.Num*b.Denom, a.Denom*b.Num);
	return div;
}
Rational& operator/(const int a, const Rational& b)
{
	Rational div(b.Denom*a, b.Num);
	return div;
}
Rational& operator/(const Rational& a, const int b)
{
	Rational div(a.Num, b*a.Denom);
	return div;
}
//Ridicare la putere
Rational& operator^(const Rational& r, const int p)
{
	Rational pow(1, 1);
	int cNum = r.Num, cDenom = r.Denom;
	if (p < 0)
		std::swap(cNum, cDenom);
	for (int i = 1; i <= abs(p); i++)
	{
		pow.Num *= cNum;
		pow.Denom *= cDenom;
	}
	pow.FormaCanonica();
	return pow;
}


//Egalitate
bool operator==(const Rational& a, const Rational& b) //Rational-Rational
{
	if (a.Num == b.Num && a.Denom == b.Denom)
		return true;
	return false;
}
bool operator==(const int a, const Rational& b) //Int-Rational
{
	if (a == b.Num && b.Denom == 1)
		return true;
	return false;
}
bool operator==(const Rational & a, const int b) //Rational-Int
{
	if (b == a.Num && a.Denom == 1)
		return true;
	return false;
}



//Neegailitate
bool operator!=(const Rational &a, const Rational &b) //Rational-Rational
{
	if (a.Num != b.Num || a.Denom != b.Denom)
		return true;
	return false;
}
bool operator!=(const int a, const Rational &b)//Int-Rational
{
	if (a != b.Num || b.Denom != 1)
		return true;
	return false;
}
bool operator!=(const Rational &a, const int b)//Rational-Int
{
	if (b != a.Num || a.Denom != 1)
		return true;
	return false;
}



//Mai mic
bool operator<(const Rational &a, const Rational &b) //Rational-Rational
{
	if ((float)a.Num / (float)a.Denom < (float)b.Num / (float)b.Denom)
		return true;
	return false;
}
bool operator<(const int a, const Rational &b)//Int-Rational
{
	if ((float)a < (float)b.Num / (float)b.Denom)
		return true;
	return false;
}
bool operator<(const Rational &a, const int b)//Rational-Int
{
	if ((float)a.Num / (float)a.Denom < (float)b)
		return true;
	return false;
}



//Mai mare
bool operator>(const Rational &a, const Rational &b) //Rational-Rational
{
	if ((float)a.Num / (float)a.Denom > (float)b.Num / (float)b.Denom)
		return true;
	return false;
}
bool operator>(const int a, const Rational &b)//Int-Rational
{
	if ((float)a > (float)b.Num / (float)b.Denom)
		return true;
	return false;
}
bool operator>(const Rational &a, const int b)//Rational-Int
{
	if ((float)a.Num / (float)a.Denom > (float)b)
		return true;
	return false;
}



//Mai mic sau egal
bool operator<=(const Rational &a, const Rational &b) //Rational-Rational
{
	if ((float)a.Num / (float)a.Denom <= (float)b.Num / (float)b.Denom)
		return true;
	return false;
}
bool operator<=(const int a, const Rational &b)//Int-Rational
{
	if ((float)a <= (float)b.Num / (float)b.Denom)
		return true;
	return false;
}
bool operator<=(const Rational &a, const int b)//Rational-Int
{
	if ((float)a.Num / (float)a.Denom <= (float)b)
		return true;
	return false;
}



//Mai mare sau egal
bool operator>=(const Rational &a, const Rational &b) //Rational-Rational
{
	if ((float)a.Num / (float)a.Denom >= (float)b.Num / (float)b.Denom)
		return true;
	return false;
}
bool operator>=(const int a, const Rational &b)//Int-Rational
{
	if ((float)a >= (float)b.Num / (float)b.Denom)
		return true;
	return false;
}
bool operator>=(const Rational &a, const int b)//Rational-Int
{
	if ((float)a.Num / (float)a.Denom >= (float)b)
		return true;
	return false;
}


//metoda-operator publica de cast, de la rational la double??
Rational::operator double() const
{
	return (double)Num / (double)Denom;
}
Rational::operator int() const
{
	return (int)Num / (int)Denom;
}

//Citire Afisare
std::istream& operator>>(std::istream& in, Rational& r)
{
	std::string s, token;
	in >> s;
	int k = 1;
	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] == '/')
		{
			r.Num = std::stoi(token);
			token.clear();
			k = 0;
		}
		else
			token.push_back(s[i]);
	}
	if (k == 1)
	{
		r.Num = std::stoi(token);
		r.Denom = 1;
	}
	else
		r.Denom = std::stoi(token);
	r.FormaCanonica();
	return in;
}
std::ostream& operator<<(std::ostream& out, Rational& r)
{
	if (r.Denom == 1)
		out << r.Num;
	else
		out << r.Num << "/" << r.Denom;
	return out;
}