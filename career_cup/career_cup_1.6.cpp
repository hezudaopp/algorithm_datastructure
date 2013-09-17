#include <string>
#include <iostream>
#include <cstring>

using namespace std;

#define SIZE 3

void rotate(int matrix[3][3]) {
	int tmp[3][3];
	// memcpy((int *)tmp, (int *)matrix, n*n);
	for (int i=0; i<SIZE; i++) {
		for (int j=0; j<SIZE; j++) {
			*((int *)tmp +i*SIZE +j) = *((int *)matrix +i*SIZE +j);
		}
	}
	for (int i=0; i<SIZE; i++) {
		for (int j=0; j<SIZE; j++) {
			*((int *)matrix + SIZE*j + SIZE-1-i) = *((int *)tmp +i*SIZE +j);
		}
	}
}

int main (int argc, char *argv[]) {
	int matrix[][SIZE] = {{1,2,3}, {4,5,6},{7,8,9}};
	rotate(matrix);
	for (int i=0; i<SIZE; i++) {
		for (int j=0; j<SIZE; j++) {
			cout << matrix[i][j] << endl;
		}
	}
}