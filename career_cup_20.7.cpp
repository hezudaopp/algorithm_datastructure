#include <iostream>
#include <fstream>
#include <vector>
#include <set>

using namespace std;

#define FILE "100west.txt"

extern void getWordFromFile(vector<string> &, string);

void print_str (string str) {
	cout << " " << str;
}

void getWordFromFile(std::vector<string> &v, string filename) {
	ifstream ifs(filename.c_str());
	string str;
	char signArr[] = {',', '.'}; 
	while (ifs >> str) {
		for (int i = 0; i < sizeof(signArr); ++i)
		{
			if (signArr[i] == str[str.length()-1]) {
				str = str.substr(0, str.length()-1);
			}
		}
		for (int i = 0; i < str.length(); ++i)
		{
			str[i] = tolower(str[i]);
		}
		v.push_back(str);
	}
}

bool strLenComp(string str1, string str2) {
	return (str1.length() > str2.length());
}

bool isAllSubStrInArray(set<string> s, string str) {
	for (int j=1; j<str.length(); j++) {
		string a = str.substr(0, j);
		string b = str.substr(j);
		if (s.find(a) != s.end() && s.find(b) != s.end()) {
			cout << a << " " << b << endl;
			cout << str << endl;
			return true;
		}
	}
	return false;
}

unsigned longestSubStrInArray(std::vector<string> str_v, set<string> str_set) {
	for (int i=0; i<str_v.size(); i++) {
		if (isAllSubStrInArray(str_set, str_v[i])) {
			return str_v[i].length();
		}
	}
	return 0;
}

int main(char *argv, int argc) {
	std::vector<string> str_v;
	getWordFromFile(str_v, FILE);
	sort(str_v.begin(), str_v.end(), strLenComp);
	set<string> str_set;
	for (int i=0; i<str_v.size(); i++) {
		str_set.insert(str_v[i]);
	}
	cout << longestSubStrInArray(str_v, str_set) << endl;
	// for_each(str_v.begin(), str_v.end(), print_str);
	return 0;
}