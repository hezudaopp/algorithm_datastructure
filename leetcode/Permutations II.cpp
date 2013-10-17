#include <vector>
#include <iostream>

using namespace std;

class Solution {
private:
	bool used[100];
	vector<int> *permutation;
	int size;

	void permute(vector<int> &num, int dep, vector<vector<int> > &result) {
		if (dep == size) {
			result.push_back(*permutation);
			return;
		}
		for (int i=0; i<size; i++) {
			if (!used[i]) {
				if (i > 0 && num[i] == num[i-1] && !used[i-1]) {
					continue;
				}
				used[i] = true;
				(*permutation)[dep] = num[i];
				permute(num, dep+1, result);
				used[i] = false;
			}
		}
	}

public:
    vector<vector<int> > permuteUnique(vector<int> &num) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        size = num.size();
        permutation = new vector<int>(size);
    	sort(num.begin(), num.end());
    	memset(used, false, sizeof(used)/sizeof(bool));
    	vector<vector<int> > result;
    	permute(num, 0, result);
    	return result;
    }
};

int main (char *argv[], int argc) {
	Solution sol;
	int arr[] = {1,-1,1,2,-1,2,2,-1};
	vector<int> num(arr, arr+sizeof(arr)/sizeof(int));
	vector<vector<int> > result = sol.permuteUnique(num);
	for (int i=0; i<result.size(); i++) {
		for (int j=0; j<result[i].size(); j++) {
			cout << result[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}