#include <iostream>
#include "Polinom.hpp"
#include <string>

int main()
{
	Polynomial p({ -1,2,-5,0,3 }, 4), p2({-3,1,0,1,2,5,8},6);
	Polynomial p3({ 1,2,3 }, 2);

	std::cout << p + p2<<'\n';
	std::cout << p - p2<<'\n';
	std::cout << p*p2 << '\n';

	std::cout << ppoint(p3,2);

	system("pause");
	return 0;
}