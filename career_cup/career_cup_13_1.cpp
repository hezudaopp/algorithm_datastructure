#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

#define INFILE "career_cup_13_1.cpp"

void printLastKLine(ifstream &ifs, int k) {
	string line;
	int firstGo = 0;
	int secondGo = 0;
	vector<string> allLines;
	while(getline(ifs, line)) {
		allLines.push_back(line);
		if (firstGo >= k) {
			secondGo++;
		}
		firstGo++;
	}
	for (int i=secondGo; i<allLines.size(); ++i) {
		cout << allLines[i] << endl;
	}
}

void printLastKLineWithKSpace(ifstream &ifs, const int k) {
	string line;
	string lastKLines[k];
	int i = 0;
	while (getline(ifs, line)) {
		lastKLines[i%k] = line;
		i++;
	}
	if (i < k) {
		for (int j=0; j<i; j++) {
			cout << lastKLines[j] << endl;
		}
	} else {
		int start = i%k;
		for (int count=0; count < k; count++) {
			cout << lastKLines[(start++)%k] << endl;
		}
	}
}

int main (char *argv[], int argc) {
	ifstream ifs(INFILE);
	// printLastKLine(ifs, 10);
	printLastKLineWithKSpace(ifs, 100);
	return 0;
}