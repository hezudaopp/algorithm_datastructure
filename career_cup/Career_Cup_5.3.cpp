#include <iostream>

using namespace std;

#define LEN 32

bool getBit(int n, int index) {
	return ((n&(1<<index)) > 0);
}

void setBit(int &n, int index, bool b) {
	if (b) {
		n = n | (1<<index);
	} else {
		int mask = ~(1<<index);
		n = n & mask;
	}
}

int getNextNP(int &n) {
	int index = 0;
	int countOnes = 0;
	// from right to left, find the first 1
	while (!getBit(n, index) && index < LEN) {
		index++;
	}
	if (index >= LEN) return n;//n==0
	// from the first 1, find the first 0 left to it
	while (getBit(n, index) && index < LEN) {
		index++;
		countOnes++;
	}
	if (index >= LEN) return n;//n is the largest
	// set 0 to 1
	setBit(n, index, true);

	// Turn off previous one
	index--;
	setBit(n, index, false);
	countOnes--;
	for (int i=index-1; i>=0; i--) {
		setBit(n, i, false);
	}
	for (int i=0; i<countOnes; i++) {
		setBit(n, i, true);
	}
	return n;
}

int main(int argc, char *argv[]) {
	int n=1025;
	getNextNP(n);
	cout << n <<endl;
}