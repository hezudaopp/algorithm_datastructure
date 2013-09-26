#include <iostream>
#include <stack>
#include <queue>

using namespace std;

/**
 * 做这道题发现一个规律：队列中存在重复元素不影响算法效果。
 * 对于有两个重复的元素，如果出栈顺序在前面的元素对应到队列中的后面元素是合法的，那么出栈顺序在前面的元素对应到队列中的前面元素必然是合法的
 */

bool isPossiblePopQueueFromStack(int *target, int *src, int size) {
	stack<int> s;
	int j = 0;
	for (int i = 0; i < size; ++i) {
		s.push(src[i]);
		while (j < size && !s.empty() && target[j] == s.top()) {
			j++;
			s.pop();
		}
	}
	if (j < size) return false;
	return true;
}

bool isPossiblePopQueueFromStackWithRepeatableNumber (queue<int> waitQueue, stack<int> inStack, const vector<int> &srcQueue, int i, const int &size) {
	if (waitQueue.empty()) {
		return true;
	} else if (i==size && inStack.top() != waitQueue.front()) {
		return false;
	}
	if (!inStack.empty() && (inStack.top() == waitQueue.front())) {
		inStack.pop();
		waitQueue.pop();
		return isPossiblePopQueueFromStackWithRepeatableNumber(waitQueue, inStack, srcQueue, i, size);
	} else {
		inStack.push(srcQueue[i]);
		return isPossiblePopQueueFromStackWithRepeatableNumber(waitQueue, inStack, srcQueue, i+1, size);
	}
}

int main (char *argv, int argc) {
	int arrTarget[] = {1, 2, 1, 3};
	int arrSrc[] = {2, 1, 3, 1};
	cout << isPossiblePopQueueFromStack(arrTarget, arrSrc, sizeof(arrSrc)/sizeof(int)) << endl;
	vector<int> v(arrSrc, arrSrc + sizeof(arrSrc)/sizeof(int));
	queue<int> waitQueue;
	for (int i=0; i<sizeof(arrTarget)/sizeof(int); i++) {
		waitQueue.push(arrTarget[i]);
	}
	stack<int> inStack;
	cout << isPossiblePopQueueFromStackWithRepeatableNumber(waitQueue, inStack, v, 0, v.size()) << endl;
	return 0;
}