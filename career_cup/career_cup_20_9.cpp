#include <iostream>
#include <queue>
#include <cstdlib>     /* srand, rand */
#include <ctime>       /* time */

using namespace std;

class mycomparison {
	bool reverse;
public:
	mycomparison(const bool& revparam=false) {
		reverse=revparam;
	}

	bool operator() (const int& lhs, const int&rhs) const {
		if (reverse) return (lhs>rhs);
		else return (lhs<rhs);
	}
};

class MidValueQueue {
	priority_queue<int, std::vector<int>, mycomparison> *belowPriorityQueue;
	priority_queue<int, std::vector<int>, mycomparison> *abovePriorityQueue;
public:
	MidValueQueue() {
		belowPriorityQueue = new priority_queue<int, std::vector<int>, mycomparison>(mycomparison());
		abovePriorityQueue = new priority_queue<int, std::vector<int>, mycomparison>(mycomparison(true));
	}

	int getMidValue () {
		if (!belowPriorityQueue->empty())
			return belowPriorityQueue->top();
	}

	void insertValue(int arg) {
		if (belowPriorityQueue->size() == abovePriorityQueue->size()) {
			if (arg > this->getMidValue()) {
				abovePriorityQueue->push(arg);
				belowPriorityQueue->push(abovePriorityQueue->top());
				abovePriorityQueue->pop();
			} else {
				belowPriorityQueue->push(arg);
			}
		} else {
			if (arg > this->getMidValue()) {
				abovePriorityQueue->push(arg);
			} else {
				belowPriorityQueue->push(arg);
				abovePriorityQueue->push(belowPriorityQueue->top());
				belowPriorityQueue->pop();
			}
		}
	}
};

int main (char *argv[], int argc) {
	/* initialize random seed: */
	srand (time(NULL));
	MidValueQueue midValueQueue;
	for (int i=0; i<1000; i++) {
		midValueQueue.insertValue(rand()%10000);
		cout << midValueQueue.getMidValue() << endl;
	}

	// MidValueQueue *midValueQueue = new MidValueQueue();
	// for (int i=0; i<1000; i++) {
	// 	midValueQueue->insertValue(rand()%10000);
	// 	cout << midValueQueue->getMidValue() << endl;
	// }

	return 0;
}