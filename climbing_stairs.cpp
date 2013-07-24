#include <vector>
#include <map>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        sort(candidates.begin(), candidates.end());
        map<int, vector<vector<int> > > m;   
        for (int i=1; i<=target; i++) {
            for (int j=0; j<candidates.size(); i++) {
                if (i < candidates[j]) {
                    continue;
                } else (i == candidates[j]) {
                    m[i].push_back(vector<int>());
                    m[i].back().push_back(candidates[j]);
                } else {
                    int sub = i - candidates;
                    for (int k=0; k<m[sub].size(); i++) {
                        m[i].push_back(vector(m[sub][k]));
                        m[i].back().push_back(candidates[j]);
                    }
                }
            }
        }
        return m[target];
};