#include <vector>
#include <map>
#include <algorithm>
#include <iostream>

using namespace std;


class Solution {
public:
    vector<vector<int> > combinationSum2(vector<int> &num, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        sort(num.begin(), num.end());
        std::vector<vector<int> > result;
        std::vector<int> path;
        getSum2(num, target, 0, result, path);
        return result;
    }

private:
    void getSum2(std::vector<int> num, int target, int start, vector<vector<int> > &result, vector<int> path) {
        // cout << target << " " << num[start] << endl;
        if (target == 0) {
            result.push_back(path);
            // for (int i=0;i<path.size();i++) cout << path[i] << " ";
            // cout << endl;
            return;
        }
        if (target < 0 || start >= num.size() || num[start] > target) return;
        int k=1;
        while(num[start+k] == num[start]) k++;
        getSum2(num, target, start+k, result, path);
        path.push_back(num[start]);
        getSum2(num, target-num[start], start+1, result, path);
    }
};

int main (int argc, char *argv[]) {
    int my_ints[] = {10,1,2,7,6,1,5};
    std::vector<int> v(my_ints, my_ints+sizeof(my_ints)/sizeof(int));
    Solution sol;
    sol.combinationSum2(v, 8);
    return 0;
}