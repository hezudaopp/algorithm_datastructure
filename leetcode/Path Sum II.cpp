#include <vector>
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
	void buildPathSum(TreeNode *node, int sum, vector<vector<int> > &result, vector<int> path) {
		path.push_back(node->val);
		if (!node->left && !node->right) {
			if (sum == node->val) {
				result.push_back(path);
			} else {
				return;
			}
		}
		if (node->left) {
			buildPathSum(node->left, sum-node->val, result, path);
		}
		if (node->right) {
			buildPathSum(node->right, sum-node->val, result, path);
		}
	}	

public:
    vector<vector<int> > pathSum(TreeNode *root, int sum) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        vector<vector<int> > result;
        if (!root) return result;
        vector<int> path;
        buildPathSum(root, sum, result, path);
        return result;
    }
};

int main (char *argv[], int argc) {
	TreeNode *t1 = new TreeNode(5);
	TreeNode *t2 = new TreeNode(4);
	TreeNode *t3 = new TreeNode(8);
	t1->left = t2;
	t1->right = t3;
	TreeNode *t4 = new TreeNode(11);
	TreeNode *t5 = new TreeNode(13);
	TreeNode *t6 = new TreeNode(4);
	t2->left = t4;
	t3->left = t5;
	t3->right = t6;
	TreeNode *t7 = new TreeNode(7);
	TreeNode *t8 = new TreeNode(2);
	TreeNode *t9 = new TreeNode(5);
	TreeNode *t10 = new TreeNode(1);
	t4->left = t7;
	t4->right = t8;
	t6->left = t9;
	t6->right = t10;
	vector<vector<int> > result;
	Solution sol;
	result = sol.pathSum(t1, 22);
	cout << result.size() << endl;
	return 0;
}