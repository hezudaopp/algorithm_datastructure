#include <vector>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 
class Solution {
public:
    vector<vector<int> > levelOrder(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        std::vector<std::vector<int> > result;
        if (root == NULL) return result;
        std::queue<TreeNode *> q;
        q.push(root);
        TreeNode *level_end = q.back();
        std::vector<int> v;
        do {
        	TreeNode *cur = q.front();
        	v.push_back(cur->val);
        	q.pop();
        	if (cur->left != NULL) q.push(cur->left);
        	if (cur->right != NULL) q.push(cur->right);
        	if (cur == level_end) {
        		result.push_back(v);
        		v.clear();
        		level_end = q.back();
        	}
        } while (!q.empty());
        return result;
    }
};