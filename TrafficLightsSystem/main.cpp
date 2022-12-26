
#include <iostream>
#include <time.h>
#include <cstdlib>
#include <string>
#include "Road.h"
#include "Vehicle.h"
#include "Car.h"
#include "Truck.h"
#include "Bus.h"
#include "Motorcycle.h"
#include "Place.h"
#include "VehicleQueue.h"
#include "TrafficLight.h"
#include "Constants.h"


using namespace std;


int main()
{


	//0 north, 1 south, 2 east, 3 west
	// Set the random seed
	srand(time(0));

	//NORTH ROAD
	pair<int, int> locs[YMAX];

	for (int i = 0; i < YMAX; i++)
	{
		locs[i].first = XMAX / 2 + 1;//501(x)
		locs[i].second = i;//0 to 999(y)
	}
	//road implementation
	Road north_bound(locs, YMAX, 0);  // 0 = north bound
	VehicleQueue northq(0);

	//SOUTH
	for (int i = 0; i < YMAX; i++)
	{
		locs[i].first = XMAX / 2 - 1;//499(x)
		locs[i].second = i;//0 to 999(y)
	}
	//road implementation
	Road south_bound(locs, YMAX, 1);  // 1 = north bound
	VehicleQueue southq(1);

	//WEST
	for (int i = 0; i < XMAX; i++)
	{
		locs[i].first = i;//499(x)
		locs[i].second = YMAX / 2 + 1;//0 to 999(y)
	}
	//road implementation
	Road west_bound(locs, XMAX, 3);  // 3 = west bound
	VehicleQueue westq(3);

	// let start putting vehicles into the lanes
	//EAST ROAD
	for (int i = 0; i < XMAX; i++)
	{
		locs[i].first = i;//0 to 999 (x)
		locs[i].second = YMAX / 2 - 1;//499 (y)
	}
	Road east_bound(locs, YMAX, 2);// 2 = east bound
	VehicleQueue eastq(2);
	//spawning north vehicles
	for (int tm = 0; tm < 20; tm++)
	{
		int ncar = CAR_PROB * 1000;
		int ntruck = TRUCK_PROB * 1000;
		int nbus = BUS_PROB * 1000;
		int nmoto = MOTORCYCLE_PROB * 1000;

		int nrand = rand() % 1000;

		if (nrand < ncar)
		{
			// car arrives
			int index = north_bound.getfreeplace(0);

			// insert car into road
			Car* carN = new Car(pair<int, int>(XMAX / 2 + 1, index), 100, 50, 'N');
			//Vehicle* v = (Vehicle)carN;
			northq.insertVehicle(carN);

		}
		else if (nrand >= ncar && nrand < (ntruck+ncar))
		{
			int index = north_bound.getfreeplace(0);
			//truck arrives
			Truck* truckN = new Truck(pair<int, int>(XMAX / 2 + 1, index), 100, 50, 'N', 600, pair<int, int>(0, 0));
			northq.insertVehicle(truckN);
		}
		else if (nrand >= (ntruck + ncar) && nrand < (ntruck + ncar + nbus))
		{
			// bus arrives
			int index = north_bound.getfreeplace(0);

			Bus* busN = new Bus(pair<int, int>(XMAX / 2 + 1, index), 100, 50, 'N', "bus1", 6);//name, #ofpassengers
			northq.insertVehicle(busN);
		}
		else if (nrand >= (ntruck + ncar + nbus) &&
				nrand < (ntruck + ncar + nbus + nmoto))
		{
			int index = north_bound.getfreeplace(0);
			//motorcycle arrives
			Motorcycle* motoN = new Motorcycle(pair<int, int>(XMAX / 2 + 1, index), 100, 50, 'N', "Kawasaki");
			northq.insertVehicle(motoN);
		}
		else
		{
			// no vehicle arrives
		}
	}
	//spawning east vehicles
	for (int tm = 0; tm < 20; tm++)
	{
		int ncar = CAR_PROB * 1000;
		int ntruck = TRUCK_PROB * 1000;
		int nbus = BUS_PROB * 1000;
		int nmoto = MOTORCYCLE_PROB * 1000;

		int nrand = rand() % 1000;

		if (nrand < ncar)
		{
			// car arrives
			int index = east_bound.getfreeplace(2);

			// insert car into road
			Car* carE = new Car(pair<int, int>(index, YMAX/2), 100, 50, 'E');
			eastq.insertVehicle(carE);
		}
		else if (nrand >= ncar && nrand < (ntruck+ncar))
		{
			int index = east_bound.getfreeplace(2);
			//truck arrives
			Truck* truckE = new Truck(pair<int, int>(index, YMAX/2), 100, 50, 'E', 600, pair<int, int>(0, 0));
			eastq.insertVehicle(truckE);
		}
		else if (nrand >= (ntruck + ncar) && nrand < (ntruck + ncar + nbus))
		{
			// bus arrives
			int index = east_bound.getfreeplace(2);

			Bus* busE = new Bus(pair<int, int>(index, YMAX/2), 100, 50, 'E', "bus1", 6);//name, #ofpassengers
			eastq.insertVehicle(busE);
		}
		else if (nrand >= (ntruck + ncar + nbus) &&
				nrand < (ntruck + ncar + nbus + nmoto))
		{
			int index = east_bound.getfreeplace(2);
			//motorcycle arrives
			Motorcycle* motoE = new Motorcycle(pair<int, int>(index, YMAX/2), 100, 50, 'E', "Harley-Davidson");
			eastq.insertVehicle(motoE);
		}
		else
		{
			// no vehicle arrives
		}
	}
	//spawning south vehicles
	for (int tm = 0; tm < 20; tm++)
	{
		int ncar = CAR_PROB * 1000;
		int ntruck = TRUCK_PROB * 1000;
		int nbus = BUS_PROB * 1000;
		int nmoto = MOTORCYCLE_PROB * 1000;

		int nrand = rand() % 1000;

		if (nrand < ncar)
		{
			// car arrives
			int index = south_bound.getfreeplace(1);

			// insert car into road
			Car* carS = new Car(pair<int, int>(XMAX/2, index), 100, 50, 'S');
			southq.insertVehicle(carS);
		}
		else if (nrand >= ncar && nrand < (ntruck+ncar))
		{
			int index = south_bound.getfreeplace(1);
			//truck arrives
			Truck* truckS = new Truck(pair<int, int>(XMAX/2, index), 100, 50, 'S', 600, pair<int, int>(0, 0));
			southq.insertVehicle(truckS);
		}
		else if (nrand >= (ntruck + ncar) && nrand < (ntruck + ncar + nbus))
		{
			// bus arrives
			int index = south_bound.getfreeplace(1);

			Bus* busS = new Bus(pair<int, int>(XMAX/2, index), 100, 50, 'S', "bus1", 6);//name, #ofpassengers
			southq.insertVehicle(busS);
		}
		else if (nrand >= (ntruck + ncar + nbus) &&
				nrand < (ntruck + ncar + nbus + nmoto))
		{
			int index = south_bound.getfreeplace(1);
			//motorcycle arrives
			Motorcycle* motoS = new Motorcycle(pair<int, int>(XMAX/2, index), 100, 50, 'E', "Harley-Davidson");
			southq.insertVehicle(motoS);
		}
		else
		{
			// no vehicle arrives
		}
	}
	//spawning west vehicles
	for (int tm = 0; tm < 20; tm++)
	{
		int ncar = CAR_PROB * 1000;
		int ntruck = TRUCK_PROB * 1000;
		int nbus = BUS_PROB * 1000;
		int nmoto = MOTORCYCLE_PROB * 1000;

		int nrand = rand() % 1000;

		if (nrand < ncar)
		{
			// car arrives
			int index = west_bound.getfreeplace(3);

			// insert car into road
			Car* carW = new Car(pair<int, int>(index, YMAX/2 + 1), 100, 50, 'W');
			westq.insertVehicle(carW);
		}
		else if (nrand >= ncar && nrand < (ntruck+ncar))
		{
			int index = west_bound.getfreeplace(3);
			//truck arrives
			Truck* truckW = new Truck(pair<int, int>(index, YMAX/2 + 1), 100, 50, 'W', 600, pair<int, int>(0, 0));
			westq.insertVehicle(truckW);
		}
		else if (nrand >= (ntruck + ncar) && nrand < (ntruck + ncar + nbus))
		{
			// bus arrives
			int index = west_bound.getfreeplace(3);

			Bus* busW = new Bus(pair<int, int>(index, YMAX/2 + 1), 100, 50, 'W', "bus1", 6);//name, #ofpassengers
			westq.insertVehicle(busW);
		}
		else if (nrand >= (ntruck + ncar + nbus) &&
				nrand < (ntruck + ncar + nbus + nmoto))
		{
			int index = west_bound.getfreeplace(3);
			//motorcycle arrives
			Motorcycle* motoW = new Motorcycle(pair<int, int>(index, YMAX/2 + 1), 100, 50, 'W', "Harley-Davidson");
			westq.insertVehicle(motoW);
		}
		else
		{
			// no vehicle arrives
		}
	}
	//traffic lights
	//maybe four places? One TrafficLight?
	//place.cpp needs relationship with traffic light
	//traffic light class is nothing more than a time counter that increments
	Place* n = new Place(pair<int, int>(XMAX/2 + 1, YMAX/2 - 1));
	Place* e = new Place(pair<int, int>(XMAX/2 - 1, YMAX/2));
	Place* w = new Place(pair<int, int>(XMAX/2 + 2, YMAX/2 + 1));
	Place* s = new Place(pair<int, int>(XMAX/2, YMAX/2 + 2));

	//place these lights in roads? (iterate through vector until correct position is found and place the place light)
	//bring method in road that sets param place to place

	north_bound.setplace(n, YMAX/2 -1, 'N');
	south_bound.setplace(s, YMAX/2 +2, 'S');
	east_bound.setplace(e, XMAX/2 -1, 'E');
	west_bound.setplace(w, XMAX/2 +2, 'W');
	//dont forget replacing a place means requiring to set directional places for it too.
	//north_bound.getPlace(YMAX/2 - 1) = n;
	TrafficLight* light = new TrafficLight(n,s,e,w, GREEN);//NORTH AND SOUTH IS STARTING GREEN!
	//start process
	//move available vehicles on respec roads until all queues are empty, queues empty when last car pops out at border
	//implement when vehicle hits border to 1. make dissappear from map 2. pop out from queue
	//it falls out of loop when all is false

	//create iterators for each road
	Vehicle* ntemp = northq.front();
	Vehicle* stemp = southq.front();
	Vehicle* etemp = eastq.front();
	Vehicle* wtemp = westq.front();

	//Everything works up til this point onward

	while(!(northq.isempty() && southq.isempty() && eastq.isempty() && westq.isempty())){
		if(!(northq.isempty()))
		ntemp->move();

		if(!(southq.isempty()))
		stemp->move();

		if(!(eastq.isempty()))
		etemp->move();

		if(!(westq.isempty()))
		wtemp->move();
		//vehicles will auto delete at end when move() is used

		//checking if vehicles are at end
		int northend = northq.front()->getlocation().second;
		int southend = southq.front()->getlocation().second;
		int eastend = eastq.front()->getlocation().first;
		int westend = westq.front()->getlocation().first;

		if(northend == YMAX-1){
			if(!(northq.isempty()))
			northq.pop();
		}
		if(southend == 1){//or 0?
			if(!(southq.isempty()))
			southq.pop();
		}
		if(eastend == XMAX - 1){
			if(!(eastq.isempty()))
			eastq.pop();
		}
		if(westend == 1){
			if(!(westq.isempty()))
			westq.pop();
		}

		//process ends when all vehicle queues are empty
		//
		return 0;
	}
}

