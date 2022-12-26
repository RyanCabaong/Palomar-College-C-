#include <math.h>
#include <iostream>
#include "ParallelResonantCircuit.h"
#include "ResonantCircuit.h"
using namespace std;
//Constructor
PRC::PRC(){

}

PRC::PRC(double freq,double band,double gain){
	w = freq;
	B = band;
	k = gain;
}

double PRC::getR(){//get Resistance 1/r
	return getk();
}

double PRC::getC(){//1/BR
	//get Capacitor
	return 1 / (getB() * getR());
}

double PRC::getL(){
	//get Induction
	return 1 / (pow(getw(),2) * getC());
}
//overrides the display virtual method from parent class
void PRC::display(){
	cout<<"[Parallel Resonant Circuit]"<<endl;
	cout<<"(w) Resonance Frequency: "<<getw()<<", (B) Bandwidth: "<<getB()<<", (k) Gains: "<<getk()<<endl;
	cout<<"(R) Resistance: "<<getR()<<", (L) Induction: "<<getL()<<", (C) Capacitor: "<<getC()<<endl;
}
