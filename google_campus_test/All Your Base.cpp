#include <iostream>
#include <fstream>
#include <set>
#include <map>
#include <vector>

using namespace std;

#define FILE "A-small-practice.in"
#define LARGEFILE "A-large-practice.in"
#define OUTFILE "A-small-practice.out"
#define LARGEOUTFILE "A-large-practice.out"

int decideBase(string code) {
	set<char> s;
	for (int i=0; i<code.length(); i++) {
		s.insert(code[i]);
	}
	if (s.size() < 2) return 2;
	return s.size();
}

void makeMap(std::map<int, int> &m, string code) {
	bool isZeroDecided = false;
	int j = 2;
	std::map<char, int> myMap;
	for (int i=0; i<code.length(); i++) {
		if (i == 0) {
			myMap[code[i]] = 1;
			m[i] = 1;
		}
		if (!isZeroDecided) {
			if (myMap.find(code[i]) == myMap.end()) {
				myMap[code[i]] = 0;
				m[i] = 0;
				isZeroDecided = true;
				continue;
			} else {
				m[i] = 1;
			}
		} else {
			if (myMap.find(code[i]) == myMap.end()) {
				myMap[code[i]] = j;
				m[i] = j;
				++j;
			} else {
				m[i] = myMap[code[i]];
			}
		}
	}
}

long long minimumSecondsToWars(string code) {
	int base = decideBase(code);
	// cout << base << endl;
	std::map<int, int> m;
	makeMap(m, code);
	// for (int i=0; i<m.size(); i++) {
	// 	cout << m[i] << " ";
	// }
	// cout << endl;
	long long result = 0;
	int last_index = code.length()-1;
	for (int i=code.length()-1; i>=0; --i) {
		result = m[last_index-i] + result*base;
	}
	return result;
}

int main (char *argv[], int argc) {
	ifstream ifs(LARGEFILE);
	ofstream ofs(LARGEOUTFILE);
	string str;
	ifs >> str;
	int count = atoi(str.c_str());
	for (int i=1; i<=count; i++) {
		ifs >> str;
		// printf("Case #%d: %lld\n",i,minimumSecondsToWars(str));
		ofs << "Case #" << i << ": " << minimumSecondsToWars(str) << endl;
	}
}