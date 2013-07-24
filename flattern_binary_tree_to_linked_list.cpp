#include <stack>
#include <queue>
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
    void flatten(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
    	TreeNode *cur = root;
    	while (cur) {
            queue<TreeNode *> q;
    		firstTraverserLeft(cur, cur->left, q);
            TreeNode *right = cur->right;
    		while (!q.empty()) {
                cur->right = q.front();
                q.pop();
                cur = cur->right;
            }
            cur->right = right;
            cur = right;
    	}
    	while (root) {
    		cout << root->val << " ";
    		root = root->right;
    	}
    }

    void firstTraverserLeft(TreeNode *&cur, TreeNode *root, queue<TreeNode *> &q) {
    	stack<TreeNode *> s;
        while (root) {
            q.push(root);
            s.push(root);
            root = root->left;
        }
    	while (!s.empty()) {
    		TreeNode *node = s.top();
            s.pop();
    		if (node->right) {
                q.push(node->right);
    			s.push(node->right);
                node = node->right;
                while (node->left) {
                    q.push(node);
                    s.push(node);
                    node = node->left;
                }
    		}
    	}
    }
};

int main (int argc, char *argv[]) {
	Solution sol;
	TreeNode *t = new TreeNode(0);
	TreeNode *t1 = new TreeNode(1);
	// TreeNode *t2 = new TreeNode(2);
	// TreeNode *t3 = new TreeNode(3);
	// TreeNode *t4 = new TreeNode(4);
	// TreeNode *t5 = new TreeNode(5);
	// t->left = t1;
	t->right = t1;
	// t1->left = t3;
	// t3->left = t4;
	// t3->right = t5;
	sol.flatten(t);
	return 0;
}