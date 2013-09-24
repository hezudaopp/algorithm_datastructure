#include <iostream>
#include <stack>

using namespace std;

bool isPossiblePopQueueFromStack(int *target, int *src, int size) {
	stack<int> s;
	int j = 0;
	for (int i = 0; i < size; ++i) {
		s.push(src[i]);
		while (j < size && target[j] == s.top()) {
			j++;
			s.pop();
		}
	}
	if (j < size) return false;
	return true;
}

int main (char *argv, int argc) {
	int arrTarget[] = {2, 3, 5, 4, 1};
	int arrTarget1[] = {2, 3, 5, 1, 4};
	int arrSrc[] = {1, 2, 3, 4, 5};
	cout << isPossiblePopQueueFromStack(arrTarget, arrSrc, 5) << endl;
	cout << isPossiblePopQueueFromStack(arrTarget1, arrSrc, 5) << endl;
	return 0;
}