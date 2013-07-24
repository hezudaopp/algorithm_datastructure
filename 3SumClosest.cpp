#include <vector>
#include <algorithm>
#include <iostream>
#include <climits>

#define FOR(i, a, b) for(int i=(a); i<(b); i++)

using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int> &num, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int len = num.size();
        if (len < 3) return 0;
        // unsigned int first = abs(num[0]-target), second = UINT_MAX, third = UINT_MAX;
        // int f_index = 0, s_index = 1, t_index = 2;
        // FOR(i, 1, len) {
        // 	unsigned int absolute = abs(num[i]-target);
        // 	// cout << absolute << " ";
        // 	if (absolute < first) {
        // 		f_index = i;
        // 	}
        // }
        // cout << f_index << endl;
        // for (int i = 0; i < len && i != f_index; i++) {
        // 	unsigned int absolute = abs(num[i]-target);
        // 	if (absolute < second) {
        // 		s_index = i;
        // 	}
        // }
        // cout << s_index << endl;
        // for (int i = 0; i < len && i != f_index && i != s_index; i++) {
        // 	unsigned int absolute = abs(num[i]-target);
        // 	if (absolute < third) {
        // 		t_index = i;
        // 	}
        // }
        // cout << t_index << endl;
        // return num[f_index]+num[s_index]+num[t_index];

        sort(num.begin(), num.end());
        unsigned int minsum = UINT_MAX;
        int three_sum_closest;
        FOR(i, 0, len-2) {
        	for (int j=i+1, k=len-1; j<k;) {
        		// cout << i << " " << j << " " << k << endl;
        		int sum = num[i]+num[j]+num[k]-target;
        		unsigned int ab_sum = abs(sum);
        		if (ab_sum < minsum) {
        			minsum = ab_sum;
	        		three_sum_closest = num[i]+num[j]+num[k];
	        		if (minsum == 0) break;
        		}
        		if (sum > 0) {
        			k--;
        		} else if (sum <= 0) {
        			j++;
        		}
        	}
        }
        // do {
        // 	unsigned int ab_sum = abs(num[0]+num[1]+num[2]-target);
        // 	if (ab_sum < minsum) {
        // 		// cout << num[0] << " " << num[1] << " " << num[2] << endl;
        // 		minsum = ab_sum;
        // 		three_sum_closest = num[0]+num[1]+num[2];
        // 		if (minsum == 0) break;
        // 	}
        // 	reverse(num.begin()+3, num.end());
        // } while (next_permutation(num.begin(), num.end()));
        return three_sum_closest;
    }
};

int main (int argc, char *argv[]) {
	Solution s;
	int my_ints[] = {-1,2,1,-4};
	std::vector<int> v(my_ints, my_ints+sizeof(my_ints)/sizeof(int));
	cout << s.threeSumClosest(v, 1) << endl;
	return 0;
}