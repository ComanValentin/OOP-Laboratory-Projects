#ifndef POLYNOMIAL_H_
#define POLYNOMIAL_H_

#include <vector>
#include <iostream>
#include <fstream>
#include <string>

class Polynomial {
public:
	Polynomial(const std::vector<double> = { 0 }, const int = 0);
	Polynomial(const Polynomial&);

	~Polynomial() {}

	Polynomial& operator+=(const Polynomial&);
	Polynomial& operator+=(const double&);
	Polynomial& operator-=(const Polynomial&);
	Polynomial& operator-=(const double&);
	Polynomial& operator*=(const Polynomial&);
	Polynomial& operator*=(const double&);

	Polynomial operator+(const Polynomial); 
	Polynomial operator+(const double&);
	friend Polynomial operator+(const double&, const Polynomial);

	Polynomial operator-(const Polynomial);
	Polynomial operator-(const double&);
	friend Polynomial operator-(const double&, const Polynomial);

	Polynomial operator*(const Polynomial);
	Polynomial operator*(const double&);
	friend Polynomial operator*(const double&, const Polynomial);

	friend Polynomial ppoint(const Polynomial,double);

	friend std::istream& operator>>(std::istream&, Polynomial&);
	friend std::ostream& operator<<(std::ostream&, const Polynomial&);

	static int cmp(const Polynomial&, const Polynomial&);
private:
	std::vector<double> mCoeff;
	int mDegree;
};
#endif