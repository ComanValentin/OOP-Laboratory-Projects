#ifndef TRUCK_H_
#define TRUCK_H_

#include "Vehicle.h"

class Truck: public Vehicle {
public:
	Truck() : Vehicle() {
	}

	Truck(float x, float y, DeliveryStrategy strategy, bool cold, float maxWeight, float maxVolume, string driverName) : Vehicle(x, y, strategy, Vehicle::manhattan, 5,maxWeight,maxVolume, driverName),cold(cold) {

	}
	Truck(const Truck& val) : Vehicle(val.x, val.y, val.strategy, Vehicle::manhattan, 5,val.maxWeight,val.maxVolume,val.driverName),cold(val.cold) {

	}
	~Truck() {

	}

	const bool canCarryCold() const;
	Truck& operator=(const Truck& val);
	friend ostream& operator<<(std::ostream& out, Truck& val);
	friend istream& operator>>(std::istream& in, Truck& val);

private:
	bool cold;

};


#endif
