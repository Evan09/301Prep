#include <iostream>
using namespace std;

void power(int&, int);
void swapPointers(int*&, int*&);
int main() {
	int n = 5;
	int x = 3;
	int valueOne = 23;
	int valueTwo = 5;
	int *p = &valueOne;
	int *g = &valueTwo;
	

	power(n, x);
	cout << n;

	cout << endl << "p = "<< *p << ", g = " << *g << " pre-swap\n";
	swapPointers(p, g);
	cout << "p = " << *p << ", g = " << *g << " swapped\n";

	return 0;
}

void power(int& base, int exp) {
	int sum = 1;
	for (int i = 0; i < exp; ++i) {
		sum *= base;
	}
	base = sum;
}

void swapPointers(int*& ptr1, int*& ptr2) {
	int temp = *ptr1;
	*ptr1 = *ptr2;
	*ptr2 = temp;
}
