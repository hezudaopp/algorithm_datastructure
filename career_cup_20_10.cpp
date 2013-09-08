#include <iostream>
#include <set>
#include <map>
#include <queue>
#include <fstream>

using namespace std;

set<string> dictionary;

set<string> getOneEditWords(string sourceWord) {
	set<string> result;
	for (int i=0; i<sourceWord.length(); i++) {
		char stringToBeAdded[10];
		strcpy(stringToBeAdded, sourceWord.c_str());
		for (char c = 'a'; c <= 'z'; c++) {
			if (stringToBeAdded[i] != c) {
				stringToBeAdded[i] = c;
				string str(stringToBeAdded);
				if (dictionary.find(str) != dictionary.end()) {
					result.insert(str);
				}
			}
		}
	}
	return result;
}

vector<string> transformFromOneWordToAnother(string sourceWord, string terminalWord) {
	queue<string> actionQueue;
	actionQueue.push(sourceWord);
	map<string, string> backtraceMap;
	vector<string> result;
	set<string> visitedWords;
	while (!actionQueue.empty()) {
		string actionWord = actionQueue.front();
		actionQueue.pop();
		set<string> ondEditWords = getOneEditWords(actionWord);
		for (set<string>::iterator it=ondEditWords.begin(); it!=ondEditWords.end(); it++) {
			if ((*it).compare(terminalWord) == 0) {
				result.push_back(*it);
				string backtraceWord = actionWord;
				while (backtraceWord.compare(sourceWord) != 0) {
					result.push_back(backtraceWord);
					backtraceWord = backtraceMap[backtraceWord];
				}
				result.push_back(sourceWord);
				return result;
			} else {
				if (visitedWords.find(*it) == visitedWords.end()){
					visitedWords.insert(*it);
					actionQueue.push(*it);
					backtraceMap[*it] = actionWord;
				}
			}
		}
	}
	return result;
}

int main (char *argv[], int argc) {
	ifstream ifs("US.dic");
	string inputString("damp");
	string outputString("like");
	string str;
	while (ifs >> str) {
		if (str.length() > outputString.length()) break;
		if (str.length() == outputString.length()) {
			dictionary.insert(str);
		}
	}
	std::vector<string> result = transformFromOneWordToAnother(inputString, outputString);
	for (int i=0;i<result.size();i++) {
		cout << result[i] << endl;
	}
	return 0;
}