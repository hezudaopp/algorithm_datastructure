#include <vector>
#include <map>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        sort(candidates.begin(), candidates.end());
        map<int, vector<vector<int> > > m;   
        for (int i=1; i<=target; i++) {
            m[i] = vector<vector<int> >();
            for (int j=0; j<candidates.size(); j++) {
                if (i < candidates[j]) {
                    continue;
                } else if (i == candidates[j]) {
                    m[i].push_back(vector<int>());
                    m[i].back().push_back(candidates[j]);
                } else {
                    int sub = i - candidates[j];
                    for (int k=0; k<m[sub].size(); k++) {
                        if (m[sub][k].back() <= candidates[j]) {
                            m[i].push_back(vector<int>(m[sub][k]));
                            m[i].back().push_back(candidates[j]);
                        }
                    }
                }
            }
        }
        return m[target];
    }
};

int main (int argc, char *argv[]) {
    int my_ints[] = {1};
    std::vector<int> v(my_ints, my_ints+sizeof(my_ints)/sizeof(int));
    Solution sol;
    sol.combinationSum(v, 2);
    return 0;
}