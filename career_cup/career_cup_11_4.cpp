#include <iostream>

using namespace std;

class BitSet {
private:
	int *bits;
	int innerSize;

public:
	BitSet(const int size) {
		this->innerSize = sizeof(int)*8;
		bits = new int[size/this->innerSize];
	}

	void setBit(const int i) {
		if (i < 0 || i >= innerSize) return;
		int outterIndex = i/this->innerSize;
		int innerIndex = i%this->innerSize;
		// cout << outterIndex << " " << innerIndex << endl;
		bits[outterIndex] |= 1 << innerIndex; 
	}

	bool getBit(const int i) {
		if (i < 0 || i >= innerSize) return false;
		int outterIndex = i/this->innerSize;
		int innerIndex = i%this->innerSize;
		// cout << outterIndex << " " << innerIndex << endl;
		int result = 1 & (bits[outterIndex] >> innerIndex);
		return (result==1) ? true : false;
	}
};

int main (char *argv[], int argc) {
	BitSet bitSet(32000);
	bitSet.setBit(1000);
	cout << bitSet.getBit(1000) << endl;
	bitSet.setBit(0);
	cout << bitSet.getBit(0) << endl;
	bitSet.setBit(87280000);
	cout << bitSet.getBit(87280000) << endl;
	return 0;
}