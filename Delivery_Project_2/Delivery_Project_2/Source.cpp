#include <iostream>
#include "CEO.h"

using namespace std;

int main() {

	cout << "yes"<<endl;
	DeliveryCompany deliveryCompany(DeliveryCompany::closest, vector<Vehicle*>(0), "fedex");
	CEO manager("Coman Valentin",deliveryCompany);
	manager.startDay();


	system("pause");
	return 0;
}