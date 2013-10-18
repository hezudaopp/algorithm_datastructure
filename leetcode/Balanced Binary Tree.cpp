#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
private:
	bool isBalanced (TreeNode *node, int &dep) {
		if (!node) {
			dep = 0;
			return true;
		}
		int left, right;
		if (isBalanced(node->left, left) && isBalanced(node->right, right)) {
			int dif = left - right;
			if (dif < 0) dif = -dif;
			if (dif <= 1) {
				dep = 1+max(left, right);
				return true;
			} else {
				return false;
			}
		}
		return false;
	}

public:
    bool isBalanced(TreeNode *root) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        int dep;
    	return isBalanced(root, dep);
    }
};