#include "Polinom.hpp"

Polynomial::Polynomial(const std::vector<double> coeff, const int degree) {
	mCoeff = coeff;
	mDegree = degree;
}

Polynomial::Polynomial(const Polynomial& p) {
	mCoeff = p.mCoeff;
	mDegree = p.mDegree;
}

int Polynomial::cmp(const Polynomial& p, const Polynomial& p2) {
	if (p.mDegree < p2.mDegree)
		return p.mDegree;
	else
		return p.mDegree;
}

//ADUNARE

Polynomial& Polynomial::operator+=(const Polynomial& p) {

	for (int i = 0; i <= cmp(*this, p); i++) {
		mCoeff[i] += p.mCoeff[i];
	}

	if (mDegree < p.mDegree) {
		for (int i = mDegree + 1; i <= p.mDegree; i++) {
			mCoeff.push_back(p.mCoeff[i]);
		}
		mDegree = p.mDegree;
	}

	return *this;
}

Polynomial& Polynomial::operator+=(const double& p) {
	mCoeff[0] += p;

	return *this;
}

Polynomial Polynomial::operator+(const Polynomial p) {
	Polynomial temp(*this);
	temp += p;

	return temp;
}

Polynomial Polynomial::operator+(const double& p) {
	Polynomial temp(*this);
	temp += p;

	return temp;
}

Polynomial operator+(const double& p, const Polynomial p2) {
	Polynomial temp(p2);
	temp += p;

	return temp;
}
//SCADERE

Polynomial& Polynomial::operator-=(const Polynomial& p) {
	Polynomial temp(p);

	for (int i = 0; i <= p.mDegree; i++) {
		temp.mCoeff[i] *= -1;
	}

	*this += temp;
	for (int i = mDegree; i >= 0; i--) {
		if (mCoeff[i] != 0)
			break;
		else {
			mDegree--;
			mCoeff.erase(mCoeff.begin() + i);
		}
	}

	return *this;
}

Polynomial& Polynomial::operator-=(const double& p) {
	*this += (-p);

	return *this;
}

Polynomial Polynomial::operator-(const Polynomial p) {
	Polynomial temp(*this);
	temp -= p;

	return temp;
}

Polynomial Polynomial::operator-(const double& p) {
	Polynomial temp(*this);
	temp -= p;

	return temp;
}

Polynomial operator-(const double& p, const Polynomial p2) {
	Polynomial temp({ p }, 0);							

	return temp;
}

//INMULTIRE

Polynomial& Polynomial::operator*=(const Polynomial& p)
{
	std::vector<double> tempVector(mDegree + p.mDegree + 1, 0);
	Polynomial temp(tempVector, mDegree + p.mDegree);

	for (int i = 0; i <= mDegree; i++) {
		for (int j = 0; j <= p.mDegree; j++) {
			temp.mCoeff[i + j] += mCoeff[i] * p.mCoeff[j];
		}
	}
	*this = temp;
	return *this;
}
Polynomial& Polynomial::operator*=(const double& p)
{
	for (int i = 0; i <= mDegree; i++) {
		mCoeff[i] *= p;
	}

	return *this;
}

Polynomial Polynomial::operator*(const Polynomial p) {
	Polynomial temp(*this);
	temp *= p;

	return temp;
}

Polynomial Polynomial::operator*(const double& p) {
	Polynomial temp(*this);
	temp *= p;

	return temp;
}

Polynomial operator*(const double& p, const Polynomial p2) {
	Polynomial temp(p2);
	temp *= p;

	return temp;
}
//CALCUL INTR-UN PUNCT

Polynomial ppoint(const Polynomial p, const double val)
{
	Polynomial s({0},0);
	for (int i = 0; i <= p.mDegree; i++)
	{
		s.mCoeff[0] = s.mCoeff[0] + (pow(val,i) * p.mCoeff[i]);
	}
	return s;
}

//CIIRE/AFISARE

std::istream& operator>>(std::istream& in, Polynomial& p) {

	std::string tbr;
	Polynomial temp;
	in >> tbr;
	int i;

	for (i = 1; i < tbr.length(); i++) {			
		if (tbr[i] == '+' || tbr[i] == '-') {
			char token = tbr[i];						
			std::string tempStr = tbr.substr(0, tbr.find(token));
			temp.mCoeff[0] = (atof(tempStr.c_str()));
			tbr.erase(0, tempStr.length());
			break;
		}
		else if (tbr[i] == '*')
			break;
	}

	if (tbr.length() != 0 && tbr.find('*') == -1) {		
		temp.mCoeff[0] = atof(tbr.c_str());
		tbr.erase(0, tbr.length());
	}

	while (tbr.length() > 0) {										
		std::string tempStr = tbr.substr(0, tbr.find("*x"));
		if (tbr[tempStr.length() + 2] != '^') {					
			temp.mCoeff.push_back(atof(tempStr.c_str()));
			tbr.erase(0, tempStr.length() + 2);
		}
		else {														
			std::string tempTbr = tbr;			
			tempTbr.erase(0, 1);
			std::string degreeString;						
			if (tempTbr.find("+") == -1 && tempTbr.find("-") == -1) {			
				degreeString = tbr.substr(tempStr.length() + 3, -1);
			}
			else {
				int tokenPos = tempTbr.find("+") < tempTbr.find("-") ? tempTbr.find("+") : tempTbr.find("-");		
				degreeString = tbr.substr(tempStr.length() + 3, tokenPos - 3);
			}

			int x = atof(degreeString.c_str());
			for (int i = temp.mCoeff.size(); i < x; i++) {
				temp.mCoeff.push_back(0);						
			}
			temp.mCoeff.push_back(atof(tempStr.c_str()));
			tbr.erase(0, tempStr.length() + degreeString.length() + 3);			
		}
	}
	temp.mDegree = temp.mCoeff.size() - 1;
	p = temp;

	return in;
}

std::ostream & operator<<(std::ostream & out, const Polynomial & p)
{
	if (p.mCoeff[0] != 0)
	{
		if (p.mCoeff[0] > 0)
			out << "+";
		out << p.mCoeff[0];
	}
	for (int i = 1; i <= p.mDegree; i++) {
		if (p.mCoeff[i] != 0) {
			if (p.mCoeff[i] > 0)
				out << "+";

			out << p.mCoeff[i] << "*x";
			if (i > 1)
				out << "^" << i;
		}
	}
	out << std::endl;
	return out;
}