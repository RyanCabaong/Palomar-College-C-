//#include <stdlib.h>
//#include <string>
#include <iostream>
//#include "pch.h"
//#include stdafx.h
using namespace std;

int main() {
	//computes the day of Easter Sunday based on input year
	//input
	int year;
	cout << "Enter a year: " << endl;
	cin >> year;

	//process
	int a = year % 19;
	int b = year / 100;
	int c = year % 100;
	int d = b / 4;
	int e = b % 4;
	int g = (8 * b + 13) / 25;
	int h = (19 * a + b * d * g + 15) % 30;
	int j = c / 4;
	int k = c % 4;
	int m = (a + 11 * h) / 319;
	int r = (2 + e + 2 * j - k - h + m + 32) % 7;
	int n = (h - m + r + 90) / 25;
	int p = (h - m + r + n + 19) % 32;

	//output
	cout << "a = " << a << ",b = " << b << ",c = " << c << ",d = " << d << ",e = " << e << ",g = " << g << ",h = " <<
		h << "\n,j = " << j << ",k = " << k << ",m = " << m << ",r = " << r << ",n = " << n << ",p = " << p;

	return 0;
}