#ifndef CLIENT_H_
#define CLIENT_H_

#include <string>
#include <iostream>
#include <vector>
#include "Package.h"

using namespace std;

class Client {
public:
	enum DeliveryStrategy {
		urgency,
		closest,
		first
	};
	Client() {
	}

	Client(float x, float y, string name, Package package) :x(x), y(y), name(name), package(package) {

	}
	Client(const Client& ex) :x(ex.x), y(ex.y), name(ex.name),package(ex.package) {

	}
	~Client() {

	}

	Client& operator=(const Client& val);
	friend ostream& operator<<(std::ostream& out, const Client& val);
	friend istream& operator>>(std::istream& in, Client& val);

	void addPackage(const Package& package);

	void setX(const float val);
	void setY(const float val);
	void setName(const string& val);

	const float getX() const;
	const float getY() const;
	const string getName() const;
	const Package getPackage() const;


private:
	float x;
	float y;
	string name;
	Package package;
};


#endif