#include <iostream>

using namespace std;

int getMin (int arr[], int left, int right) {
	int mid = left;
	while (left <= right) {
		if (right - 1 == left) {
			mid = right;
			break;
		}
		mid = (left+right)>>1;
		if (arr[mid] == arr[left] == arr[right]) {
			return min(getMin(arr, left, mid), getMin(arr, mid, right));
		}

		if (arr[mid] >= arr[left]) {
			left = mid;
		} else {
			right = mid;
		}
	}
	return arr[mid];
}

int getMinOfRotatedSortedArray (int arr[], int size) {
	return getMin (arr, 0, size-1); 
}

int main (char *argv[], int argc) {
	int arr[] = {1,3};
	cout << getMinOfRotatedSortedArray(arr, sizeof(arr)/sizeof(int));
	return 0;
}