#include <iostream>

using namespace std;

int countFactorialTrailingZeros (int n) {
	int zeros = 0;
	for (int i=5; i<=n; i*=5) {
		zeros += n/i;
	}
	return zeros;
}

int main (int argc, char *argv[]) {
	cout << countFactorialTrailingZeros(26) << endl;
}