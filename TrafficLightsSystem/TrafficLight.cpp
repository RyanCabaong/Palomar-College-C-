
#include "TrafficLight.h"

/*
 * 1) set timing
 * 2) set update
 * 3) block places before intersection
 */
TrafficLight::TrafficLight(Place *placeN, Place *placeS,Place *placeE,Place *placeW, traffic_state state) {
	this->alltime=0;
	this->yellow_timer = 6;
	this->red_timer = 0;
	this->green_timer = 0;
	//while creating Traffic light create set current state
	this->current_state = state;

	this->north = placeN;
	this->south = placeS;
	this->east = placeE;
	this->west = placeW;
	int val1, val2;
	cout << "enter green timing for current traffic light: " << endl;
	cin >> val1;
	this->green_timer = val1;

	//Ask user to enter timings of Green light in opposite directions seperated by space AKA RED TIME
	// like 100 200
	cout << "enter red timing: " << endl;
	cin >> val1 >> val2;
	this->red_timer = val1 + val2;

	//create the four places here?
	//NORTH AND SOUTH ARE STARTING AS GREEN
	//EAST AND WEST ARE STARTING RED!
	if(state==RED){
		north->setLight(0);//red
		south->setLight(0);//red
		east->setLight(1);//green
		west->setLight(1);//green
	}
	else if(state==GREEN){
		north->setLight(1);//green
		south->setLight(1);//green
		east->setLight(0);//red
		west->setLight(0);//red
	}
	else{//YELLOW
		north->setLight(2);//yellow
		south->setLight(2);//yellow
		east->setLight(2);//red
		west->setLight(2);//red
	}

}
//place must say isred=true to prevent vehicles moving into intersection on RED
void TrafficLight::update() {
	//increase the timer
	this->current_timier++;
	this->alltime++;
	switch (current_state) {
	case RED: {
		//if RED timer elapsed, go to Green
		if (this->current_timier >= this->red_timer) {
			//change all relevant lights to green and other to red
			north->setLight(1);//green
			south->setLight(1);//green
			east->setLight(0);//red
			west->setLight(0);//red
			//change state and timer
			this->current_state = GREEN;
			this->current_timier = 0;
		}

	}
	break;
	case YELLOW: {
		//if Yellow timer elapsed, go to REd
		if (this->current_timier >= this->yellow_timer) {
			north->setLight(0);//red
			south->setLight(0);//red
			east->setLight(1);//green
			west->setLight(1);//green
			this->current_state = RED;
			this->current_timier = 0;
		}

	}
	break;
	case GREEN: {
		//if GREEN timer elapsed, go to YELLOW
		if (this->current_timier >= this->green_timer) {
			north->setLight(2);//YELLOW
			south->setLight(2);//YE
			east->setLight(2);//YELLOW
			west->setLight(2);//YELLOW
			this->current_state = YELLOW;
			this->current_timier = 0;
		}

	}
	break;
	default:
		break;
	}
}

TrafficLight::~TrafficLight() {
	// TODO Auto-generated destructor stub
}
