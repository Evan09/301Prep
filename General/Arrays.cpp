#include <vector>
#include <iostream>
using namespace std;


void swap(int*, int*);
void bubbleSort(int[], int);
void printArray(int[], int);
int oddSum(int[], int);
void combineArrayElements(int[], int, int[], int);
const int arraySize = 10;

int main() {
	int* p;
	int arr[5];
	int initArray[arraySize] = { 10, 23, 343, 1, 26 };
	int oddNumbers;
	int size = (sizeof(arr) / sizeof(arr[0]));

	cout << "Initial Array: ";
	printArray(initArray, size);

	// User inputting values into an array
	cout << "Enter values for an array(5 max): ";
	for (int i = 0; i < size; ++i) {
		cin >> arr[i];
	}

	cout << "Combining user input array into the sorted array...\n";
	combineArrayElements(initArray, arraySize, arr, size);
	cout << "Unsorted array: \n";
	printArray(initArray, arraySize);

	cout << "Sorted array: \n";
	bubbleSort(initArray, arraySize);
	printArray(initArray, arraySize);

	// Returns number of odd numbers
	oddNumbers = oddSum(initArray, arraySize);
	cout << "\n This array's odd numbers equates to a total of " << oddNumbers << ".\n\n";

	return 0;
}

void swap(int* x, int* y) {
	int temp = *x;
	*x = *y;
	*y = temp;
}

void bubbleSort(int arr[], int arrSize) {
	int i, j;
	for (i = 0; i < arrSize - 1; ++i) {
		for (j = 0; j < arrSize - i - 1; ++j) {
			if (arr[j] > arr[j + 1]) {
				swap(&arr[j], &arr[j + 1]);
			}
		}
	}
}

void printArray(int arr[], int arrSize) {
	cout << "[";

	for (int i = 0; i < arrSize; ++i) {
		if (i != arrSize - 1) {
			cout << arr[i] << ", ";
			continue;
		}
		cout << arr[i];
	}
	cout << "]\n";
}

int oddSum(int arr[], int arrSize) {
	int oddNumberTotal = 0;
	for (int i = 0; i < arrSize; ++i) {
		if (arr[i] % 2 == 0) {
			continue;
		}
		else {
			oddNumberTotal += arr[i];
		}
	}
	return oddNumberTotal;
}

void combineArrayElements(int arrOne[], int arrOneSize, int arrTwo[], int arrTwoSize) {
	for (int i = 0; i < arrOneSize; ++i) {
		arrOne[i + arrTwoSize] = arrTwo[i];
	}

}
