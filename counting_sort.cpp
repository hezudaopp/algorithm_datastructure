#include <iostream>
#include <cstring>

using namespace std;

#define MAX 100

void countingSort(int arr[], int size, int b[]) {
	// sizeof (arr) == 4
	// memcpy(b, arr, size);
	int c[MAX] = {0};
	for (int i=0; i<size; i++) {
		c[arr[i]]++;
	}
	for (int i=1; i<MAX; i++) {
		c[i] += c[i-1];
	}
	for (int i=size-1; i>=0; i--) {
		b[c[arr[i]]] = arr[i];
		c[arr[i]]--;
		cout << i << " " << arr[i] << " " << c[arr[i]] << " " << b[c[arr[i]]] << endl;
	}
}

int main(int argc, char *argv[]) {
	int arr[] ={23,45,1,23,57,5,43,3,1,2,34,7,5,5,4,3,22,6,5,23,2,2,1,5,6,6,12,68,4,3,2,18,4,33,9,76,8,9,0,0,94,32,1,5,6};
	unsigned const size = sizeof(arr)/sizeof(int);
	int b[size]={0};
	countingSort(arr, size, b);
	for (int i=0; i<size; i++) {
		cout << b[i] << " ";
	}
	cout << endl;
}