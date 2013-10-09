#include <iostream>

using namespace std;

#define isPowerOf2(X) !(X&(X-1))

int numberOf1(int x) {
	int count = 0;
	if (x < 0) {
		count++;
		x = -x;
	}
	while (x) {
		x = x & (x-1);
		count++;
	}
	return count;
}

int dif1OfTwoNumberInBinary(int m, int n) {
	return numberOf1(m^n);
}

int main (char *argv[], int argc) {
	cout << numberOf1(-9) << endl;
	cout << isPowerOf2(8) << endl;
	cout << dif1OfTwoNumberInBinary(10, 13) << endl;
	return 0;
}