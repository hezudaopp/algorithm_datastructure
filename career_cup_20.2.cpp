#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void shuffleCard(int cards[], int len) {
	srand(time(NULL));
	for (int i=len-1; i>=0; i--) {
		int index;
		if (i>0) index = rand()%i;
		else index = i+1;
		cards[index] = cards[index] ^ cards[i];
		cards[i] = cards[index] ^ cards[i];;
		cards[index] = cards[index] ^ cards[i];
	}
}

int main (int argc, char *argv[]) {
	int arr[52];
	for (int i=0; i<52; i++) {
		arr[i] = i+1;
	}
	shuffleCard(arr, 52);
	for (int i=0; i<52; i++) {
		cout << arr[i] << " ";
	}
	return 0;
}