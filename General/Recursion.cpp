#include <iostream>
using namespace std;


const int ARRSIZE = 5;

struct Node {
	int data;
	Node* next;
};

void appendToList(Node*&, int);

// ALL functions below will be implemented using recursion.
void printArrayRecursively(int[], int);
void printLinkedListRecursively(Node*);
int sumArray(int[], int);
int sumList(Node*);
int evenNumbers(int[], int);
int calcExponential(int, int);

// driver
int main6() {
	int array[ARRSIZE] = { 50 , 20, 434, 55, 3 };
	Node* head = nullptr;
	Node* linkedList = new Node;
	linkedList->data = 21;
	linkedList->next = NULL;

	head = linkedList;

	appendToList(linkedList, 23);
	appendToList(linkedList, 9);
	appendToList(linkedList, 76);
	appendToList(linkedList, 67);
	
	cout << "Array: ";
	printArrayRecursively(array, ARRSIZE);
	cout << "\nList: ";
	printLinkedListRecursively(head);
	

	cout << "\nSum of array elements: " << sumArray(array, ARRSIZE) << "\n";
	cout << "\nSum of list elements: " << sumList(head) << "\n";
	cout << "\nNumber of even number elements in the array: " << evenNumbers(array, ARRSIZE) << "\n";
	cout << "\n5 to the 5th power: " << calcExponential(5, 5) << "\n";

	return 0;
}

void appendToList(Node*& head, int element) {
	Node* newNode = new Node;
	newNode->data = element;
	newNode->next = NULL;

	if (head == NULL) {
		head = newNode;
	}
	else {
		Node* temp = head;
		while (temp->next != NULL) {
			temp = temp->next;
		}
		temp->next = newNode;
	}
}

void printArrayRecursively(int array[], int size) {
	static int counter;

	if (counter == size) {
		cout << endl;
		return;
	}
	else {
		cout << array[counter] << "\t";
		++counter;
		printArrayRecursively(array, size);
	}
}

void printLinkedListRecursively(Node* head) {
	if (head == NULL) {
		cout << "\n";
		return;
	}
	else {
		cout << head->data << "\t";
		printLinkedListRecursively(head->next);
	}
}

int sumArray(int array[], int size) {
	if (size <= 0) {
		return 0;
	}
	else {
		return (sumArray(array, size - 1) + array[size - 1]);
	}
}

int sumList(Node* head) {
	if (head == NULL) {
		return 0;
	}
	else {
		return (sumList(head->next) + head->data);
	}
}

int evenNumbers(int array[], int size) {
	static int count;

	if (size <= 0) {
		return count;
	}
	else {
		if (array[size] % 2 == 0) {
			++count;
		}
		return evenNumbers(array, size - 1);
	}

}

int calcExponential(int base, int exp) {
	if (exp == 1) {
		return base;
	}
	else {
		return base * calcExponential(base, exp - 1);
	}
}