#include <iostream>
#include <cstdlib>

using namespace std;

int **my2DAlloc(const int row, const int col) {
	if (row < 1 || col < 1) return 0;
	int **result = (int**)malloc(sizeof(int*)*sizeof(row));
	for (int i=0; i<row; i++) {
		result[i] = (int*)malloc(sizeof(int)*sizeof(col));
	}
	return result;
}

int **my2DAllocWithOneMalloc(const int row, const int col) {
	if (row < 1 || col < 1) return 0;
	int indexSize = sizeof(int *)*row;
	int dataSize = sizeof(int)*row*col;
	int **result = (int **)malloc(indexSize + dataSize);
	int *dataIndexStart = (int *)(result + row);
	for (int i=0; i<row; i++) {
		result[i] = dataIndexStart + i*col;
	}
	return result;
}

int main (char *argv[], int argc) {
	int **arr = my2DAllocWithOneMalloc(3,5);
	arr[0][1] = 2;
	cout << arr[0][1] << endl;
	return 0;
}