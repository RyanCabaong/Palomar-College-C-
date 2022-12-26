#ifndef VEHICLEQUEUE_H_
#define VEHICLEQUEUE_H_
#include"Vehicle.h"
#include <list>
#include <iterator>

using namespace std;


class VehicleQueue {
private:
int dir;
//list of places
list <Vehicle*> vehicles;
public:
VehicleQueue(int dir);
void insertVehicle(Vehicle* v);
Vehicle* front();//refered to as the head (where objects are pushed to as a tail)
Vehicle* back();
bool isempty();
void pop();
int size();
virtual ~VehicleQueue();
};

#endif /* VEHICLEQUEUE_H_ */
