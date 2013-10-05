#include <iostream>
#include <string>

using namespace std;

int binarySearch(string arr[], int left, int right, string target) {
	while (left <= right) {
		int midRight = (left+right)>>1;
		int midLeft = midRight;
		while (midRight <= right && arr[midRight].compare("") == 0) {
			midRight++;
		}
		if (target.compare(arr[midRight]) == 0) {
			return midRight;
		}
		else if (target.compare(arr[midRight]) > 0) {
			left = midRight + 1;
			continue;
		}
		while (midLeft >= left && arr[midLeft].compare("")) {
			midLeft--;
		}
		if (target.compare(arr[midLeft]) == 0) {
			return midLeft;
		} else if (target.compare(arr[midLeft])) {
			right = midLeft - 1;
			continue;
		}
		return -1;	// target > arr[midLeft] && target < arr[midRight]
	}
	return -1;
}

int search (string arr[], int len, string target) {
	if (target.compare("") == 0)
		return -1;
	return binarySearch(arr, 0, len-1, target);
}

int main (char *argv[], int argc) {
	const int size = 13;
	string arr[size] = {"at", "", "", "", "ball", "", "", "car", "", "", "dad", "", ""};
	for (int i=0; i<size; i++) {
		cout << search(arr, size, arr[i]) << endl;
	}
	return 0;
}