#include <vector>

using namespace std;

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        std::vector<int> result(rowIndex+1);
        result[0] = 1;
        for (int i=0; i<=rowIndex; i++) {
        	result[i] = 1;
    		int mid = i/2;
    		for (int j=mid; j>=1; j--) {
    			result[j] = result[j-1] + result[j];
    			result[i-j] = result[j];
    		}
    	}
    	return result;
    }
};