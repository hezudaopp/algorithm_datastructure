#include <stack>

using namespace std;

template <class t>
class minstack : public stack<t> {
	stack<t> minStack;
	void push(t val) {
		if (val <= min()) {
			minStack.push(val);
		}
		stack<t>::push(val);
	}

	void pop() {
		if (minStack.top() == stack<t>::top()) {
			minStack.pop();
		}
		stack<t>::pop();
	}

	t min() {
		if (!minStack.empty()) {
			return minStack.top();
		} else {
			return INT_MAX;
		}
	}
};

int main (char *argv[], int argc) {
	return 0;
}