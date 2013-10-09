#include <iostream>

using namespace std;

void print1ToNDigitMaxIndex (int n, char *num, int index) {
	if (index == n) {
		int i=0;
		while (num[i] == '0' && i<n-1) {
			i++;
		}
		cout << (num+i) << endl;
		return;
	}
	for (num[index] = '0'; num[index] <= '9'; num[index]++) {
		print1ToNDigitMaxIndex(n, num, index+1);
	}
}

void print1ToNDigitMax(int n) {
	if (n <= 0) return;
	char *num = new char[n];
	num[n] = '\0';
	print1ToNDigitMaxIndex(n, num, 0);
}

int main (char *argv[], int argc) {
	print1ToNDigitMax(3);
	return 0;
}