#include <iostream>
#include <cmath>
#include <ctime>

using namespace std;

#define SIZE 20

long long calculateRectangleSum(int arr[][SIZE], int xStart, int yStart, int xEnd, int yEnd) {
	if (xStart<0 || yStart<0 || xEnd>SIZE || yEnd>SIZE) return 0;
	if ((xStart > xEnd) || (yStart > yEnd)) return 0;
	long long result = 0;
	for (int i=yStart; i<=yEnd; i++) {
		for (int j=xStart; j<=xEnd; j++) {
			result += arr[i][j];
		}
	}
	return result;
}

void calculateAllSubMatrixSum(int arr[][SIZE], int x, int y, long long sumArr[][SIZE]) {
	for (int i=0; i<y; i++) {
		for (int j=0; j<x; j++) {
			sumArr[i][j] = calculateRectangleSum(arr, 0, 0, i, j);		
		}
	}
}

long long calculateSubMatrixSum(int xStart, int yStart, int xEnd, int yEnd, long long sumArr[][SIZE]) {
	return sumArr[yEnd][xEnd] + sumArr[yStart][xStart] - sumArr[yEnd][xStart] - sumArr[yStart][xEnd];
}

long long getMinSubMatrixSum(int arr[][SIZE]) {
	long long sumArr[SIZE][SIZE] = {0};
	calculateAllSubMatrixSum(arr, SIZE, SIZE, sumArr);
	long long result = arr[0][0];
	for (int yStart=0; yStart<SIZE; yStart++) {
		for (int xStart=0; xStart<SIZE; xStart++) {
			for (int yEnd=yStart; yEnd<SIZE; yEnd++) {
				for (int xEnd=xStart; xEnd<SIZE; xEnd++) {
					long long subMatrixSum = calculateSubMatrixSum(xStart, yStart, xEnd, yEnd, sumArr);
					// cout << subMatrixSum << endl;
					if (subMatrixSum > result) result = subMatrixSum;
				}
			}
		}
	}
	return result;
}

int main (char *argv[], int argc) {
	srand(time(NULL));
	int arr[SIZE][SIZE] = {0};
	for (int i=0; i<SIZE; i++) {
		for (int j=0; j<SIZE; j++) {
			rand()%3!=0 ? arr[i][j] = rand()%SIZE : arr[i][j] = 0-(rand()%SIZE);
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
	cout << getMinSubMatrixSum(arr) << endl;
	return 0;
}