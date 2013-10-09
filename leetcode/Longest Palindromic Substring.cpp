#include <iostream>

using namespace std;

class Solution {
private:
	string preProcess (string s) {
		int len = (2*s.length())+4;
		char *result = new char[len];
		result[0] = '^';
		result[len-1] = '\0';
		for (int i=0; i<s.length(); i++) {
			result[2*i+1] = '#';
			result[2*i+2] = s[i];
		}
		result[len-2] = '$';
		result[len-3] = '#';
		return string(result);
	}

public:
    string longestPalindrome(string s) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        if (s.empty()) return "";
        string newString = preProcess(s);
        int len = newString.length();
        int *P = new int[len];
        P[0] = 0;
        int id=0, mx=0;
        for (int i=1; i<len-1; i++) {
        	if (i < mx) {
        		int i_mirror = 2*id - i;
        		P[i] = min(P[i_mirror], mx-i);
        	} else {
        		P[i] = 0;
        	}
        	while (newString[i + P[i] + 1] == newString[i-P[i]-1]) {
        		P[i]++;
        	}
        	if ((i + P[i]) > mx) {
        		id = i;
        		mx = i + P[i];
        	}
        }
        int maxIndex = 0, maxLen = P[0];
        for (int i=1; i<len-1; i++) {
        	if (P[i] > maxLen) {
        		maxIndex = i;
        		maxLen = P[i];
        	}
        }
        delete P[];
        return s.substr((maxIndex-maxLen)/2, maxLen);
    }
};

int main (char *argv[], int argc) {
	string s("aaabaaaa");
	Solution sol;
	cout << sol.longestPalindrome(s) << endl;
	return 0;
}