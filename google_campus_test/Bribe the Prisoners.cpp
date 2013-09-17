#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

#define INFILE "C-large-practice.in"
#define OUTFILE "C-large-practice.out"

long long minimumNumberOfGoldCoins (int left, int right, vector<int> posArr, int lastPosIndex, int posLeft, int posRight) {
	// cout << left << " " << right << endl;
	if (posLeft > lastPosIndex) return 0;
	if (posRight < 0) return 0;
	if (posLeft > posRight) return 0;
	if (posLeft == posRight) return right - left;
	int mid = (left+right)/2+1;
	int midPos = posLeft;
	int i;
	for (i=posLeft; i<posRight; i++) {
		if ( (mid - posArr[i]) <= 0 ) break;
	}
	if (i > posLeft) {
		(mid - posArr[i-1]) > (posArr[i] - mid) ? midPos = i : midPos = i-1;
	}
	// cout << midPos << " ";
	return (right - left) + (minimumNumberOfGoldCoins(left, posArr[midPos]-1, posArr, lastPosIndex, posLeft, midPos-1))
		   + (minimumNumberOfGoldCoins(posArr[midPos]+1, right, posArr, lastPosIndex, midPos+1, posRight));
}

int main (char *argv[], int argc) {
	ifstream ifs(INFILE);
	int testcases;
	ifs >> testcases;
	ofstream ofs(OUTFILE);
	for (int testcase = 1; testcase <= testcases; ++testcase) {
		long long result = 0;
		int totalPrisoners, releasePrisoners;
		ifs >> totalPrisoners >> releasePrisoners;
		std::vector<int> posArr;
		for (int i=0; i<releasePrisoners; i++) {
			int releasePos;
			ifs >> releasePos;
			posArr.push_back(releasePos);
		}
		result = minimumNumberOfGoldCoins(1, totalPrisoners, posArr, posArr.size()-1, 0, releasePrisoners-1);
		// cout << result << endl;
		ofs << "Case #" << testcase << ": " << result << endl;
	}
	return 0;
}