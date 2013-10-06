#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct human {
	int height;
	int weight;
	bool operator>(human h) {
		if (height > h.height && weight > h.weight) {
			return true;
		} else {
			return false;
		}
	}
};

typedef struct human hum;

bool mycompare (hum h1, hum h2) {
	if (h1.height < h2.height) {
		return true;
	} else if (h1.height > h2.height) {
		return false;
	} else {
		if (h1.weight <= h2.weight) {
			return true;
		} else {
			return false;
		}
	}
}

int getNextStartSequence (hum arr[], vector<hum> &curHumSequence, int len, int start) {
	hum lastHum;
	int result = start;
	for (int i=start; i<len; i++) {
		if (i == start || arr[i] > lastHum) {
			curHumSequence.push_back(arr[i]);
			lastHum = arr[i];
		} else if (result == start) {
			result = i;
		}
	}
	return result;
}

vector<hum> findMaxSequence (hum arr[], int len) {
	sort(arr, arr+len, mycompare);
	vector<hum> maxSequence, curSequence, nextSequence;
	int curStart = 0;
	int nextHumIndex = getNextStartSequence(arr, curSequence, len, curStart);
	maxSequence = curSequence;
	while (nextHumIndex > curStart) {
		curStart = nextHumIndex;
		nextSequence.clear();
		nextHumIndex = getNextStartSequence(arr, nextSequence, len, curStart);
		if (nextSequence.size() > maxSequence.size()) {
			maxSequence = nextSequence;
		}
	}
	return maxSequence;
}

int main (char *argv[], int argc) {
	hum arr[] = {{65, 88}, {70, 150}, {56, 90}, {75, 190}, {60, 85}, {69, 110}, {66, 77}, {67, 78}, {68, 79}};
	int size = sizeof(arr)/sizeof(hum);
	vector<hum> result = findMaxSequence(arr, size);
	for (int i=0; i<result.size(); i++) {
		cout << result[i].height << "-" << result[i].weight << " ";
	}
	return 0;
}