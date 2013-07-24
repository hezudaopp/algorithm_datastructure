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
    vector<int> inorderTraversal(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        std::vector<int> result;
        std::stack<TreeNode * > s;
        if (root == NULL) return result;
        TreeNode *t = root;
        while (t != NULL) {
    		s.push(t);
    		t = t->left;
    	}
        do {
        	TreeNode *tmp = s.top();
        	// cout << tmp->val << endl;
        	s.pop();
        	result.push_back(tmp->val);
        	t = tmp->right;
        	// if (t != NULL) cout << t->val << endl;
        	while (t != NULL) {
        		s.push(t);
        		t = t->left;
        	}
        } while (!s.empty());
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
	TreeNode *t = new TreeNode(2);
	Solution sol;
	sol.insertLeftNode(t, 1);
	sol.insertRightNode(t, 5);
	sol.insertRightNode(t->left, 3);
	sol.insertLeftNode(t->right, 4);
	sol.insertLeftNode(t->left->right, 6);
	sol.inorderTraversal(t);
}