#ifndef DELIVERY_COMPANY_H_
#define DELIVERY_COMPANY_H_

#include "Car.h"
#include "Truck.h"
#include "Scooter.h"
#include "Client.h"
#include "Package.h"

class DeliveryCompany {
public:
	enum AllocationType {
		closest,
		fastest,
		capacity
	};

	DeliveryCompany() {
		
	}

	DeliveryCompany(AllocationType allocationType, vector<Vehicle*> vehicles, string name):allocationType(allocationType),vehicles(vehicles), name(name) {

	}

	DeliveryCompany(const DeliveryCompany& val) : allocationType(val.allocationType), vehicles(val.vehicles), name(val.name) {

	}

	~DeliveryCompany() {
		while (vehicles.size() > 0) {
			vehicles.erase(vehicles.begin());
		}
	}

	DeliveryCompany& operator=(const DeliveryCompany& val);
	friend ostream& operator<<(std::ostream& out, const DeliveryCompany& val);
	friend istream& operator>>(std::istream& in, DeliveryCompany& val);


	void changeAllocationType(AllocationType val);

	void hireDriver(Vehicle& vehicle);
	void hireDrivers(vector<Vehicle*> vehicles);
	void receiveCall(const Client& client, const float currentTime);
	void makePickups(vector<float> &currentTimers);
	void makeDeliveries(vector<float> &currentTimers);

	string getTypeOfVehicle(Vehicle *vehicle);
	const string getName() const;

private:
	AllocationType allocationType;
	vector<Vehicle*> vehicles;
	string name;
};

#endif