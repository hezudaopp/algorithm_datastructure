#include <iostream>

using namespace std;

int getMaxWithoutComparasonOperator(int a, int b) {
	unsigned k = ((a-b) >> (sizeof(int)*8-1)) & 1;
	return a-k*(a-b);
}

int main (char *argv[], int argc) {
	cout << getMaxWithoutComparasonOperator(2, 3) << endl;
	cout << getMaxWithoutComparasonOperator(3, 2) << endl;
	return 0;
}