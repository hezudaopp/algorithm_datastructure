#include <vector>
#include <algorithm>
#include <iostream>
#include <set>

#define FOR(i, a, b) for(int i=(a);i<(b);i++)

using namespace std;

// class Solution {
// public:
//     vector<vector<int> > threeSum(vector<int> &num) {
//         // Start typing your C/C++ solution below
//         // DO NOT write int main() function
//       vector<std::vector<int> > result;
//       set<std::vector<int> > s;
//       int len = num.size();
//       if (len < 3) return result;
//   		sort(num.begin(), num.end());
//   		int positive_start = len-1;
//   		FOR(i, 0, len) {
//   			// cout << num[i] << " ";
//   			if (num[i] > 0) {
//   				positive_start = i;
//   				break;
//   			}
//   		}
//   		// std::vector<int>::iterator it_last = num.end();
//   		FOR(i, 0, positive_start) {
//   			FOR(j, i+1, len) {
//   				int two_sum = 0-num[i]-num[j];
//   				int begin_index = num[j] > 0 ? j+1 : positive_start;
//           int last_index = len-1;
//           if (begin_index > last_index) {
//             break;
//           }
//   				last_index = b_search(num, begin_index, last_index, two_sum);
//           // cout <<i << j << begin_index << last_index << endl;
//   				if (num[last_index] == two_sum) {
//   					cout << "{" << num[i] << "," << num[j] << "," << two_sum << "}" << endl;
//   					int myints[] = {num[i], num[j], two_sum};
//   					std::vector<int> three_sums(myints, myints + sizeof(myints)/sizeof(int));
//   					// result.push_back(three_sums);
//             s.insert(three_sums);
//   				}
//   				// std::vector<int>::iterator begin = num[j] > 0 ? num.begin() + j + 1 : num.begin() + positive_start;
//   				// if (binary_search (begin, num.end(), two_sum)) {
//   				// 	cout << "{" << num[i] << "," << num[j] << "," << two_sum << "}" << endl;
//   				// 	int myints[] = {num[i], num[j], two_sum};
//   				// 	std::vector<int> three_sums(myints, myints + 3);
//   				// 	result.push_back(three_sums);
//   				// }
//   			}
//   		}
//       std::copy(s.begin(), s.end(), std::back_inserter(result));
//   		return result;
//     }

// private:
// 	int b_search(vector<int> v, int start, int end, int value) {
// 		if (start >= end) {
// 			return start;
// 		}
// 		int mid = (start+end)/2;
// 		if (v[mid] > value) {
// 			return b_search(v, start, mid-1, value);
// 		} else if (v[mid] < value) {
// 			return b_search(v, mid+1, end, value);
// 		} else {
// 			return mid;
// 		}
// 	}
// };

class Solution {
public:
  vector<vector<int> > threeSum(vector<int> &num) {
    set<vector<int> > s;
    std::vector<vector<int> > result;
    int len = num.size();
    if (len < 3) {
      return result;
    }
    sort(num.begin(), num.end());
    FOR(i, 0, len-1) {
      // cout << i << endl;
      for (int j = i+1, k = len-1; j<k;) {
        // cout << j << " " << k << endl;
        // cout << num[i] << " " << num[j] << " " << num[k] << endl;
        int sum = num[i]+num[j]+num[k];
        // cout << "sum:" << sum << endl;
        if (sum > 0) {
          // cout << "k:" << k << endl;
          k--;
        } else if (sum < 0){
          // cout << "j:" << j << endl;
          j++;
        } else {
          int nums[3] = {num[i], num[j], num[k]};
          // cout << num[i] << " " << num[j] << " " << num[k] << endl;
          std::vector<int> three_sums(nums, nums + sizeof(nums)/sizeof(int));
          s.insert(three_sums);
          j++;
        }
      }
    }
    std::copy(s.begin(), s.end(), std::back_inserter(result));
    print_result(result);
    return result;
  }
private:
  void print_result(vector<vector<int> > v) {
    FOR(i, 0, v.size()) {
      FOR(j, 0, 3) {
        cout << v[i][j] << " ";
      }
      cout << endl;
    }
  }
};

int main (int argc, char *argv[]) {
	Solution sol;
	int myints[] = {-7,-1,-13,2,13,2,12,3,-11,3,7,-15,2,-9,-13,-13,11,-10,5,-13,2,-12,0,-8,8,-1,4,10,-13,-5,-6,-4,9,-12,5,8,5,3,-4,9,13,10,10,-8,-14,4,-6,5,10,-15,-1,-3,10,-15,-4,3,-1,-15,-10,-6,-13,-9,5,11,-6,-13,-4,14,-3,8,1,-4,-5,-12,3,-11,7,13,9,2,13,-7,6,0,-15,-13,-11,-8,9,-14,1,11,-7,13,0,-6,-15,11,-6,-2,4,2,9,-15,5,-11,-11,-11,-13,5,7,7,5,-10,-7,6,-7,-11,13,9,-10,-9};
  	std::vector<int> v (myints, myints + sizeof(myints) / sizeof(int) );
  	sol.threeSum(v);
	return 0;
}