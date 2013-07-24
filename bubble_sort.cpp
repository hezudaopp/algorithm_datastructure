#include <iostream>

using namespace std;

void swap (int &a, int &b) {
	a = a^b;
	b = a^b;
	a = a^b;
}

void bubble_sort (int arr[], int len) {
	bool is_swap = false;
	for (int i=0; i<len; i++) {
		for (int j=1; j<len; j++) {
			if (arr[j] < arr[j-1]) {
				swap (arr[j], arr[j-1]);
				is_swap = true;
			}
		}
		if (!is_swap) break;
	}
} 

int main (int argc, char *argv[]) {
	int arr[] ={23,45,1,23,57,5,43,3,1,2,34,7,5,5,4,3,22,6,5,23,2,2,1,5,6,6,12,68,4,3,2,18,4,33,9,76,8,9,0,0,94,32,1,5,6,100};
	int const size = sizeof(arr)/sizeof(int);
	bubble_sort(arr, size);
	for (int i=0; i<size; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
	return 0;
}