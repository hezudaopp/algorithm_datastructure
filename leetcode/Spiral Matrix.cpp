#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int> > &matrix) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        vector<int> result;
        if (matrix.empty())
        	return result;
        int rowStart = 0, colStart = 0;
        int rowEnd = matrix.size()-1, colEnd = matrix[0].size()-1;
        while (rowStart <= rowEnd && colStart <= rowEnd) {
        	for (int i=colStart; i<=colEnd; i++) {
        		result.push_back(matrix[rowStart][i]);
        	}
        	rowStart++;
        	if (rowStart > rowEnd) break;
        	for (int i=rowStart; i<=rowEnd; i++) {
        		result.push_back(matrix[i][colEnd]);
        	}
        	colEnd--;
        	if (colStart > colEnd) break;
        	for (int i=colEnd; i>=colStart; i--) {
        		result.push_back(matrix[rowEnd][i]);
        	}
        	rowEnd--;
        	if (rowStart > rowEnd) break;
        	for (int i=rowEnd; i>=rowStart; i--) {
        		result.push_back(matrix[i][colStart]);
        	}
        	colStart++;
        	if (colStart > colEnd) break;
        }
        return result;
    }
};

int main (char *argv[], int argc) {
	int arr[3][3] = {{1,2,3},{4,5,6},{7,8,9}};
	vector<int> v1(arr[0], arr[0]+1);
	vector<int> v2(arr[1], arr[1]+1);
	vector<int> v3(arr[2], arr[2]+1);
	vector<vector<int> > v;
	v.push_back(v1);
	v.push_back(v2);
	v.push_back(v3);
	Solution sol;
	vector<int> vx(sol.spiralOrder(v));
	for (int i=0; i<vx.size(); i++) {
		cout << vx[i] << endl;
	}
	return 0;
}