#include <iostream>
#include <cstring>

using namespace std;

void swap (int &a, int &b) {
	a = a^b;
	b = a^b;
	a = a^b;
}

void merge(int a[], int left, int mid, int right, int c[]) {
	for (int i=left; i <= right; i++) {
		c[i] = a[i];
	}
	int i=left, j=mid+1, k=left;
	while (i<=mid && j<=right) {
		if (a[i] <= c[j]) {
			a[k++] = c[i++];
		} else {
			a[k++] = c[j++];
		}
	}
	while (i<=mid) {
		a[k++] = c[i++];
	}
	while (j<=right) {
		a[k++] = c[j++];
	}
}

void sub_sort (int arr[], int left, int right, int result[]) {
	if (left < right) {
		int mid = (left+right)/2;
		sub_sort(arr, left, mid, result);
		sub_sort(arr, mid+1, right, result);
		merge(arr, left, mid, right, result);
	}
}

void merge_sort (int arr[], int const len) {
	int result[len];
	memset(result, 0, len);
	sub_sort(arr, 0, len-1, result);
}

int main (int argc, char *argv[]) {
	int arr[] ={23,45,1,23,57,5,43,3,1,2,34,7,5,5,4,3,22,6,5,23,2,2,1,5,6,6,12,68,4,3,2,18,4,33,9,76,8,9,0,0,94,32,1,5,6,100};
	int const size = sizeof(arr)/sizeof(int);
	merge_sort(arr, size);
	for (int i=0; i<size; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
	return 0;
}