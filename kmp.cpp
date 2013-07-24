#include <iostream>
#include <string>
#include <cstring>

using namespace std;

void compute_overlay(string pattern, int pattern_index[]) {
	const int length = pattern.length();
	pattern_index[0] = -1;
	for (int i=1; i<length; i++) {
		int h = pattern_index[i-1];
		while (h>=0 && pattern[h+1] != pattern[i]) h = pattern_index[h];
		if (pattern[h+1] == pattern[i]) {
			pattern_index[i] = h+1;
		} else {
			pattern_index[i] = -1;
		}
	}
}

int kmp_find(string source, string pattern, int pattern_index[]) {
	compute_overlay(pattern, pattern_index);
	int source_len = source.length();
	int pattern_len = pattern.length();
	int cur_index = 0;
	int compared_index = 0;
	while (cur_index < source_len && compared_index < pattern_len) {
		cout << compared_index << " " << cur_index << endl;
		if (source[cur_index] == pattern[compared_index]) {
			compared_index++;
			cur_index++;
		} else if (compared_index == 0){
			cur_index++;
		} else {
			compared_index = pattern_index[compared_index-1]+1;
		}
	}
	if (compared_index == pattern_len) return cur_index - compared_index;
	else return -1;
}

int main(int argc, char *argv[]) {
	string source = "annbcdanacadsannanannacannannn";
	string pattern = "annacanna";
	const int length = pattern.length();
	int pattern_index[length];
	memset(pattern_index, 0, length);
	cout << kmp_find(source, pattern, pattern_index) << endl;
	return 0;
}