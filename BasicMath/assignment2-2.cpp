#include <string>
#include <iostream>

using namespace std;

int main() {
	//declarations
	float carCost, miles, mpg, gas, resale, efficiency, milesDriven, usedCarCost, total;
	cout << "Enter the cost of the car: ";
	cin >> carCost;
	cout << "Enter the miles driven in a year: ";
	cin >> miles;
	cout << "Enter current gas prices: ";
	cin >> gas;
	cout << "Enter the miles per gallon: ";
	cin >> mpg;

	//calculation of ownership for 5 years
	resale = carCost * 0.4;
	efficiency = gas / mpg;
	milesDriven = miles * efficiency * 5;
	usedCarCost = carCost - resale;
	total = usedCarCost + milesDriven;

	//print output
	cout << "Total cost of owning the car for five years: " << total;

	return 0;
}