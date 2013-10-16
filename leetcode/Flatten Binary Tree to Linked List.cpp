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
	void flatten(TreeNode *curNode, TreeNode *&leftLastNode) {
		if (curNode) {
			TreeNode *rightNode = curNode->right;
			leftLastNode = curNode;
			if (curNode->left) {
				flatten(curNode->left, leftLastNode);
				curNode->right = curNode->left;
				curNode->left = NULL;
			}
			if (leftLastNode) {
				leftLastNode->right = rightNode;
			}
			if (rightNode) {
				flatten(rightNode, leftLastNode);
			}
		}
	}

public:
    void flatten(TreeNode *root) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
    	TreeNode *leftLastNode = NULL;
    	flatten(root, leftLastNode);
    }
};

int main (char *argv[], int argc) {
	TreeNode *t1 = new TreeNode(1);
	TreeNode *t2 = new TreeNode(2);
	TreeNode *t3 = new TreeNode(3);
	t1->left = t2;
	t1->right = t3;
	Solution sol;
	sol.flatten(t1);
	while (t1) {
		cout << t1->val << endl;
		t1= t1->right;
	}
	return 0;
}