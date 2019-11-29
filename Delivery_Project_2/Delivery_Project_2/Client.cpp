#include "Client.h"

Client& Client::operator=(const Client& val)
{
	this->x = val.x;
	this->y = val.y;
	this->name = val.name;
	this->package = val.package;

	return *this;
}

void Client::addPackage(const Package& package)
{
	this->package = package;
}

void Client::setX(const float val)
{
	x = val;
}

void Client::setY(const float val)
{
	y = val;
}

void Client::setName(const string& val)
{
	name = val;
}

const float Client::getX() const
{
	return x;
}

const float Client::getY() const
{
	return y;
}

const string Client::getName() const
{
	return name;
}

const Package Client::getPackage() const
{
	return package;
}



ostream& operator<<(std::ostream& out, const Client& val)
{
	out << "Client named " << val.name << " located at (" << val.x << "," << val.y << ")";
	return out;
}

istream& operator>>(std::istream& in, Client& val)
{
	in >> val.x >> val.y >> val.name;

	return in;
}