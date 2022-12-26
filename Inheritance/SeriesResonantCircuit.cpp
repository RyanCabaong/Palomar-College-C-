#include <math.h>
#include <iostream>
#include "SeriesResonantCircuit.h"
#include "ResonantCircuit.h"
//Constructor
SRC::SRC(){

}


SRC::SRC(double freq,double band,double gain){
	w = freq;
	B = band;
	k = gain;
}
//Resistance
double SRC::getR(){//get Resistance 1/r
	return (1 / getk());
}

double SRC::getC(){
	//get Capacitor
	return 1 / (pow(getw(),2) * getL());
}

double SRC::getL(){
	//get Induction
	return getR() / getB();
}
//overrides the display virtual method from parent class
void SRC::display(){
	cout<<"[Series Resonant Circuit]"<<endl;
	cout<<"(w) Resonance Frequency: "<<getw()<<", (B) Bandwidth: "<<getB()<<", (k) Gains: "<<getk()<<endl;
	cout<<"(R) Resistance: "<<getR()<<", (L) Induction: "<<getL()<<", (C) Capacitor: "<<getC()<<endl;
}
