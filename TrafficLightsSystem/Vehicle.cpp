
#include <iostream>
#include "Vehicle.h"

using namespace std;

Vehicle::Vehicle()
{
	location.first = -1;
	location.second = -1;
	weight = 0;
	speed = 0;
	direction = ' ';
}

//was &
Vehicle::Vehicle(pair<int,int> loc, float w, float sp, char d)
{
	location = loc;
	weight = w;
	speed = sp;
	direction = d;
	front=NULL;
	back=NULL;
}

void Vehicle::move(){
	//should use child methods instead

}

//new methods that return vehicle in front and behind each vehicle
Vehicle* Vehicle::getFront(){
	return front;
}
Vehicle* Vehicle::getBack(){
	return back;
}
void Vehicle::setFront(Vehicle* v){
	front = v;
}
void Vehicle::setBack(Vehicle* v){
	back = v;
}
pair<int, int> Vehicle::getlocation() const
{
	return location;
}

void Vehicle::setlocation(pair<int, int> loc)
{
	location = loc;
}

void Vehicle::setweight(float w)
{
	weight = w;
}

float Vehicle::getweight() const
{
	return weight;
}

float Vehicle::getspeed() const
{
	return speed;
}

void Vehicle::setspeed(float sp)
{
	speed = sp;
}

void Vehicle::setdirection(char d)
{
	direction = d;
}

char Vehicle::getdirection() const
{
	return direction;
}
