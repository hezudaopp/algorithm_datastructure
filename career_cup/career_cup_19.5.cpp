#include <iostream>

#define SIZE 4

using namespace std;

void getHits(int ans[], int slots[], int &hits, int &psu_hits) {
	for (int i=0; i<SIZE; i++) {
		if (ans[i] == slots[i]) {
			hits++;
			continue;
		}
		for (int j=0; j<SIZE && j!=i; j++) {
			if (ans[i] == slots[j]) {
				psu_hits++;
				break;
			}
		}
	}
	return;
}

int main (int argc, char *argv[]) {
	int ans[SIZE] = {'R','G','G','R'};
	int slots[SIZE] = {'G','Y','G','G'};
	int hits = 0, psu_hits = 0;
	getHits(ans, slots, hits, psu_hits);
	cout << hits << " " << psu_hits << endl;
	return 0;
}