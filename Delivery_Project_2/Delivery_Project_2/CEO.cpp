#include "CEO.h"

CEO & CEO::operator=(const CEO & val)
{
	this->name = val.name;
	this->deliveryCompany = val.deliveryCompany;
	this->currentTimers = val.currentTimers;
	this->currentTime = val.currentTime;

	return *this;
}

void CEO::startDay()	
{
	Car billy(0, 0, Vehicle::closest, 500, 2500, "billy");
	Truck jim(0, 0, Vehicle::urgency, true, 1500, 1200000,"jim");
	Scooter anna(0, 0, Vehicle::first, 50, 500,"anna");
	vector<Vehicle*> vehicles;
	vehicles.push_back(&billy);
	currentTimers.push_back(0);
	vehicles.push_back(&jim);
	currentTimers.push_back(0);
	vehicles.push_back(&anna);
	currentTimers.push_back(0);

	deliveryCompany.hireDrivers(vehicles);
	Package drugs(129, 523, 10, 100, false, Package::normal, 1, 950);
	Package beans(50, 1050, 3, 9, true, Package::normal, 2, 450);
	Package elephant(129, 321, 501, 2501, false, Package::normal, 3, 345);
	Package skittles(125, 525, 42, 499, false, Package::normal, 4, 390);
	Client drugDealer(20, 100, "Mr Coman", drugs);
	Client beanDealer(10, 12, "Mr Bean", beans);
	Client elephantDealer(50, 150, "ronald", elephant);
	Client skittlesDealer(120, 520, "Pepsiman", skittles);


	deliveryCompany.changeAllocationType(DeliveryCompany::closest);
	deliveryCompany.receiveCall(drugDealer,currentTime);
	deliveryCompany.receiveCall(beanDealer, currentTime);
	deliveryCompany.receiveCall(elephantDealer, currentTime);
	deliveryCompany.makePickups(currentTimers);
	deliveryCompany.makeDeliveries(currentTimers);

	updateCurrentTime();

	deliveryCompany.receiveCall(skittlesDealer, currentTime);
	deliveryCompany.makePickups(currentTimers);
	deliveryCompany.makeDeliveries(currentTimers);
	updateCurrentTime();
	cout <<"Current time is: "<< currentTime<<endl;


}

void CEO::updateCurrentTime()
{
	for (int i = 0; i < currentTimers.size(); i++)
		if (currentTime < currentTimers[i])
			currentTime = currentTimers[i];
	for (int i = 0; i < currentTimers.size(); i++)
		currentTimers[i] = currentTime;
}

ostream & operator<<(std::ostream & out, const CEO & val)
{
	out << "CEO named " << val.name << " who owns " << val.deliveryCompany.getName() << ".";
	return out;
}

istream & operator>>(std::istream & in, CEO & val)
{
	in >> val.name >> val.deliveryCompany;
	return in;
}
