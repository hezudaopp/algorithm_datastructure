#include <iostream>

using namespace std;

#define parent(i) i/2
#define left_child(i) i*2+1
#define right_child(i) i*2+2

void swap (int &a, int &b) {
	a = a^b;
	b = a^b;
	a = a^b;
}

void maxify_heap(int arr[], int len, int i) {
	int largest_index = i;
	if (left_child(i) < len && arr[largest_index] < arr[left_child(i)]) {
		largest_index = left_child(i);
	}
	if (right_child(i) < len && arr[largest_index] < arr[right_child(i)]) {
		largest_index = right_child(i);
	}
	if (largest_index != i) {
		swap(arr[i], arr[largest_index]);
		maxify_heap(arr, len, largest_index);
	}
}

void build_heap(int arr[], int len) {
	for (int i=len/2-1; i>=0; i--) {
		maxify_heap(arr, len, i);
	}
}

void heap_sort(int arr[], int len) {
	build_heap(arr, len);
	while (len > 1) {
		swap(arr[0], arr[len-1]);
		maxify_heap(arr, --len, 0);
	}
}

int main(int argc, char *argv[]) {
	int arr[] ={23,45,1,23,57,5,43,3,1,2,34,7,5,5,4,3,22,6,5,23,2,2,1,5,6,6,12,68,4,3,2,18,4,33,9,76,8,9,0,0,94,32,1,5,63};
	int len = sizeof(arr)/sizeof(int);
	heap_sort(arr, len);
	for (int i=0; i<len; i++ ) {
		cout << arr[i] << " ";
	}
	cout << endl;
	return 0;
}