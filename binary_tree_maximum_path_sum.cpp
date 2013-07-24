#include <iostream>
#include <climits>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int maxPathSum(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (root == NULL) return 0;
        int max_sum = INT_MIN;
        maxSubSum(root, max_sum);
        if (root->val > max_sum)
          max_sum = root->val;
        return max_sum;
  //       int result = root->val;
  //       if (root-> left != NULL && root->right != NULL) {
	 //        int left = maxSubSum(root->left);
	 //        int right = maxSubSum(root->right);
	 //        if (left > result) result = left;
	 //        if (right > result) result = right;
	 //        if ((left + root->val) > result) result = left + root->val;
	 //        if ((right + root->val) > result) result = right + root->val;
	 //        if ((left + right + root->val) > result) result = left + right + root->val;
  //       } else if (root->left == NULL && root->right != NULL) {
  //       	int right = maxSubSum(root->right);
  //       	if (right > 0) result = max(right+root->val, right);
  //       	else result =  max(right, root->val);
		// } else if (root->left != NULL && root->right == NULL) {
		// 	int left = maxSubSum(root->left);
  //       	if (left > 0) result = max(left+root->val, left);
  //       	else result =  max(left, root->val);
		// }
  //       return result;
    }

    void maxSubSum(TreeNode *root, int &max_sum) {
      if (!root) return;
      else {
        maxSubSum(root->left, max_sum);
        maxSubSum(root->right, max_sum);
        // find the max value in (root->val, root->left->val+root->val, root->right->val+root->val,
        // root->val + root->right->val + root->left->val); which is mean the sum of maximum path which
        // end with root
        int left = 0, right = 0;
        if (root->left) {
          left = root->left->val;
        }
        if (root->right) {
          right = root->right->val;
        }
        if (root->val + left + right > max_sum) max_sum = root->val + left + right;
        if (left+root->val > max_sum) max_sum = root->val + left;
        if (right+root->val > max_sum) max_sum = root->val + right;
        if (root->val > max_sum) max_sum = root->val;

        // root->val equals the sum of maximum path which will go through root
        int left_sum = left + root->val;
        int right_sum = right + root->val;
        root->val = max(max(left_sum, right_sum), root->val);
      }
		// if (root->left == NULL && root->right == NULL) return root->val;
		// else if (root->left != NULL && root->right != NULL) {
		// 	return max(max(maxSubSum(root->left)+root->val, maxSubSum(root->right)+root->val), root->val);
		// } else if (root->left == NULL && root->right != NULL) {
		// 	return max(maxSubSum(root->right)+root->val, root->val);
		// } else if (root->left != NULL && root->right == NULL) {
		// 	return max(maxSubSum(root->left)+root->val, root->val);
		// }
    }
};