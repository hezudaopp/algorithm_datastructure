#include <iostream>
#include <cmath>

using namespace std;

int getCentsWays (int n, int denom) {
	int next_denom = 0;
	switch (denom) {
		case 25:
			next_denom = 10;
			break;
		case 10:
			next_denom = 5;
			break;
		case 5:
			next_denom = 1;
			break;
		case 1:
			return 1;
	}
	int ways=0;
	for (int i=0; i*denom <= n; i++) {
		ways += getCentsWays(n-i*denom, next_denom);
	}
	return ways;
}

int main(int argc, char *argv[]) {
	cout << getCentsWays(4, 25) << endl;
	cout << getCentsWays(5, 25) << endl;
	cout << getCentsWays(8, 25) << endl;
	cout << getCentsWays(10, 25) << endl;
	cout << getCentsWays(13, 25) << endl;
	cout << getCentsWays(17, 25) << endl;
	cout << getCentsWays(20, 25) << endl;
	cout << getCentsWays(23, 25) << endl;
	cout << getCentsWays(25, 25) << endl;
	cout << getCentsWays(27, 25) << endl;
	cout << getCentsWays(50, 25) << endl;
	cout << getCentsWays(51, 25) << endl;
}