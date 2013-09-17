#include <iostream>
#include <algorithm>
#include <ctime>

using namespace std;

#define SIZE 1000
#define SUM 500

void printPairsOfSum(int arr[], int len, int sum) {
	sort(arr, arr+len);
	int left = 0, right = len-1;
	while (left < right) {
		int tmpSum = arr[left]+arr[right];
		if (tmpSum == sum) {
			cout << arr[left] << " " << arr[right] << endl;
			++left;
			--right;
			continue;
		} else {
			if (tmpSum > sum) {
				--right;
			} else {
				++left;
			}
		}
	}
}

int main (char *argv[], int argc) {
	srand(time(NULL));
	int arr[SIZE] = {};
	for (int i=0; i<SIZE; i++) {
		arr[i] = 500 - rand()%1000;
	}
	printPairsOfSum(arr, SIZE, SUM);
	return 0;
}