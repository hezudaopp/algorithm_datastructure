#include <iostream>

using namespace std;

int getLongestSum(int arr[], int len) {
	int max_sum = 0;
	int last_sum = 0;
	for (int i=0; i<len; i++) {
		last_sum += arr[i];
		if (max_sum < last_sum) {
			max_sum = last_sum;
		} else if (last_sum < 0) {
			last_sum = 0;
		}
	}
	return max_sum;
}

int main (int argc, char *argv[]) {
	int arr[] = {2, -8, 3, -2, 4, -10,7,9,2,4,7,2,-99};
	cout << getLongestSum(arr, sizeof(arr)/sizeof(int)) << endl;
	return 0;
}