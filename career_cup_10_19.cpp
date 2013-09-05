#include <iostream>      /* printf, scanf, puts, NULL */
#include <cstdlib>     /* srand, rand */
#include <ctime>       /* time */

using namespace std;

int rand5() {
	return rand() % 5 + 1;
}

int rand7() {
	while (true) {
		int ran = rand5()*5 + rand5();
		if (ran > 6 && ran < 28) {
			return ran%7;
		}
	}
}

int main (int argc, char *argv[]) {
	/* initialize random seed: */
	srand (time(NULL));
	int count[7] ={0};
	for (int i=0; i<1000000; i++) {
		int j = rand7();
		count[j]++;
	}
	for (int i=0; i<7; i++)
		cout << count[i] << " ";
}