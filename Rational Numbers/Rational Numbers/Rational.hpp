#ifndef RATIONAL_H_
#define RATIONAL_H_

#include <stdexcept>
#include <string>

class Rational
{
public:
	Rational(int = 0, int = 1);
	Rational(const Rational&);

	//Set-uri si Get-uri
	void setBoth(int, int);
	void setNumarator(int);
	void setNumitor(int);
	int getNumarator();
	int getNumitor();

	Rational& operator+=(const Rational&);
	Rational& operator+=(const int);
	Rational& operator-=(const Rational&);
	Rational& operator-=(const int);
	Rational& operator*=(const Rational&);
	Rational& operator*=(const int);
	Rational& operator/=(const Rational&);
	Rational& operator/=(const int);

	//Operatori aritmetici binari
	friend Rational& operator+(const Rational&, const Rational&);
	friend Rational& operator+(const int, const Rational&);
	friend Rational& operator+(const Rational&, const int);
	friend Rational& operator-(const Rational&, const Rational&);
	friend Rational& operator-(const int, const Rational&);
	friend Rational& operator-(const Rational&, const int);
	friend Rational& operator*(const Rational&, const Rational&);
	friend Rational& operator*(const int, const Rational&);
	friend Rational& operator*(const Rational&, const int);
	friend Rational& operator/(const Rational&, const Rational&);
	friend Rational& operator/(const int, const Rational&);
	friend Rational& operator/(const Rational&, const int);
	friend Rational& operator^(const Rational&, const int);
	friend Rational& operator+(Rational&);
	friend Rational& operator-(Rational&);

	//Operatori relationali
	friend bool operator==(const Rational&, const Rational&);
	friend bool operator==(const int, const Rational&);
	friend bool operator==(const Rational&, const int);
	friend bool operator!=(const Rational&, const Rational&);
	friend bool operator!=(const int, const Rational&);
	friend bool operator!=(const Rational&, const int);
	friend bool operator<(const Rational&, const Rational&);
	friend bool operator<(const int, const Rational&);
	friend bool operator<(const Rational&, const int);
	friend bool operator<=(const Rational&, const Rational&);
	friend bool operator<=(const int, const Rational&);
	friend bool operator<=(const Rational&, const int);
	friend bool operator>(const Rational&, const Rational&);
	friend bool operator>(const int, const Rational&);
	friend bool operator>(const Rational&, const int);
	friend bool operator>=(const Rational&, const Rational&);
	friend bool operator>=(const int, const Rational&);
	friend bool operator>=(const Rational&, const int);

	operator double() const;
	operator int() const;

	//Citire & Afisare
	friend std::istream& operator>>(std::istream&, Rational&);
	friend std::ostream& operator<<(std::ostream&, Rational&);
private:
	int Num, Denom; //Numarator si numitor
	void FormaCanonica();
};

#endif //RATIONAL_H_