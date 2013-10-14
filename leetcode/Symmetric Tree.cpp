#include <iostream>
#include <stack>
#include <queue>

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

    bool isSymmetricIteratively(TreeNode *root) {
        if (root == NULL) return true;
        queue<TreeNode *> leftQueue, rightQueue;
        if (root->left && root->right) {
            if (root->left->val == root->right->val) {
                leftQueue.push(root->left);
                rightQueue.push(root->right);
            } else {
                return false;
            }
        } else if ((root->left == NULL) ^ (root->right == NULL)) {
            return false;
        }
        while (!leftQueue.empty() && !rightQueue.empty()) {
            TreeNode *left, *right;
            left = leftQueue.front();
            leftQueue.pop();
            right = rightQueue.front();
            rightQueue.pop();
            if (left->left && right->right) {
                if (left->left->val == right->right->val) {
                    leftQueue.push(left->left);
                    rightQueue.push(right->right);
                } else {
                    return false;
                }
            } else if ((left->left == NULL) ^ (right->right == NULL)) {
                return false;
            }
            if (left->right && right->left) {
                if (left->right->val == right->left->val) {
                    leftQueue.push(left->right);
                    rightQueue.push(right->left);
                } else {
                    return false;
                }
            } else if ((left->right == NULL) ^ (right->left == NULL)) {
                return false;
            }
        }
        return true;
    }

public:
    bool isSymmetric(TreeNode *root) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
     	if (root) {
     		return isSymmetricIteratively(root);
     	}
     	return true;
    }
};

int main (char *argv[], int argc) {
    Solution sol;
    TreeNode *t1 = new TreeNode(1);
    TreeNode *t2 = new TreeNode(2);
    TreeNode *t3 = new TreeNode(2);
    TreeNode *t4 = new TreeNode(3);
    TreeNode *t5 = new TreeNode(3);
    TreeNode *t6 = new TreeNode(4);
    TreeNode *t7 = new TreeNode(4);
    t1->left = t2;
    // t1->right = t3;
    // t2->left = t6;
    // t2->right = t4;
    // t3->right = t7;
    // t3->left = t5;
    cout << sol.isSymmetric(t1) << endl;
}