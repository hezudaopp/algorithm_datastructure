#include <iostream>

#define SIZE sizeof(int)*8

using namespace std;

int addWithoutArithemeticOperators(int a, int b) {
	int result=0, carry = 0;
	int a_last, b_last, result_i;	
	for (int i=0; i<SIZE; i++) {
		a_last = a&1, b_last = b&1;
		cout << a_last << " " << b_last;
		result_i = a_last ^ b_last ^ carry;
		cout << " " << result_i;
		if ((a_last == 1 && b_last == 1) || (a_last == 1 && carry == 1) || (b_last == 1 && carry == 1)) carry =1;
		else carry = 0;
		result_i <<= i;
		result |= result_i;
		cout << " " << result << endl;
		a >>= 1;
		b >>= 1;
	}
	return result;
}

int main (int argc, char *argv[]) {
	cout << addWithoutArithemeticOperators(759,674) << endl;
	return 0;
}