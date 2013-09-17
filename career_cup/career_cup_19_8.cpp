#include <iostream>
#include <fstream>
#include <map>
#include <vector>

using namespace std;

#define FILE "100west.txt"

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

void printWordCount(std::vector<string> words) {
	map<string, int> wordCount;
	for (vector<string>::iterator it=words.begin(); it!=words.end(); it++) {
		wordCount.find(*it) == wordCount.end() ? wordCount[*it] = 1 : wordCount[*it]++;
	}
	for (map<string, int>::iterator it=wordCount.begin(); it!=wordCount.end(); it++) {
		cout << it->first << " " << it->second << endl;
	}
}

int main (char *argv[], int argc) {
	std::vector<string> str_v;
	getWordFromFile(str_v, FILE);
	printWordCount(str_v);
	return 0;
}