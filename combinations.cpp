#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<vector<int> > combine(int n, int k) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        std::vector<std::vector<int> > result;
        std::vector<int> temp(k);
        combineVector(n, k, 0, 0, result, temp);
        return result;
    }

private:
	void combineVector(int n, int k, int size, int cur, std::vector<std::vector<int> > &result, std::vector<int> &temp) {
		if (k == size) {
			result.push_back(temp);
			return;
		}
		for (int i=cur; i<n; i++) {
			temp[size] = i+1;
			combineVector(n, k, size+1, i+1, result, temp);
		}
	}
};

int main (int argc, char *argv[]) {
	std::vector<std::vector<int> > v;
	Solution sol;
	v = sol.combine(4,2);
	for (int i=0;i < v.size(); i++) {
		for (int j=0; j <v[i].size(); j++) {
			cout << v[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}