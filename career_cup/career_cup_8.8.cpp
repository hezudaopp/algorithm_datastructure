#include <iostream>
#include <stack>
#include <cmath>

#define SIZE 7

using namespace std;

int *col = new int[SIZE];
stack<int> s;
int count;

bool checkRow(int row) {
	for (int i=0; i<row; i++) {
		if (col[i] == col[row] || abs(col[i]-col[row]) == row-i) return false;
	}
	return true;
}

void placeQueen(int row, int size) {
	if (row == SIZE) {
		// for (int i=0; i<SIZE; i++) {
		// 	cout << col[i] << " ";
		// }
		// cout << endl;
		count ++;
		return;
	}
	for (int i=0; i<SIZE; i++) {
		col[row] = i;
		if (checkRow(row)) {
			placeQueen(row+1);
		}
	}
}


int main (int argc, char *argv[]) {
	placeQueen(0);
	cout << count << endl;
}