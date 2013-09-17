#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

#define INFILE "C-small-practice-2.in"
#define OUTFILE "C-small-practice-2.out"

int lexicographicallyCompare (string str1, string str2) {
	int i=0;
	int len1 = str1.length(), len2 = str2.length();
	while (i < len1 && i < len2) {
		if (str1[i] < str2[i]) return 1;
		else if (str1[i] > str2[i]) return -1;
		i++;
	}
	if (i < str1.length()) {
		return -1;
	}
	if (i < str2.length()) {
		return 1;
	}
	return 0;
}

int countSwapTimes(vector<string> v) {
	int result = 0;
	if (v.empty()) return result;
	string curMaxString = v[0];
	for (int i=1; i<v.size(); i++) {
		// cout << result << curMaxString << endl;
		if (lexicographicallyCompare(v[i], curMaxString) > 0) {
			result++;
		} else {
			curMaxString = v[i];
		}
	}
	return result;
}

int main (char* argv[], int argc) {
	ifstream ifs(INFILE);
	ofstream ofs(OUTFILE);
	string testcases;
	std::getline(ifs, testcases);
	int T = atoi(testcases.c_str());
	for (int t=1; t<=T; t++) {
		string sizeLine;
		std::getline(ifs, sizeLine);
		int size = atoi(sizeLine.c_str());
		vector<string> v;
		string line;
		for (int i=0; i<size; i++) {
			std::getline(ifs, line);
			v.push_back(line);
		}
		ofs << "Case #" << t << ": " << countSwapTimes(v) << endl;
	}
	return 0;
}