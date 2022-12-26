#ifndef TRAFFICLIGHT_H_
#define TRAFFICLIGHT_H_
#include "Place.h"
#include <iostream>
#include "constants.h"
using namespace std;


class TrafficLight {
private:
//pointer to first Place among four consecutive Places this Traffic light controls
Place *north;
Place *south;
Place *east;
Place *west;
//current state of Traffic light Red/Green/Yellow
traffic_state current_state;
//timing for Red/Green/Yellow Lights
int alltime;
int red_timer;
int green_timer;
int yellow_timer;
//timer value spend in current state
int current_timier = 0;
public:
TrafficLight(Place *placeN,Place *placeS,Place *placeE,Place *placeW, traffic_state state);
virtual ~TrafficLight();
void update();
};

#endif /* TRAFFICLIGHT_H_ */
