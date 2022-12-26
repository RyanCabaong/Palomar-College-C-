#pragma once

#ifndef VEHICLE_H

#include <iostream>
#include <utility>

using namespace std;

#define VEHICLE_H

class Vehicle
{
private:
	pair<int, int> location;
	float weight, speed;
	char direction;  // N, S, E, W
	Vehicle* front;
	Vehicle* back;

public:
	Vehicle();//was & in pair
	Vehicle(pair<int, int>, float w, float sp, char d);

	Vehicle* getFront();
	Vehicle* getBack();
	void setFront(Vehicle* v);
	void setBack(Vehicle* v);

	pair<int, int> getlocation() const;
	void setlocation(pair<int, int>);
	virtual float getweight() const;
	virtual void setweight(float);
	float getspeed() const;
	void setspeed(float);
	char getdirection() const;
	void setdirection(char);

	virtual void move();
};


#endif
