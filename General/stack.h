#pragma once

template <typename T>
class Stack;

template <typename T>
class SNode {
	T data;
	SNode<T>* next = nullptr;
	friend class Stack<T>;
	SNode() : next(nullptr) {}
};


template <typename T>
class Stack {
public:
	Stack();
	~Stack();
	int size();
	bool isEmpty();
	bool push(const T &);
	bool pop();
	bool top(T &);

private:
	SNode<T>* head;
	int numOfNodes;
};

template <typename T>
Stack<T>::Stack() {
	head = nullptr;
	numOfNodes = 0;
}

template<typename T>
Stack<T>::~Stack() {
	while (!isEmpty()) {
		pop();
	}
}

template<typename T>
inline int Stack<T>::size()
{
	return numOfNodes;
}

template<typename T>
inline bool Stack<T>::isEmpty()
{
	return (numOfNodes == 0);
}

template<typename T>
inline bool Stack<T>::push(const T &element)
{
	SNode<T>* newNode = new SNode<T>;
	if (newNode = nullptr) {
		return false;
	}
	newNode->data = element;
	newNode->next = head;
	head = newNode;
	++numOfNodes;

	return true;
}

template<typename T>
inline bool Stack<T>::pop()
{
	if (isEmpty) {
		return false;
	}
	SNode<T>* temp = head;
	head = head->next;
	delete front;
	front = nullptr;
	--numOfNodes;

	return true;
}

template<typename T>
inline bool Stack<T>::top(T &element)
{
	if (isEmpty) {
		return false;
	}
	element = head->data;
	return true;
}
