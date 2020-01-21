#pragma once

template <typename T>
class Queue;

template <typename T>
class QNode {
	T data;
	QNode<T>* next;
	QNode<T>* prev;
	friend class Queue<T>;
	QNode() : next(nullptr), prev(nullptr) {}
};

template <typename T>
class Queue {
public:
	Queue();
	~Queue();
	int size();
	bool isEmpty();
	bool dequeue();
	bool enqueue(const T&);
	bool getFront(T&);
	bool getBack(T&);

private:
	QNode<T>* head;
	QNode<T>* tail;
	int numOfNodes;
	bool insertHelper(QNode<T>*, const T&);
	void removeHelper(QNode<T>*&);

};

template<typename T>
inline Queue<T>::Queue()
{
	head = new QNode<T>;
	tail = new QNode<T>;
	head->next = trail;
	trail->prev = head;
	numOfNodes = 0;
}

template<typename T>
inline Queue<T>::~Queue()
{
	while (!isEmpty()) {
		dequeue();
	}
	delete head;
	delete tail;
}

template<typename T>
inline int Queue<T>::size()
{
	return numOfNodes;
}

template<typename T>
inline bool Queue<T>::isEmpty()
{
	return (numOfNodes == 0);
}

template<typename T>
inline bool Queue<T>::dequeue()
{
	if (isEmpty()) {
		return false;
	}
	QNode<T> toRemove = head->next;
	removeHelper(toRemove);
	return true;
}

template<typename T>
inline bool Queue<T>::enqueue(const T &trail)
{
	return insertHelper(trail->prev, Element);
}

template<typename T>
inline bool Queue<T>::getFront(T &element)
{
	if (isEmpty()) {
		return false;
	}
	element = tail->prev->data;
	return true;
}

template<typename T>
inline bool Queue<T>::getBack(T &element)
{
	if (isEmpty()) {
		return false;
	}
	element = head->next->data;
	return true;
}

template<typename T>
inline bool Queue<T>::insertHelper(QNode<T>* predecesssor, const T &element)
{
	QNode<T>* newNode = new QNode<T>;
	if (newNode == nullptr) {
		return false;
	}
	newNode->data = element;
	QNode<T>* sucessor = predecesssor->next;
	predecesssor->next = newNode;
	successor->prev = newNode;
	newNode->next = sucessor;
	newNode->prev = predecesssor;
	++numOfNodes;
	return true;

}

template<typename T>
inline void Queue<T>::removeHelper(QNode<T>* &toRemove)
{
	QNode<T>* predecessor = toRemove->prev;
	QNode<T>* successor = toRemove->next;
	predecessor->next = successor;
	successor->prev = predecessor;
	delete toRemove;
	toRemove = nullptr;
	--numOfNodes;

}
