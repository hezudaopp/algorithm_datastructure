#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

#define FILENAME "C-large.in"
#define OUTFILE "C-large.out"

bool myfunction (int i,int j) { return (i>j); }

int main(char *argv[], int argc) {
	ifstream ifs(FILENAME);
	ofstream ofs(OUTFILE);
	int test;
	ifs >> test;
	for (int t=1; t <= test; t++) {
		int len;
		ifs >> len;
		vector<int> oddValues, evenValues;
		queue<int> oddIndexs, evenIndexs;
		for (int i=0; i<len; i++) {
			int tmp;
			ifs >> tmp;
			if (tmp%2==0) {
				evenValues.push_back(tmp);
				// evenMap.insert(pair<int, int>(i, tmp));
				evenIndexs.push(i);
			} else {
				oddValues.push_back(tmp);
				// oddMap.insert(pair<int, int>(i, tmp));
				oddIndexs.push(i);
				
			}
		}
		sort(evenValues.begin(), evenValues.end());
		sort(oddValues.begin(), oddValues.end(), myfunction);
		int arr[1000];
		while (!evenIndexs.empty()) {
			int tmpIndex = evenIndexs.front();
			arr[tmpIndex] = evenValues.back();
			evenValues.pop_back();
			evenIndexs.pop();
		}
		while (!oddIndexs.empty()) {
			int tmpIndex = oddIndexs.front();
			arr[tmpIndex] = oddValues.back();
			oddValues.pop_back();
			oddIndexs.pop();
		}
		ofs << "Case #" << t << ": ";
		for (int i= 0; i<len; i++) {
			ofs << arr[i];
			if (i != len-1) ofs << " ";
		}
		if (t!=test) ofs << endl;
	}
	return 0;
}