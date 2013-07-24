#include <climits>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int> &prices) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int min_index, max_index;
        int min, max;
        if (prices.size() == 0) return 0;
        return maxSubValue(prices, 0, prices.size()-1);
    }

	int maxSubValue (std::vector<int> &v, int left, int right) {
		int min_v = v[left], max_v = v[left];
		int min_i = left, max_i = left;
		for (int i=left; i<=right; i++) {
			if (v[i]>max_v) {
				max_v = v[i];
				max_i = i;
			}
			if (v[i]<min_v) {
				min_v = v[i];
				min_i = i;
			}
		}
		if (min_i <= max_i) {
			return v[max_i] - v[min_i];
		}

		int min_left_v = max_v, max_right_v = min_v;
		int min_left_i = max_i, max_right_i = min_i;
		for (int i=left; i<=max_i; i++) {
			if (v[i] < min_left_v) {
				min_left_v = v[i];
				min_left_i = i;
			}
		}
		for (int i=min_i; i<=right; i++) {
			if (v[i] > max_right_v) {
				max_right_v = v[i];
				max_right_i = i;
			}
		}
		int left_sub = max_v - min_left_v;
		int right_sub = max_right_v - min_v;
		return max_in_three(left_sub, right_sub, maxSubValue(v, max_i+1, min_i-1));
	}

private:
	int max_in_three(int a, int b, int c) {
		// cout << a << " " << b << " " << c << endl;
		int max = a;
		if (b > max) max = b;
		if (c > max) max = c;
		return max;
	}
};

int main(int argc, char *argv[]) {
	Solution sol;
	int my_ints[] = {3,2,6,5,0,3};
	std::vector<int> v(my_ints, my_ints + sizeof(my_ints)/sizeof(int));
	cout << sol.maxProfit(v) << endl;
}