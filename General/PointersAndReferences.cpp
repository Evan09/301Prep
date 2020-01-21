#include <iostream>
using namespace std;

void power(int&, int);
void swapPointers(int*&, int*&);

struct Person {
	string name = "";
	int age = 0;

};

int main3() {
	int n = 5;
	int x = 3;
	int valueOne = 23;
	int valueTwo = 5;
	int *p = &valueOne;
	int *g = &valueTwo;

	Person structObj;
	Person *structPtr = 0;

	structPtr = &structObj;

	Person personOne = { "Rei", 76 };

	struct Person personArray[3];
	personArray[0].name = "Oscar";
	personArray[0].age = 30;
	personArray[1].name = "Tommy";
	personArray[1].age = 19;
	personArray[2].name = "Vegeta";
	personArray[2].age = 9001;


	power(n, x);
	cout << n;

	cout << endl << "p = "<< *p << ", g = " << *g << " pre-swap\n";
	swapPointers(p, g);
	cout << "p = " << *p << ", g = " << *g << " swapped\n";

	structObj.name = "Evan";
	structObj.age = 24;

	cout << "\nOutputting struct object using a pointer...\n"
		<< "name: " << structPtr->name << "\nAge: " << structPtr->age;

	cout << "\n\nOutputting struct array using a loop...\n";
	for (int i = 0; i < 3; ++i) {
		cout << personArray[i].name << ", " << personArray[i].age << endl;
	}
	cout << "\n";
	
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
