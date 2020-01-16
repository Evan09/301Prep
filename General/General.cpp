// General.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include "ClassExampleHeader.h"
using namespace std;

const int arrSize = 5;

int main() {
	// Data initilization
	int userValue;
	int array[arrSize];
	int sizeOfArray;
	int oddNumbers;

	string name = "";
	int height{ 5 };
	double weight = 175;

	// Basic I/O calls
	cout << "Enter your name: ";
	getline(cin, name);
	cout << "Hello " << name << ", please enter your weight(kg) and height(cm): ";
	cin >> weight >> height;
	cout << "\n";

	// Creating a class using a custom constructor (see ClassExample.cpp)
	BMI classExample(name, height, weight);

	classExample.showBMI();

	return 0;
}
