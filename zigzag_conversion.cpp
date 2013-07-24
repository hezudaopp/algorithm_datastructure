/* cann't understand what shall we solve.*/

#include <string>

using namespace std;

class Solution {
public:
    string convert(string s, int nRows) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function    
        string result;
        if (nRows%2==1) {
        	int midRow = nRows/2;
        	for (int i=0; i<nRows; i++) {
        		int j = i, step;
        		if (i!=midRow) {
        			step = nRows+1;
	        	} else {
	        		step = midRow+1;
	        	}
	        	while (j < s.length()) {
        			result += s[j];
        			j += step;
        		}
        	}
        } else {
        	int midRow1 = nRows/2-1, midRow2 = nRows/2;
        	for (int i=0; i<nRows; i++) {
        		int j = i, step;
        		if (i!=midRow1 && i!=midRow2) {
        			step = nRows+2;
        			while (j < s.length()) {
	        			result += s[j];
	        			j += step;
	        		}
	        	} else if (i==midRow1) {
	        		int count = 1;
	        		while (j < s.length()) {
	        			step = (count%2==1) ? midRow2+2 : midRow2;
	        			result += s[j];
	        			j += step;
	        			count++;
	        		}
	        	} else {
	        		int count = 1;
	        		while (j < s.length()) {
	        			step = (count%2==0) ? midRow2+2 : midRow2;
	        			result += s[j];
	        			j += step;
	        			count++;
	        		}
	        	}
        	}
        }
        return result;
    }
};