#include <iostream>

using namespace std;

int numOfZeros (unsigned num) {
	int result = 0;
	for (int i=5; i<num; i*=5)
		result += num/i;
	return result;
}

int main(char *argv[], int argc) {
	cout << numOfZeros(26) << endl;
	cout << numOfZeros(126) << endl;
	return 0;
}