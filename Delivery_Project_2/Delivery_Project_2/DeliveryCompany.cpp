#include "DeliveryCompany.h"


DeliveryCompany & DeliveryCompany::operator=(const DeliveryCompany & val)
{

	this->allocationType = val.allocationType;
	this->vehicles = val.vehicles;
	this->name = val.name;

	return *this;
}

void DeliveryCompany::changeAllocationType(AllocationType val)
{
	allocationType = val;
}

void DeliveryCompany::hireDriver(Vehicle & vehicle)
{
	vehicles.push_back(&vehicle); 
	cout << "A new ";
	switch ((&vehicle)->getSpeed()) {
	case 5:
		cout << "truck";
		break;
	case 10:
		cout << "car";
		break;
	case 20:
		cout << "scooter";
		break;

	}
	cout<<" has been hired!"<<endl;
}

void DeliveryCompany::hireDrivers(vector<Vehicle*> vehicles)
{
	for (int i = 0; i < vehicles.size(); i++) {
		hireDriver(*vehicles[i]);
	}
}

void DeliveryCompany::receiveCall(const Client & client, const float currentTime)
{
	cout <<client.getName() << " has called in with a delivery request." << endl;

	float minDistance = 100000;
	int mini=-1;
	float minTime = 100000;
	float simTime;
	float maxWeight=0;
	float load;

	vector<Vehicle*> selection;

	if (client.getPackage().isCold())
	{
		for (int i = 0; i < vehicles.size(); i++) {
			if (vehicles[i]->getSpeed()==5)
			{
				if (dynamic_cast<Truck*>(vehicles[i])->canCarryCold()) {
					selection.push_back(vehicles[i]);
				}
			}
		}
	}
	else {
		selection = vehicles;
	}

	for (int i = 0; i < selection.size(); i++) {
		if (selection[i]->canFit(client.getPackage()) && selection[i]->simulateDeliveryTime(client,currentTime)<client.getPackage().getMp())
		{
			switch (allocationType) {
			case closest:
				if (selection[i]->calculateDistance(client.getX(), client.getY()) < minDistance)
				{
					minDistance = selection[i]->calculateDistance(client.getX(), client.getY());
					mini = i;
				}
				break;
			case fastest:
				simTime = selection[i]->simulateDeliveryTime(client, currentTime);
				if (simTime < minTime) {
					minTime = simTime;
					mini = i;
				}
				break;
			case capacity:
				load = selection[i]->getMaxWeight() - selection[i]->getCurrentWeight();
				if (load > maxWeight) {
					maxWeight = load;
					mini = i;
				}
				break;
			}
		}
	}

	if (mini == -1) {
		cout << "The package from " << client.getName() << " cant be delivered in time or doesnt fit into any drivers' cars and so it was refused." << endl;
	}
	else {
		cout << "The package from " << client.getName() << " has been allocated to our driver " <<selection[mini]->getDriverName()<<" who has a "<< getTypeOfVehicle(selection[mini])<<"."<<endl;
		selection[mini]->addClient(client);
	}

}
void DeliveryCompany::makePickups(vector<float>& currentTimers)
{
	for (int i = 0; i < vehicles.size(); i++) {
		int clientCount = vehicles[i]->getClientCount();
		for (int j = 0; j < clientCount; j++) {
			currentTimers[i] += vehicles[i]->goToClient(currentTimers[i]);
		}
	}
}
void DeliveryCompany::makeDeliveries(vector<float>& currentTimers)
{
	for (int i = 0; i < vehicles.size(); i++) {
		int packageCount = vehicles[i]->getPackageCount();
		for (int j = 0; j < packageCount; j++)
			currentTimers[i] += vehicles[i]->goToPackage(currentTimers[i]);
	}
}
string DeliveryCompany::getTypeOfVehicle(Vehicle * vehicle)
{
	string retValue= " ";
	switch (vehicle->getSpeed()) {
	case 5:
		retValue= "truck";
		break;
	case 10:
		retValue= "car";
		break;
	case 20:
		retValue= "scooter";
		break;

	}
	return retValue;
}
const string DeliveryCompany::getName() const
{
	return name;
}

ostream & operator<<(std::ostream & out, const DeliveryCompany & val)
{
	out << "Company called " << val.name << " which employs the following vehicle drivers:";
	for (int i = 0; i < val.vehicles.size(); i++)
		switch (val.vehicles[i]->getSpeed()) {
		case 5:
			out << *dynamic_cast<Truck*>(val.vehicles[i]) << endl;
			break;
		case 10:
			out << *dynamic_cast<Car*>(val.vehicles[i]) << endl;
			break;
		case 20:
			out << *dynamic_cast<Scooter*>(val.vehicles[i]) << endl;
			break;

		}

	return out;
}

istream & operator>>(std::istream & in, DeliveryCompany & val)
{
	in >> val.name;
	for (int i = 0; i < val.vehicles.size(); i++)
		in >> *val.vehicles[i];
	return in;
}
