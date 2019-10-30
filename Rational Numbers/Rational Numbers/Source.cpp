#include "Rational.hpp"

#include <iostream>
#include <fstream>
using std::cin;
using std::cout;
using std::endl;

int main()
{
	std::ifstream fin("input.txt");
	std::ofstream fout("output.txt");
	Rational r1, r2(2, 6);
	fin >> r1;
	fout << "r1 " << r1 << endl;
	if (r1 < r2)
		fout << "True\n";
	else
		fout << "False\n";
	fout.close();
	fin.close();
}