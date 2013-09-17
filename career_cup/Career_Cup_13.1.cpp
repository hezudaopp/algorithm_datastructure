#include <iostream>
#include <fstream>
#include <string>

using namespace std;

#define K 5

int main (int argc, char *argv[]) {
	string lines[K];
	ifstream myfile ("Career_Cup_13.1.cpp");
	if (myfile.is_open()) {
		int i = 0;
		while (myfile.good()) {
			getline(myfile, lines[i%K]);
			i++;
		}
		if (i<=K) {
			int count = i;
			for (int j=0; j<count; j++) {
				cout << lines[i++] << endl;
			}
		} else {
			for (int j=0; j<K; j++) {
				cout << lines[i++%K] << endl;
			}
		}
	}
}