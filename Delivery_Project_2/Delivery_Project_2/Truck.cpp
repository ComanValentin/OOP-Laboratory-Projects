#include "Truck.h"

const bool Truck::canCarryCold() const
{
	return cold;
}

Truck & Truck::operator=(const Truck & val)
{
	Vehicle::operator=(val);
	this->cold = val.cold;
	return *this;
}

ostream & operator<<(std::ostream & out, Truck & val)
{
	return out << "Truck"<< static_cast<const Vehicle&>(val) << " that can carry cold "<<val.cold;
}

istream & operator>>(std::istream & in, Truck & val)
{
	return in >> static_cast<Vehicle&>(val) >> val.cold;
}
