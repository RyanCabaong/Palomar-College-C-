
#include <iostream>
#include <utility>
#include "Place.h"
#include "Vehicle.h"
#include "Constants.h"
#include "TrafficLight.h"
using namespace std;

Place::Place()
{
	loc = pair<int, int>(-1, -1);
	veh = NULL;
	N = NULL;
	S = NULL;
	E = NULL;
	W = NULL;
	light = 1;
}

Place::Place(pair<int, int> location)
{
	loc = location;
	veh = NULL;
	N = NULL;
	S = NULL;
	E = NULL;
	W = NULL;
	light = 1;
}

pair<int, int> Place::getlocation() const
{
	return loc;
}

void Place::setlocation(pair<int, int> location)
{
	loc = location;
}

void Place::setvehicle(Vehicle* v)
{
	veh = v;
}

Vehicle* Place::getvehicle()
{
	return veh;
}

void Place::setnorth(Place* north)
{
	N = north;
}

Place* Place::getnorth()
{
	return N;
}

void Place::setsouth(Place* south)
{
	S = south;
}

Place* Place::getsouth()
{
	return S;
}

void Place::seteast(Place* east)
{
	E = east;
}

Place* Place::geteast()
{
	return E;
}

void Place::setwest(Place* west)
{
	W = west;
}

Place* Place::getwest()
{
	return W;
}
//
void Place::setdirection(Place* north, Place* south, Place* east,
		Place* west)
{
	N = north;
	S = south;
	E = east;
	W = west;
}

bool Place::isoccupied() const
{
	return (veh == NULL);
}
void Place::setLight(int l){
	light = l;
}
bool Place::freeToMove(char dir){
	//checks if there is link to next place and whether its free (or occupied) and green
	//red = 0, green = 1, yellow = 2
	//return (next(dir).isoccupied());
	//if any vehicle in intersection than go
	if ((this->next(dir) != NULL) && this->next(dir)->isoccupied() && this->next(dir)->light==1){
		//if light is yellow but your vehicle is ahead than go
		return true;
	}



	return false;
}
//returns place object in direction of travel e.g. N,S,E,W
Place* Place::next(char dir){
	if(dir == 'N'){
		return N;//prev: N
	}
	else if(dir == 'S'){
		return S;
	}
	else if(dir == 'E'){
		return E;
	}
	else{
		return W;
	}
}

bool Place::isintersection() const
{
	if ((loc.first >= XMAX / 2) &&
			(loc.first <= (XMAX / 2 + 1)) &&
			(loc.second >= YMAX / 2) && //before: <=
			(loc.second <= (YMAX / 2 + 1))//before: >=
	)
		return true;
	else
		return false;
}



