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
	bool isSymmetricRecursive(TreeNode *l, TreeNode *r) {
		if (l == NULL && r == NULL) {
 			return true;
 		} else if ((l == NULL) ^ (r == NULL)){
 			return false;
 		} else {
 			if (l->val == r->val) {
 				return isSymmetricRecursive(l->left, r->right) && isSymmetricRecursive(l->right, r->left);
 			} else {
 				return false;
 			}
 		}
	}

public:
    bool isSymmetric(TreeNode *root) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
     	if (root) {
     		return isSymmetricRecursive(root->left, root->right);	
     	}
     	return true;
    }
};