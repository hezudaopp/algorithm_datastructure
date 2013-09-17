#include <string>
#include <iostream>
#include <map>

using namespace std;

struct result
{
	int hits;
	int pseudohits;
};

result estimateHitsAndPseudoHits(string guess, string solution) {
	result res = {0, 0};
	int guessLen = guess.length(), solLen = solution.length();
	if (guessLen != solLen) return res;
	map<char, int> solutionCharsCount, unhitGuessCharsCount;
	int i=0;
	while (i<guessLen) {
		if (guess[i] == solution[i]) {
			res.hits++;
		} else {
			unhitGuessCharsCount[guess[i]]++;
		}
		solutionCharsCount[solution[i]]++;
		i++;
	}
	for (map<char, int>::iterator it = unhitGuessCharsCount.begin(); it!=unhitGuessCharsCount.end(); it++) {
		int guessCount = it->second, guessChar = it->first;
		while (guessCount > 0) {
			if (solutionCharsCount.find(guessChar)!=solutionCharsCount.end()) {
				++res.pseudohits;
			} else {
				break;
			}
			guessCount--;
		}
	}
	return res;
}

result estimateHitsAndPseudoHitsUsingMask(string guess, string solution) {
	result res = {0, 0};
	int guessLen = guess.length(), solLen = solution.length();
	if (guessLen != solLen) return res;
	int solutionMask = 0;
	for (int i=0; i<solLen; i++) {
		solutionMask |= (1 << (1+solution[i]-'A'));
	}
	for (int i=0; i<guessLen; i++) {
		if (guess[i] == solution[i]) {
			++res.hits;
		} else if ((solutionMask & (1 << (1+guess[i]-'A'))) >= 1) {
			++res.pseudohits;
		}
	}
	return res;
}

int main (char *argv[], int argc) {
	string guess = "AAAAAA", solution = "RGGBEA";
	result res = estimateHitsAndPseudoHits(guess, solution);
	cout << res.hits << " " << res.pseudohits << endl;
	res = estimateHitsAndPseudoHitsUsingMask(guess, solution);
	cout << res.hits << " " << res.pseudohits << endl;
	return 0;
}