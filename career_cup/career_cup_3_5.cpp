#include <iostream>
#include <stack>

using namespace std;

class MyQueue {
private:
	stack<int> s1;
	stack<int> s2;

	void pushToS1 () {
		while (!s2.empty()) {
			s1.push(s2.top());
			s2.pop();
		}
	}

	void pushToS2() {
		while (!s1.empty()) {
			s2.push(s1.top());
			s1.pop();
		}
	}

public:
	void push (int v) {
		pushToS1();
		s1.push(v);
	}

	void pop () {
		pushToS2();
		s2.pop();
	}

	int front() {
		pushToS2();
		return s2.top();
	}

	int back() {
		pushToS1();
		return s1.top();
	}
};

int main (char *argv[], int argc) {
	MyQueue q;
	q.push(1);
	q.push(2);
	q.push(3);
	cout << q.front() << endl;
	cout << q.back() << endl;
	q.pop();
	cout << q.front() << endl;
	cout << q.back() << endl;
	return 0;
}