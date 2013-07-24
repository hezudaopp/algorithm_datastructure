#include <iostream>

using namespace std;

int kth(int arr[], int start, int end, int k) {
	for (int l=start; l<=end; l++) cout << arr[l] << " ";
	cout << endl;
	int i=start;
	int v = arr[start];
	for (int j=i+1;j<=end; j++) {
		if (arr[j] < v) {
			i++;
			if (i != j) {
				arr[i] = arr[i] ^ arr[j];
				arr[j] = arr[i] ^ arr[j];
				arr[i] = arr[i] ^ arr[j];
			}
		}
	}
	if (i != start) {
		arr[i] = arr[i] ^ arr[start];
		arr[start] = arr[i] ^ arr[start];
		arr[i] = arr[i] ^ arr[start];
	}
	if (i == k) return v;
	else if (i > k) return kth(arr, start, i-1, k);
	else return kth(arr, i+1, end, k);
}

int kthMin (int arr[], int len, int k) {
	if (k<1 || k>len) return -1;
	return kth(arr, 0, len-1, k-1);
}

int main (int argc, char *argv[]) {
	int arr[] = {4,6,5,3,2,7,9,8};
	int len = sizeof(arr)/sizeof(int);
	cout << kthMin(arr, len, 7) << endl;
}