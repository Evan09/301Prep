#include <iostream>
using namespace std;

void insertFront(struct Node*&, int);
void appendElement(Node*&, int);
void insertElement(Node*&, int, int);
void printList( Node*&);
void deleteList( Node*&);
void combineLists( Node*&, Node*&);
Node* copyList(Node*&);


struct Node {
	int data = NULL;
	Node* next = NULL;
};

int main5() {
	Node* head = nullptr;
	Node* list1 = new Node;
	Node* list2 = new Node;
	Node* list3[5];

	for (int i = 0; i < 5; ++i) {
		list3[i] = NULL;
	}

	appendElement(list3[0], 25);
	appendElement(list3[1], 9);
	appendElement(list3[2], 234);
	appendElement(list3[3], 365);
	appendElement(list3[4], 3);
	for (int i = 0; i < 5; ++i) {
		printList(list3[i]);
	}
	
	head = list1;


	for (int i = 0; i < 5; ++i) {
		appendElement(head, i);
	}

	head = list2;

	for (int i = 0; i < 5; ++i) {
		appendElement(head, i + 4);

	}

	printList(list1);
	printList(list2);


	return 0;
}

void insertFront(Node *&head, int element) {
	Node* newNode = new Node;
	newNode->data = element;
	newNode->next = head;

	head = newNode;
}

void printList(Node *&head) {
	Node* temp = head;
	cout << "Node list: ";

	while (temp != NULL) {
		cout << temp->data << "\t";
		temp = temp->next;
	}
	cout << "\n";

}

void appendElement(Node*& head, int element) {
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

void insertElement(Node *&head, int element, int target) {
	int index = 0;
	Node* newNode = new Node;
	newNode->data = element;
	newNode->next = NULL;

	Node* temp;
	temp = head;

	while (index != target) {
		temp = temp->next;
		index++;
	}

	temp->next = newNode;
}

void deleteList(Node *&head) {
	Node* current = head;
	Node* next;

	while (current != NULL) {
		next = current->next;
		free(current);
		current = next;
	}

	head = NULL;
}


void combineLists(Node *&headOne, Node *&headTwo) {

}

Node* copyList(Node *&targetList) {
	Node* newNode = new Node;

	return newNode;
}