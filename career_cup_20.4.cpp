#include <iostream>

using namespace std;

unsigned count1(unsigned n) {
	if (n == 0) return 0;
	unsigned pow = 1, num = n;
	while (pow < n) {
		pow *= 10;
	}
	pow = pow/10;
	unsigned digit = num/pow;
	unsigned remainder = num%pow;
	unsigned result = 0;
	if (digit > 1) {
		result = digit*count1(pow-1) + count1(remainder) + pow;
	} else if (digit == 1){
		result = digit*count1(pow-1) + count1(remainder) + remainder + 1;
	}
	return result;
}

unsigned count1_2(unsigned n) {
	unsigned num = n, digit=0;
	unsigned pow = 1, powResult = 0, result = 0;
	while (num > 0) {
		digit = num % 10;
		int remainder = n%pow;
		result += digit*powResult;
		if (digit > 1) {
			result += pow;
		} else if (digit == 1) {
			result += remainder + 1;
		}
		powResult = 10*powResult  + pow;
		pow *= 10;
		num = n/pow;
	}
	return result;
}

int main (int argc, char *argv[]) {
	cout << count1(3376) << endl;
	cout << count1_2(3376) << endl;
	return 0;
}