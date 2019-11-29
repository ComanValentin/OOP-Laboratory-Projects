#include "Car.h"

Car & Car::operator=(const Car & val)
{
	Vehicle::operator=(val);
	return *this;
}

ostream & operator<<(std::ostream & out, Car & val)
{
	return out << "Car"<<static_cast<const Vehicle&>(val);
}

istream & operator>>(std::istream & in, Car & val)
{
	return in >> static_cast<Vehicle&>(val);
}
