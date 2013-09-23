#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

#define FILENAME "2.in"
#define OUTFILE "2.out"

vector<int> v;

void buildFacbo(int size) {
	v.push_back(1);
	v.push_back(2);
	for (int i=2; i<size; i++) {
		v.push_back(v[i-1]+v[i-1]);
	}
}

void getPQOfIndex(int index, int &p, int &q) {
	int power = 1;
	int row = 0;
	while (power * 2 <= index) {
		power *= 2;
		row++;
	}
	int col = index-power;
	cout << row << " " << col << endl;
}

int getIndexOfPQ(int p, int q) {

	return 0;
}

int main(char *argv[], int argc) {
	buildFacbo(64);
	ifstream ifs(FILENAME);
	ofstream ofs(OUTFILE);
	int test;
	ifs >> test;
	for (int t=1; t <= test; t++) {
		int problemNumber;
		ifs >> problemNumber;
		if (problemNumber == 1) {
			int index;
			ifs >> index;
			int p, q;
			getPQOfIndex(index, p, q);
		} else if(problemNumber == 2) {
			int p, q;
			ifs >> p >> q;
		}
		ofs << "Case #" << t << ": ";
		if (t!=test) ofs << endl;
	}
	return 0;
}