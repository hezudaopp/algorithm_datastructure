#include <iostream>
#include <vector>

using namespace std;

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        TreeNode *root = NULL;
        buildTree(root, inorder, 0, inorder.size()-1, postorder, 0, postorder.size()-1);
        return root;
    }

    void buildTree(TreeNode *&node, vector<int> &inorder, int inorderStart, int inorderEnd,
    					vector<int> &postorder, int postorderStart, int postorderEnd) {
    	// cout << inorderStart << " " << inorderEnd << " " << postorderStart << " " << postorderEnd << endl;
    	if ((inorderStart > inorderEnd) || (postorderStart > postorderEnd)) return;
    	// cout << postorderEnd << endl;
    	int nodeVal = postorder[postorderEnd];
    	node = new TreeNode(nodeVal);
    	int i;
    	for (i=inorderStart; i<=inorderEnd; i++) {
    		if (inorder[i] == nodeVal) break;
    	}
    	int postLeftOffset = i-inorderStart-1;
    	int postRightStart = postorderEnd-(inorderEnd-i);
       	buildTree(node->left, inorder, inorderStart, i-1, postorder, postorderStart, postorderStart+postLeftOffset);
    	buildTree(node->right, inorder, i+1, inorderEnd, postorder, postRightStart, postorderEnd-1);
    }

    void printPreorderReverse (TreeNode *node) {
    	// cout << node << " ";
    	if (node) {
    		cout << node->val << " ";
			printPreorderReverse(node->left);
			printPreorderReverse(node->right);
		}
    }

    // TreeNode *buildTree(vector<int> &inorder, vector<int> &preorder) {

    // }
};

int main (char *argv[], int argc) {
	// int preorderInts[] = {1, 2, 4, 5, 6, 7, 3};
	// int inorderInts[] = {4, 5, 2, 7, 6, 1, 3};
	// int postorderInts[] = {5, 4, 7, 6, 2, 3, 1};
	int inorderInts[] = {1, 2, 3, 4};
	int postorderInts[] = {3, 4, 2, 1};
	std::vector<int> inorder(inorderInts, inorderInts+sizeof(inorderInts)/sizeof(int));
	std::vector<int> postorder(postorderInts, postorderInts+sizeof(postorderInts)/sizeof(int));
	Solution sol;
	TreeNode *tree = sol.buildTree(inorder, postorder);
	sol.printPreorderReverse(tree);
	return 0;
}