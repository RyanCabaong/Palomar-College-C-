#include <iostream>
#include <utility>
#include "Place.h"
#include "VehicleQueue.h"
#include "Vehicle.h"
//0 straight, 1 down, 2 east, 3 west
VehicleQueue::VehicleQueue(int dir) {
	this->dir = dir;
}

void VehicleQueue::insertVehicle(Vehicle* v){
	this->vehicles.push_front(v);
	front()->setFront(v);//sets the vehicle behind to have v in front
	v->setBack(front());//set v to have the front vehicle in queue behind
}

Vehicle* VehicleQueue::front(){
	return this->vehicles.front();
}
//return vehicle based on until empty?
//Vehicle* VehicleQueue::iterator(int n){
//
//}
Vehicle* VehicleQueue::back(){

	return this->vehicles.back();
}

bool VehicleQueue::isempty(){
	return this->vehicles.empty();
}

void VehicleQueue::pop(){
	this->vehicles.pop_front();
}

int VehicleQueue::size(){
	return this->vehicles.size();
}
VehicleQueue::~VehicleQueue() {

}
