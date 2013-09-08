#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

#define SIZE 100

int cells[SIZE][SIZE] = {0};

bool isBlackBorderSquare(int startX, int startY, int len) {
	int endX = startX+len-1, endY = startY+len-1;
	for (int i=startY; i<=endY; i++) {
		// left border
		if (cells[i][startX] == 1) return false;
		// right border
		if (cells[i][endX] == 1) return false;
	}

	for (int i=startX; i<=endX; i++) {
		// up border
		if (cells[startY][i] == 1) return false;
		// bottom border
		if (cells[endY][i] == 1) return false;
	}
	return true;
}

int maxSquareSizeWithBalckBoards() {
	int maxValue = 0;
	for (int col=0; col<SIZE; col++) {
		for (int borderSize = (SIZE-col); borderSize >= 1 || borderSize > maxValue; borderSize-- ) {
 			int startX = col;
 			int startYMax = SIZE-borderSize;
 			for (int i=0; i<=startYMax; i++) {
 				if (isBlackBorderSquare(startX, i, borderSize)) {
  					if (borderSize>maxValue)
 						maxValue = borderSize;
 					if (SIZE-col<=maxValue)
 						return maxValue;
 				}
 			}
		}
	}
	return maxValue;
}

int main (char *argv[], int argc) {
	srand(time(NULL));
	for (int i=0; i<SIZE; i++) {
		for (int j=0; j<SIZE; j++) {
			cells[i][j] = rand()%2;
			// cells[i][j] = 0;
			cout << cells[i][j] << " ";
		}
		cout << endl;
	}

	cout << maxSquareSizeWithBalckBoards() << endl;
	return 0;
}