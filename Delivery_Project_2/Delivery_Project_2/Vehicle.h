#ifndef VEHICLE_H_
#define VEHICLE_H_

#include <iostream>
#include "Package.h"
#include "Client.h"
#include <vector>
#include <limits>

using namespace std;


class Vehicle {
public:

	enum DeliveryStrategy {
		urgency,
		closest,
		first
	};
	enum DrivingMethod {
		euclid,
		manhattan
	};

	Vehicle() : speed(-1) {
	}

	Vehicle(float x, float y, DeliveryStrategy strategy, DrivingMethod drivingMethod, int speed, float maxWeight, float maxVolume, string driverName) :x(x), y(y), strategy(strategy),speed(speed), drivingMethod(drivingMethod), maxWeight(maxWeight),maxVolume(maxVolume), driverName(driverName)
	{
	}
	Vehicle(const Vehicle& val) :x(val.x), y(val.y), strategy(val.strategy),speed(val.speed),drivingMethod(val.drivingMethod), maxWeight(val.maxWeight),maxVolume(val.maxVolume), driverName(val.driverName) {

	}
	virtual ~Vehicle() {

	}

	Vehicle& operator=(const Vehicle& val);
	friend ostream& operator<<(std::ostream& out, const Vehicle& val);
	friend istream& operator>>(std::istream& in, Vehicle& val);
	
	void addClient(const Client& client);
	void addPackage(const Package& package);
	float goToClient(float currentTime, bool simulation=false);
	float goToPackage(float currentTime, bool simulation=false);
	float simulateDeliveryTime(const Client& client, float currentTime);
	bool canFit(const Package& package);
	void changeDeliveryStrategy(DeliveryStrategy deliveryStrategy);


	float calculateTime(float _x, float _y);
	float calculateDistance(float _x, float _y);
	void updateWeightVolume();

	const float getCurrentWeight() const;
	const float getCurrentVolume() const;
	const float getMaxWeight() const;
	const float getMaxVolume() const;
	const int getSpeed() const;
	const string getDriverName() const;
	const int getClientCount() const;
	const int getPackageCount() const;


protected:
	DeliveryStrategy strategy;
	DrivingMethod drivingMethod;
	vector<Package> packages;
	vector<Client> clients;
	float x;
	float y;
	const int speed;
	string driverName;

	float maxWeight;
	float maxVolume;
	float currentWeight=0;
	float currentVolume=0;

	bool changeStrategy = false;
	DeliveryStrategy queuedStrategy;
};

#endif