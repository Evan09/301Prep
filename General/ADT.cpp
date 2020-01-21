#include <iostream>
#include <stack>
#include <queue>
using namespace std;

int main23() {
	stack<double> stack;
	queue<string> queue;

	stack.push(30);
	stack.push(344);
	stack.push(69);
	cout << "Stack size is " << stack.size() << ".\n";
	cout << "Top of stack: " << stack.top() << "\n";
	stack.pop();
	stack.pop();
	cout << "Stack size is now " << stack.size() << " after popping twice.\n";
	cout << "Top of stack is now " << stack.top() << ".\n";

	if (!(stack.empty())) {
		stack.pop();
	}

	queue.push("first position");
	queue.push("second position");
	queue.push("third position");

	cout << "Front of queue: "  << queue.front() 
		 << ", back of queue: " << queue.back() 
		 << ", current size: "  << queue.size()
		 << endl;

	if (!queue.empty()) {
		queue.pop();
	}

	return 0;
}