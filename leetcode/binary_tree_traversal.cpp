#include <vector>
#include <iostream>
#include <stack>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    std::vector<int> preorderTraversal (TreeNode *root) {
        std::vector<int> result;
        TreeNode *cur = root;
        stack<TreeNode *> s;
        while (cur || !s.empty()) {
            while (cur) {
                cout << cur->val << endl;
                result.push_back(cur->val);
                s.push(cur);
                cur = cur->left;
            }
            cur = s.top();
            s.pop();
            if (cur->right) {
                cur = cur->right;
            } else {
                cur = NULL; // do not forget set cur to NULL to avoid infinite loop
            }
        }
        return result;
    }

    vector<int> inorderTraversal(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        std::vector<int> result;
        std::stack<TreeNode *> s;
        TreeNode *cur = root;
        while (cur || !s.empty()) {
            while (cur) {
                s.push(cur);
                cur = cur->left;
            }
            cur = s.top();
            // cout << cur->val << endl;
            result.push_back(cur->val);
            s.pop();
            if (cur->right) {
                cur = cur->right;
            } else {
                cur = NULL;
            }
        }
        return result;
    }

    vector<int> postorderTraversal(TreeNode *root) {
        vector<int> result;
        TreeNode *cur = root;
        TreeNode *pre = NULL;
        stack<TreeNode *> s;
        while (cur || !s.empty()) {
            while (cur) {
                s.push(cur);
                cur = cur->left;
            }
            cur = s.top();
            if (NULL==cur->right || cur->right == pre) {
                cout << cur->val << endl;
                result.push_back(cur->val);
                s.pop();    // pop after visited it
                pre = cur;  // pre info that we have just visited that Treenode
                cur = NULL; // so that we can visit its parent node next loop
            } else {
                cur = cur->right;
                // s.push(cur); // there is need to push cur for it will be pushed into the stack next loop
            }
        }
        return result;
    }

    void insertLeftNode(TreeNode *t, int value) {
		TreeNode *node = new TreeNode(value);
		t->left = node;
	}

	void insertRightNode(TreeNode *t, int value) {
		TreeNode *node = new TreeNode(value);
		t->right = node;
	}
};

int main (int argc, char* argv[]) {
	TreeNode *t = new TreeNode(1);
	Solution sol;
	sol.insertLeftNode(t, 2);
	sol.insertRightNode(t, 3);
	sol.insertLeftNode(t->right, 4);
	sol.insertRightNode(t->right->left, 5);
	sol.insertRightNode(t->right, 6);
    sol.preorderTraversal(t); /* 1 2 3 4 5 6 */
	sol.inorderTraversal(t);   /* 2 1 4 5 3 6 */
    sol.postorderTraversal(t);  /* 2 5 4 6 3 1 */
}