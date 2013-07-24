#include <vector>
#include <algorithm>
#include <iostream>

#define FOR(i, a, b) for(int i=(a); i<(b); i++)
#define INCREASE(i, j, num) while(++i != (j) && (num[i])==(num[i-1]))
#define DECREASE(i, j, num) while(--i != (j) && (num[i])==(num[i+1]))

using namespace std;

class Solution {
public:
    vector<vector<int> > fourSum(vector<int> &num, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int> > result;
        int len = num.size();
        if (len < 4) return result;
        sort(num.begin(), num.end());
        FOR(i, 0, len-3) {
        	FOR(j, i+1, len-2) {
        		int k = j+1, l = len-1;
        		while (k<l) {
        			int sum = num[i]+num[j]+num[k]+num[l];
        			if (sum < target) {
        				INCREASE(k, l, num);
        			} else if (sum > target) {
        				DECREASE(l, k, num);
        			} else {
        				int my_ints[4] = {num[i], num[j], num[k], num[l]};
        				std::vector<int> v(my_ints, my_ints+sizeof(my_ints)/sizeof(int));
        				if (find(result.begin(), result.end(), v) == result.end()) {
        					result.push_back(v);
        				}
        				INCREASE(k, l, num);
        			}
        		}
        	}
        }
        return result;
    }
};