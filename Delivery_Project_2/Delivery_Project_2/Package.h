#ifndef PACKAGE_H
#define PACKAGE_H

#include <iostream>

using namespace std;


class Package {
public:
	enum DeadlineType {
		normal,
		nolimit
	};

	Package() {
		x = -1;
		y = -1;
	}

	Package(float x, float y, float weight, float volume, bool cold, DeadlineType deadlineType, int id, float mp):x(x),y(y),weight(weight),volume(volume),cold(cold),deadlineType(deadlineType),id(id),mp(mp) {
		
	}
	Package(const Package& ex) :x(ex.x), y(ex.y),weight(ex.weight),volume(ex.volume),cold(ex.cold), deadlineType(ex.deadlineType), id(ex.id),mp(ex.mp) {

	}

	Package& operator=(const Package& val);
	friend ostream& operator<<(std::ostream& out, const Package& val);
	friend istream& operator>>(std::istream& in, Package& val);

	float timeUntilDeadline(float currentTime) const;
	

	void setX(const float val);

	void setY(const float val);

	void setWeight(const float val);

	void setVolume(const float val);

	void setCold(const bool val);

	void setId(const int val);

	const float getX() const;

	const float getY() const;
	const float getWeight() const;

	const float getVolume() const;

	const bool isCold() const;

	const int getId() const;

	const float getMp() const;


	const DeadlineType getDeadlineType() const;

private:
	DeadlineType deadlineType;
	float x;
	float y;
	float weight;
	float volume;
	bool cold;
	int id;
	float mp;

};

#endif