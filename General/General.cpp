// General.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <cmath>
#include <iostream>
#include "ClassExampleHeader.h"
using namespace std;

int main() {

	string name = "";
	int height{ 6 };
	double weight = 175;

	cout << "Enter your name: ";
	getline(cin, name);
	cout << "Hello, " << name << "." << endl;



	BMI classExample(name, height, weight);












	return 0;
}


