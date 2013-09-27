#include <iostream>

using namespace std;

void merge (int arr[], int left, int mid, int right) {
	// if (mid+1 == right) return;
	const int size = right - mid + 1;
	int *tmpArr = new int[size];
	int i=0;
	while (i<size) {
		tmpArr[i] = arr[mid+i];
		i++;
	}
	i--;
	mid--;
	while (mid >= left && i>=0) {
		if (arr[mid] > tmpArr[i]) {
			arr[right--] = arr[mid--];
		} else {
			arr[right--] = tmpArr[i--];
		}
	}
	while (i>=0) {
		arr[right--] = tmpArr[i--];
	}
	delete tmpArr;
}

void mergeSort (int arr[], int left, int right) {
	// cout << left << " " << right << endl;
	if (left < right) {
		int mid = (left+right)/2;
		mergeSort(arr, left, mid);
		mergeSort(arr, mid+1, right);
		merge(arr, left, mid+1, right);
		// for (int j=left; j<=right; j++) {
		// 	cout << arr[j] << " ";
		// }
		// cout << endl;

	}
}

void mergeSort (int arr[], int len) {
	mergeSort (arr, 0, len-1);
}

int main (char *argv[], int argc) {
	int arr[] = {5,4,3,4,52,1,4,2,1,3,5,7,8,6,5,4,3,3,45,6,7,8,99,0,0,97,7,5,5,5,4,4,3,22,0};
	int len = sizeof(arr)/sizeof(int);
	mergeSort(arr, len);
	for (int i=0; i<len;i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
	return 0;
}