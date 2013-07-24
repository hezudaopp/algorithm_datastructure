#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int> &prices) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int len = prices.size();
        if (len <= 1) return 0;
        std::vector<int> max_profits(0);
        int cur_min = prices[0];
        int max_profit_i = 0;
        for (int i=1; i<len; i++) {
            if (prices[i] > cur_min) {
                max_profit_i = max(max_profit_i, prices[i] - cur_min);
            } else {
                cur_min = prices[i];
            }
            // cout << max_profit_i << " ";
            max_profits.push_back(max_profit_i);
        }
        // cout << endl;
        int cur_max = prices[len-1];
        int result = max_profits[0];
        int max_profit = 0;
        for (int i=len-2; i>0; i--) {
            if (prices[i] < cur_max) {
                max_profit = max(max_profit, cur_max - prices[i]);
            } else {
                cur_max = prices[i];
            }
            // cout << max_profit << " ";
            result = max(max_profit + max_profits[i-1], result);
        }
        return result;
        // int max_sub = 0;
        // for (int i=0; i<len; i++) {
        //     int temp_sum = maxSubValue(prices, 0, i) + maxSubValue(prices, i+1, len-1);
        //     if (temp_sum > max_sub) max_sub = temp_sum;
        // }
        // return max_sub;
    }

// private:
//     int maxSubValue (std::vector<int> &v, int left, int right) {
//         if (left >= right) return 0;
//         int min_v = v[left], max_v = v[left];
//         int min_i = left, max_i = left;
//         for (int i=left; i<=right; i++) {
//             if (v[i]>max_v) {
//                 max_v = v[i];
//                 max_i = i;
//             }
//             if (v[i]<min_v) {
//                 min_v = v[i];
//                 min_i = i;
//             }
//         }
//         if (min_i <= max_i) {
//             return v[max_i] - v[min_i];
//         }

//         int min_left_v = max_v, max_right_v = min_v;
//         int min_left_i = max_i, max_right_i = min_i;
//         for (int i=left; i<=max_i; i++) {
//             if (v[i] < min_left_v) {
//                 min_left_v = v[i];
//                 min_left_i = i;
//             }
//         }
//         for (int i=min_i; i<=right; i++) {
//             if (v[i] > max_right_v) {
//                 max_right_v = v[i];
//                 max_right_i = i;
//             }
//         }
//         int left_sub = max_v - min_left_v;
//         int right_sub = max_right_v - min_v;
//         return max_in_three(left_sub, right_sub, maxSubValue(v, max_i+1, min_i-1));
//     }

//     int max_in_three(int a, int b, int c) {
//         // cout << a << " " << b << " " << c << endl;
//         int max = a;
//         if (b > max) max = b;
//         if (c > max) max = c;
//         return max;
//     }
};

int main (int argc, char *argv[]) {
	Solution sol;
	int my_ints[]={1,2};
	std::vector<int> v(my_ints, my_ints + sizeof(my_ints)/sizeof(int));
	cout << sol.maxProfit(v) << endl;
    return 0;
}