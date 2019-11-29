#ifndef CAR_H_
#define CAR_H_

#include "Vehicle.h"

class Car : public Vehicle {
public:
	Car() : Vehicle() {
	}

	Car(float x, float y, DeliveryStrategy strategy, float maxWeight, float maxVolume, string driverName) : Vehicle(x, y, strategy, Vehicle::manhattan, 10,maxWeight,maxVolume,driverName) {

	}
	Car(const Car& val) : Vehicle(val.x, val.y, val.strategy, Vehicle::manhattan, 10,val.maxWeight,val.maxVolume,val.driverName) {

	}
	~Car() {

	}

	Car& operator=(const Car& val);
	friend ostream& operator<<(std::ostream& out, Car& val);
	friend istream& operator>>(std::istream& in, Car& val);
};

#endif