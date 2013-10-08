#include <iostream>
#include <vector>

using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
private:
    TreeNode *buildSubTree(vector<int> &preorder, vector<int> &inorder, int preStart, int preEnd, int inStart, int inEnd) {
    	if (preStart > preEnd || inStart > inEnd) return NULL;
    	int preCount = 0;
    	int val = preorder[preStart];
    	for (int i=inStart; i<=inEnd; i++) {
    		if (inorder[i] == val) {
    			break;
    		}
    		preCount++;
    	}
    	TreeNode *root = new TreeNode(val);
    	root->left = buildSubTree(preorder, inorder, preStart+1, preStart+preCount, inStart, inStart+preCount-1);
    	root->right = buildSubTree(preorder, inorder, preStart+preCount+1, preEnd, inStart+preCount+1, inEnd);
    	return root;
    }

public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        return buildSubTree(preorder, inorder, 0, preorder.size()-1, 0, inorder.size()-1);
    }

    void printPreorderReverse (TreeNode *node) {
    	// cout << node << " ";
    	if (node) {
    		cout << node->val << " ";
			printPreorderReverse(node->left);
			printPreorderReverse(node->right);
		}
    }
};

int main (char *argv[], int argc) {
	int preArr[] = {1,2,4,7,3,5,6,8};
	int inArr[] = {4,7,2,1,5,3,8,6};
	vector<int> preVec(preArr, preArr+sizeof(preArr)/sizeof(int));
	vector<int> inVec(inArr, inArr+sizeof(inArr)/sizeof(int));
	Solution sol;
	TreeNode *root = sol.buildTree(preVec, inVec);
	sol.printPreorderReverse(root);
	return 0;
}