#include <iostream>

using namespace std;

#define SIZE 10

int arr[SIZE][SIZE];

int catalan (int waitInStackNum, int inStackNum) {
	if (arr[waitInStackNum][inStackNum] != 0) return arr[waitInStackNum][inStackNum];
	if (waitInStackNum == 0) {
		arr[waitInStackNum][inStackNum] = 1;
		return arr[waitInStackNum][inStackNum];
	}
	if (inStackNum == 0) {
		arr[waitInStackNum][inStackNum] = catalan(waitInStackNum-1, 1);
	} else {
		arr[waitInStackNum][inStackNum] = catalan(waitInStackNum, inStackNum-1) + catalan(waitInStackNum-1, inStackNum+1);
	}
	return arr[waitInStackNum][inStackNum];
}

int main (char *argv[], int argc) {
	for (int i=0; i<SIZE; i++) {
		for (int j=0; j<SIZE; j++) {
			arr[i][j] = 0;
		}
	}
	cout << catalan(6, 0) << endl;
	return 0;
}