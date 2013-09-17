#include <iostream>

using namespace std;

int addWithoutArithemeticOperators(int a, int b) {
	if (b == 0) return a;
	int resultWithoutCarry = a ^ b;
	cout << resultWithoutCarry << " ";
	int carries = (a & b) << 1;
	cout << carries << endl;
	return addWithoutArithemeticOperators(resultWithoutCarry, carries);
}

int main (int argc, char *argv[]) {
	addWithoutArithemeticOperators(759, 674);
	// for (int i=1; i<1000; i++) {
	// 	for (int j=1; j<1000; j++) {
	// 		if (addWithoutArithemeticOperators(i, j) != i+j) {
	// 			cout << i << "," << j << endl;
	// 			i= 1001;
	// 			j = 1001;
	// 		}
	// 	}
	// } 
	return 0;
}