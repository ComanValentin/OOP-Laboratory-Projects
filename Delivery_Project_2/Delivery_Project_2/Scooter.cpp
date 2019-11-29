#include "Scooter.h"

Scooter & Scooter::operator=(const Scooter & val)
{
	Vehicle::operator=(val);
	return *this;
}

ostream & operator<<(std::ostream & out, Scooter & val)
{
	return out <<"Scooter"<< static_cast<const Vehicle&>(val);
}

istream & operator>>(std::istream & in, Scooter & val)
{
	return in >> static_cast<Vehicle&>(val);
}
