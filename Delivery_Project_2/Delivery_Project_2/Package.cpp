#include "Package.h"

Package& Package::operator=(const Package& val) {
	this->x = val.x;
	this->y = val.y;
	this->weight = val.weight;
	this->volume = val.volume;
	this->cold = val.cold;
	this->deadlineType = val.deadlineType;
	this->id = val.id;
	this->mp = val.mp;

	return *this;
}

float Package::timeUntilDeadline(float currentTime) const
{
	float time = -1.0f;
	if (deadlineType == normal) {
		time = mp - currentTime;
	}

	return time;
}

void Package::setX(const float val) {
	x = val;
}
void Package::setY(const float val) {
	y = val;
}
void Package::setWeight(const float val) {
	weight = val;
}
void Package::setVolume(const float val) {
	volume = val;
}
void Package::setCold(const bool val) {
	cold = val;
}
void Package::setId(const int val) {
	id = val;
}
const float Package::getX() const {
	return x;
}
const float Package::getY() const {
	return y;
}

const float Package::getWeight() const {
	return weight;
}

const float Package::getVolume() const {
	return volume;
}
const bool Package::isCold() const {
	return cold;
}
const int Package::getId() const {
	return id;
}
const float Package::getMp() const {
	return mp;
}
const Package::DeadlineType Package::getDeadlineType() const {
	return deadlineType;
}
ostream& operator<<(std::ostream& out, const Package& val)
{
	out << "Package with location (" << val.x << "," << val.y << "), mass " << val.weight << ", volume " << val.volume << ", which is cold: " << val.cold;
	return out;
}

istream& operator>>(std::istream& in, Package& val)
{
	in >> val.x >> val.y >> val.weight >> val.volume >> val.cold >> val.id;

	return in;
}
