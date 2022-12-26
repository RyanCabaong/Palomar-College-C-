
#include <iostream>
#include <cstdlib>
#include <utility>
#include "Car.h"
#include "Vehicle.h"
#include "Constants.h"
#include "Place.h"
using namespace std;
Car::Car()// : Vehicle(loc, w, sp, d)
{

	int n;
	n = rand() % 12;
	color = COLORS[n];
	placeptr[0] = NULL;  // front
	placeptr[1] = NULL;  // back

}

Car::Car(pair<int, int> loca, float w, float sp, char d) : Vehicle(loca, w, sp, d)
{
	int n = rand() % 12;
	loc = loca;
	color = COLORS[n];
	placeptr[0] = NULL;
	placeptr[1] = NULL;
}

string Car::getcolor() const
{
	return color;
}

void Car::setcolor(string c)
{
	color = c;
}

void Car::setplace(Place* front, Place* back)
{
	placeptr[0] = front;
	placeptr[1] = back;
}

Place** Car::getplace()
{
	return placeptr;
}

// this function assumes that we have determined that the next
// place is unoccupied
//recreate to check if the next place is valid and free by using new place methods! lets gooo
void Car::move()
{
	char dir;
	//pair<int, int> loc;

	dir = Vehicle::getdirection();//prev: no Vehicle [art

	//when either first or second hit next == 0 or max then delete
	//if(placeptr[0]->next(dir)->getlocation().first != 0 || placeptr[0]->next(dir)->getlocation().second != 0 ||
	//		placeptr[0]->next(dir)->getlocation().first != XMAX || placeptr[0]->next(dir)->getlocation().second != YMAX)
	if(placeptr[0]->freeToMove(dir)){
		cout<<"A Car moves!"<<endl;
		if (dir == 'N')//NORTH
			{
				//if the next place is out of bounds than NULL our standing
				if(placeptr[0]->next(dir) == NULL){
					loc.first=0;
					loc.second=0;
					placeptr[0] = NULL;
					placeptr[1] = NULL;
				}
				else{
					loc.second = loc.second + 1;
					placeptr[1] = placeptr[0];
					placeptr[0] = placeptr[0]->getnorth();
				}


			}
			else if (dir == 'S')//SOUTH
			{
				//if the next place is out of bounds than NULL our standing
				if(placeptr[0]->next(dir) == NULL){
					loc.first=0;
					loc.second=0;
					placeptr[0] = NULL;
					placeptr[1] = NULL;
				}
				else{
					loc.second = loc.second - 1;
					placeptr[1] = placeptr[0];
					placeptr[0] = placeptr[0]->getsouth();
				}
			}
			else if (dir == 'E')//EAST
			{
				//if the next place is out of bounds than NULL our standing
				if(placeptr[0]->next(dir) == NULL){
					loc.first=0;
					loc.second=0;
					placeptr[0] = NULL;
					placeptr[1] = NULL;
				}
				else{
					loc.second = loc.first + 1;
					placeptr[1] = placeptr[0];
					placeptr[0] = placeptr[0]->geteast();
				}
			}
			else//WEST
			{
				//if the next place is out of bounds than NULL our standing
				if(placeptr[0]->next(dir) == NULL){
					loc.first=0;
					loc.second=0;
					placeptr[0] = NULL;
					placeptr[1] = NULL;
				}
				else{
					loc.second = loc.first - 1;
					placeptr[1] = placeptr[0];
					placeptr[0] = placeptr[0]->getwest();
				}
			}
	}



	Vehicle::setlocation(loc);
}
