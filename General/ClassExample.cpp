#include "ClassExampleHeader.h"

BMI::BMI() {
	name = "";
	height = 0;
	weight = 0;
}

BMI::BMI(string newName, int newHeight, double newWeight) {
	name = newName;
	height = newHeight;
	weight = newWeight;
}
