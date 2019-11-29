#include "Vehicle.h"


Vehicle & Vehicle::operator=(const Vehicle & val)
{
	this->x = val.x;
	this->y = val.y;
	this->strategy = val.strategy;
	this->drivingMethod = val.drivingMethod;
	this->packages = val.packages;
	this->clients = val.clients;
	this->maxWeight = val.maxWeight;
	this->maxVolume = val.maxVolume;

	return *this;
}

void Vehicle::addClient(const Client & client)
{
	clients.push_back(client);
}

void Vehicle::addPackage(const Package & package)
{
	currentWeight += package.getWeight();
	currentVolume += package.getVolume();
	packages.push_back(package);
}

float Vehicle::goToClient(float currentTime, bool simulation)
{
	try{
		float time = .0f;
		Client destination;
		float temp;
		int mini = 0;
		float minTime = 100000;
		float minDistance = 100000;
		switch (strategy) {
		case urgency:
			for (int i = 0; i < clients.size(); i++) {
				temp = clients.at(i).getPackage().timeUntilDeadline(currentTime);
				if (clients.at(i).getPackage().getDeadlineType() == Package::normal)
					if (minTime > temp) {
						minTime = temp;
						mini = i;
					}
			}
			destination = clients.at(mini);
			clients.erase(clients.begin() + mini);
			break;
		case closest:
			for (int i = 0; i < clients.size(); i++) {
				temp = calculateDistance(clients.at(i).getX(), clients.at(i).getY());

				if (minTime < temp) {
					minTime = temp;
					mini = i;
				}
			}
			destination = clients.at(mini);
			clients.erase(clients.begin() + mini);
			break;
		case first:
			destination = clients.at(0);
			clients.erase(clients.begin());
			break;
		}


		time = calculateTime(destination.getX(), destination.getY());
		x = destination.getX();
		y = destination.getY();
		addPackage(destination.getPackage());
		updateWeightVolume();
		if (!simulation) {
			cout <<driverName<< " picked up package from " << destination.getName() <<" at location "<<destination.getX()<<","<<destination.getY() <<" at " << currentTime + time << ". Current load: " <<currentWeight<<"."<< endl;
		}
		return time;
	}
	catch (const out_of_range & err) {
		cout << "You tried to send the driver to a new client when they had none left!";
	}
}

float Vehicle::goToPackage(float currentTime, bool simulation)
{
	try {
		float time = .0f;
		Package destination;

		float temp;
		int mini=0;
		float minTime = 100000;
		float minDistance = 100000;

		switch (strategy) {
		case urgency:
			for (int i = 0; i < packages.size(); i++) {
				temp = packages.at(i).timeUntilDeadline(currentTime);
				if (packages.at(i).getDeadlineType() == Package::normal)
					if (minTime > temp) {
						minTime = temp;
						mini = i;
					}
			}
			destination = packages.at(mini);
			packages.erase(packages.begin() + mini);
			break;
		case closest:
			for (int i = 0; i < packages.size(); i++) {
				temp = calculateDistance(packages.at(i).getX(), packages.at(i).getY());

				if (minTime < temp) {
					minTime = temp;
					mini = i;
				}
			}
			destination = packages.at(mini);
			packages.erase(packages.begin() + mini);
			break;
		case first:
			destination = packages.at(0);
			packages.erase(packages.begin());
			break;
		}


		time = calculateTime(destination.getX(), destination.getY());
		x = destination.getX();
		y = destination.getY();
		updateWeightVolume();
		if (!simulation) {
			cout << driverName<< " delivered package id " << destination.getId() <<" at location " << destination.getX() << "," << destination.getY() << " at " << currentTime + time << ". Current load: " <<currentWeight<<"."<< endl;
		}
		if (packages.size() == 0 && changeStrategy) {
			strategy = queuedStrategy;
			changeStrategy = false;
		}
		return time;
	}
	catch (const out_of_range& err) {
		cout << "You tried to send the driver to deliver a package when they had none left!";
	}
}

float Vehicle::simulateDeliveryTime(const Client & client, float currentTime)
{
	int id = client.getPackage().getId();
	bool returnValue;
	vector<Package> cpackages(packages);
	vector<Client> cclients(clients);
	float cx = x;
	float cy = y;
	addClient(client);
	while (clients.size() > 0)
		currentTime += goToClient(currentTime,true);
	while (packages.size() > 0) {
		currentTime += goToPackage(currentTime,true);
		bool found = false;
		for (int i = 0; i < packages.size(); i++)
			if (packages[i].getId() == id)
				found = true;
		if (!found)
		{
			if (currentTime > client.getPackage().getMp())
				returnValue = false;
			else returnValue = true;
			break;
		}
	}
	x = cx;
	y = cy;
	packages = cpackages;
	clients = cclients;

	return currentTime;
}

bool Vehicle::canFit(const Package & package)
{
	if(currentWeight+package.getWeight()>maxWeight || currentVolume+package.getVolume()>maxVolume)
		return false;
	else return true;
}

void Vehicle::changeDeliveryStrategy(DeliveryStrategy deliveryStrategy)
{
	changeStrategy = true;
	queuedStrategy = deliveryStrategy;
}

float Vehicle::calculateTime(float _x, float _y)
{
	float time = .0f;
	float distance = calculateDistance(_x, _y);

	time = distance / (float)speed;

	return time;
}

float Vehicle::calculateDistance(float _x, float _y)
{
	float distance = .0f;
	switch (drivingMethod) {
	case euclid:
		distance = sqrt((_x - x)*(_x - x) + (y - _y)*(y - _y));
		break;
	case manhattan:
		distance = abs(_y - y) + abs(_x - x);
		break;
	}
	return distance;
}

void Vehicle::updateWeightVolume()
{
	currentWeight = 0;
	currentVolume = 0;
	for (int i = 0; i < packages.size(); i++) {
		currentWeight += packages[i].getWeight();
		currentVolume += packages[i].getVolume();
	}
}

const float Vehicle::getCurrentWeight() const
{
	return currentWeight;
}

const float Vehicle::getCurrentVolume() const
{
	return currentVolume;
}

const float Vehicle::getMaxWeight() const
{
	return maxWeight;
}

const float Vehicle::getMaxVolume() const
{
	return maxVolume;
}

const int Vehicle::getSpeed() const
{
	return speed;
}

const string Vehicle::getDriverName() const
{
	return driverName;
}

const int Vehicle::getClientCount() const
{
	return clients.size();
}

const int Vehicle::getPackageCount() const
{
	return packages.size();
}

ostream & operator<<(std::ostream & out, const Vehicle & val)
{
	out << " driven by "<<val.driverName<<" with location (" << val.x << "," << val.y << "), maximum weight " << val.maxWeight << ", maximum volume " << val.maxVolume << ", that moves at " << val.speed<< " km/s";
	return out;
}

istream & operator>>(std::istream & in, Vehicle & val)
{
	in >> val.x >> val.y >> val.maxWeight >> val.maxVolume>>val.driverName;

	return in;
}
