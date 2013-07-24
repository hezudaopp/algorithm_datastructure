#include <vector>

using namespace std;

class Solution {
public:
	vector<vector<int> > generate(int numRows) {
		std::vector<std::vector<int> > result;
		for (int i=0; i<numRows; i++) {
			std::vector<int> v(i+1);
			v[0] = v[i] = 1;
			for (int j=1; j<i; j++) {
				v[j] = result[i-1][j-1] + result[i-1][j];
			}
			result.push_back(v);
		}
		return result;
	}
};