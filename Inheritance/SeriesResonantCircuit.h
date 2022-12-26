#pragma once

#ifndef SeriesResonantCircuit_H

#include <iostream>
#include <utility>
#include "ResonantCircuit.h"
using namespace std;

#define SeriesResonantCircuit_H

using namespace std;
class SRC : public ResonantCircuit {//SeriesResonantCircuit
public:
	SRC();
	SRC(double, double, double);

	double getR();//get Resistance 
	
	double getC();//get Capacitor
	
	double getL();//get Induction
	
	void display();
private:
	double R;//Resistance
	double C;//Capacitor
	double L;//Induction
};
#endif
