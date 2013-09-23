#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int getKthOf357Factors (int k) {
	int i=0;
	queue<int> q3, q5, q7;
	q3.push(3);
	q5.push(5);
	q7.push(7);
	int x = 1;
	while (i < k) {
		x = min(min(q3.front(), q5.front()), q7.front());
		if (x == q3.front()) {
			q3.pop();
			q3.push(3*x);
			q5.push(5*x);
			q7.push(7*x);
		} else if (x == q5.front()) {
			q5.pop();
			q5.push(5*x);
			q7.push(7*x);
		} else {
			q7.pop();
			q7.push(7*x);
		}
		i++;
	}
	return x;
}

int main (char *argv[], int argc) {
	for (int i=1; i<=50; i++) {
		cout << getKthOf357Factors(i) << " ";
	}
	return 0;
}