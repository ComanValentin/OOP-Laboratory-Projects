#ifndef SCOOTER_H_
#define SCOOTER_H_

#include "Vehicle.h"

class Scooter: public Vehicle {
public:
	Scooter() : Vehicle() {
	}

	Scooter(float x, float y, DeliveryStrategy strategy, float maxWeight, float maxVolume, string driverName) : Vehicle(x,y,strategy, Vehicle::euclid,20, maxWeight, maxVolume, driverName) {

	}
	Scooter(const Scooter& val) : Vehicle(val.x,val.y,val.strategy,Vehicle::euclid,20,val.maxWeight,val.maxVolume, val.driverName){

	}
	~Scooter() {

	}

	Scooter& operator=(const Scooter& val);
	friend ostream& operator<<(std::ostream& out, Scooter& val);
	friend istream& operator>>(std::istream& in, Scooter& val);
};

#endif