#include <climits>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int minimumTotal(vector<vector<int> > &triangle) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        // vector<vector<int> > sums(triangle);
        // for (int i=0; i<sums.size(); i++) {
        // 	for (int j=0; j<sums[i].size(); j++) {
        // 		sums[i][j] = INT_MAX;
        // 	}
        // }
        // int result = 0;
        // result += minSum(triangle, 0, 0, sums);
        // return result;
        int m = triangle.size();
        for (int i=m-2; i>=0; i--) {
        	int n = triangle[i].size();
        	for (int j=i; j>=0; j--) {
        		triangle[i][j] += min(triangle[i+1][j], triangle[i+1][j+1]);
        	}
        }
        return triangle[0][0];
    }

    // int minSum(vector<vector<int> > &triangle, int row, int col, vector<vector<int> > sums) {
    // 	if (sums[row][col] < INT_MAX) return sums[row][col];
    // 	int subSum = 0;
    // 	if (row < triangle.size()-1)
    // 		subSum = min(minSum(triangle, row+1, col, sums), minSum(triangle, row+1, col+1, sums));
    // 	sums[row][col] = triangle[row][col] + subSum;
    // 	return sums[row][col];
    // }
};

int main (int argc, char *argv[]) {
	int my_ints[] = {1};
	int my_ints1[] = {2,3};
	std::vector<std::vector<int> > v;
	std::vector<int> v1(my_ints, my_ints+sizeof(my_ints)/sizeof(int));
	std::vector<int> v2(my_ints1, my_ints1+sizeof(my_ints1)/sizeof(int));
	v.push_back(v1);
	v.push_back(v2);
	Solution sol;
	cout << sol.minimumTotal(v) << endl;
	return 0;
}