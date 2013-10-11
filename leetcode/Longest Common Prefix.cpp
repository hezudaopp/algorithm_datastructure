#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        int size = strs.size();
        if (size == 0) return "";
        int longestIndex = 0;
        while (longestIndex < strs[0].length()) {
        	int i;
        	for (i=1; i<size; i++) {
        		if (strs[i][longestIndex] != strs[0][longestIndex]) {
        			break;
        		}
	        }
	        if (i == size) {
	        	longestIndex++;
	        } else {
	        	break;
	        }
        }
        return strs[0].substr(0, longestIndex);
    }
};

int main (char *argv[], int argc) {
	vector<string> strs;
	Solution sol;
	cout << sol.longestCommonPrefix(strs) << endl;
	return 0;
}