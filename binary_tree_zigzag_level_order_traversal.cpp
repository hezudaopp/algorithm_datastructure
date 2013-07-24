#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
    vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        std::vector<std::vector<int> > result;
        if (!root) return result;
        std::vector<int> v;
        std::queue<TreeNode * > q;
        TreeNode *end = root;
        q.push(root);
        int i = 0;
        do {
            TreeNode *t = q.front();
            q.pop();
            v.push_back(t->val);
            if (t->left) q.push(t->left);
            if (t->right) q.push(t->right);
            if (end == t) {
                // cout << i%2 << endl;
                if (i%2) {
                    // cout << *v.begin() << endl;
                    reverse(v.begin(), v.end());
                    // cout << *v.begin() << endl;
                }
                result.push_back(v);
                v.clear();
                end = q.back();
                i++;
            }
        } while (!q.empty());
        return result;
    }
};

int main(int argc, char *argv[]) {
    Solution sol;
    TreeNode *t = new TreeNode(2);
    TreeNode *t_left = new TreeNode(3);
    TreeNode *t_right = new TreeNode(4);
    t->left = t_left;
    t->right = t_right;
    sol.zigzagLevelOrder(t);
    return 0;
}