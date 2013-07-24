#include <vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int> &prices) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int len = prices.size();
        if (len == 0) return 0;
        int result = 0;
        int i = 1;
        while (i < len) {
        	int sub;
	    	while ( i < len && (sub = (prices[i] - prices[i-1])) >= 0 ) {
	    		result += sub;
	    		i++;
	    	}
	    	while ( i < len && (sub = (prices[i] - prices[i-1])) < 0 ) {
	    		i++;
	    	}
	    }
	    return result;
    }
};