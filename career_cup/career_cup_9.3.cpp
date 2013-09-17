#include <iostream>

using namespace std;

int binary_linear_search(int arr[], int left, int right, int v) {
	if (left > right) return -1;
	int mid = (left+right)/2;
	if (arr[mid] == v) return mid;
	else if (arr[left] <= arr[mid]) {
		if (v <= arr[mid] && v >= arr[left]) {
			binary_linear_search(arr, left, mid-1, v);
		} else {
			binary_linear_search(arr, mid+1, right, v);
		}
	} else {
		if (v <= arr[right] && v >= arr[mid]) {
			binary_linear_search(arr, mid+1, right, v);
		} else {
			binary_linear_search(arr, left, mid-1, v);
		}
	}
}

int main (int argc, char *argv[]) {
	int arr[] = {15,16,19,20,25,1,3,4,5,7,10,14};
	int size = sizeof(arr)/sizeof(int);
	for (int i=0; i<size; i++) {
		cout << binary_linear_search(arr, 0, size-1, arr[i]) << " ";
	}
	return 0;
}