#include <iostream>

using namespace std;

int stepRightDown(int right, int down) {
	if (right == 1 || down == 1) {
		return 1;
	} else {
		return stepRightDown(right-1, down) + stepRightDown(right, down-1);
	}
}

int main (int argc, char *argv[]) {
	cout << stepRightDown(4,4) << endl;
}