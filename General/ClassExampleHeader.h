#pragma once

#include <iostream>
#include <string>
using namespace std;

#ifndef CLASSEXAMPLEHEADER_H
#define CLASSEXAMPLEHEADER_H

class BMI {
public:
	BMI();
	BMI(string, int, double);

private:
	string name;
	int height;
	double weight;

};

#endif

