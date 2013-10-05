#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
	bool searchMatrixIndex(vector<vector<int> > &matrix, int C, int R, int target) {
		int row = R, col = 0;
		while (row >= 0 && col <= C) {
			if (matrix[row][col] == target) {
				return true;
			} else if (matrix[row][col] < target) {
				col++;
			} else {
				row--;
			}
		}
		return false;
	}

public:
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        if (matrix.empty() || matrix[0].empty())
        	return false;
        return searchMatrixIndex(matrix, matrix[0].size()-1, matrix.size()-1, target);
    }
};

int main (char *argv[], int argc) {
	Solution sol;
	int arr1[] = {1, 3, 5, 7};
	int arr2[] = {10, 11, 16, 20};
	int arr3[] = {23, 30, 34, 50};
	vector<int> v1(arr1, arr1+sizeof(arr1)/sizeof(int));
	vector<int> v2(arr2, arr2+sizeof(arr2)/sizeof(int));
	vector<int> v3(arr3, arr3+sizeof(arr3)/sizeof(int));
	vector<vector<int> > v;
	v.push_back(v1);
	v.push_back(v2);
	v.push_back(v3);
	for (int i=0; i<=10; i++) {
		cout << sol.searchMatrix(v, i) << endl;
	}
	return 0;
}