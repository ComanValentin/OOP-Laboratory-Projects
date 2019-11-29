#ifndef MANAGER_H_
#define MANAGER_H_

#include "DeliveryCompany.h"

class CEO {
public:
	CEO(){
	}
	CEO(string name, DeliveryCompany deliveryCompany) :name(name), deliveryCompany(deliveryCompany) {
	}
	CEO(const CEO& val) :name(val.name), deliveryCompany(val.deliveryCompany) {
	}

	~CEO() {

	}


	CEO& operator=(const CEO& val);
	friend ostream& operator<<(std::ostream& out, const CEO& val);
	friend istream& operator>>(std::istream& in, CEO& val);


	void startDay();
	void updateCurrentTime();

private:
	DeliveryCompany deliveryCompany;
	vector<float> currentTimers;	//each driver will have their own timer since the program isnt parallelized
	float currentTime=0.0f;			//will be updated with the current highest timer of a driver
	string name;
};

#endif