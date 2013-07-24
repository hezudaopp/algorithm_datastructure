#include <queue>
#include <algorithm>
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
    bool isBalanced(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (root == NULL) return true;
        bool result = true;
        height(root, result);
        return result;
      //   std::queue<TreeNode *> q;
      //   q.push(root);
      //   TreeNode *end = root;
      //   int level = 1;
      //   int first_level = 0;
      //   int diff;
      //   while (!q.empty()) {
      //   	TreeNode *t = q.front();
      //   	q.pop();
    		// if (first_level > 0 && level > first_level) {
    		// 	// cout << "cur_level:" << level << endl;
    		// 	diff = level - first_level;
    		// 	if (diff > 1) return false;
    		// }
      //   	if (t->left == NULL && t->right == NULL) {
      //   		if (first_level == 0) {
      //   			first_level = level;
      //   			// cout << "first_level:" << first_level << endl;
      //   		}
      //   	}
      //   	if (t->left != NULL) q.push(t->left);
      //   	if (t->right != NULL) q.push(t->right);
      //   	if (t == end) {
      //   		level++;
      //   		// cout << "end:" << end->val << endl;
      //   		end = q.back();
      //   	}
      //   }

        // root->val = 1;
        // deepTraverse(root);
        // int first_height = v[0];
        // for (std::vector<int>::iterator it = v.begin(); it!=v.end(); it++) {
        // 	int diff = abs(first_height - (*it));
        // 	cout << diff << endl;
        // 	if (diff > 1) return false;
        // }
        // return true;
    }

  void insertLeftNode(TreeNode *t, int value) {
		TreeNode *node = new TreeNode(value);
		t->left = node;
	}

	void insertRightNode(TreeNode *t, int value) {
		TreeNode *node = new TreeNode(value);
		t->right = node;
	}
private:
	int height(TreeNode *t, bool &isBalanced) {
		const int left_height = t->left == NULL ? 0 : height(t->left, isBalanced)+1;
		if (!isBalanced) return 0;
		const int right_height = t->right == NULL ? 0 : height(t->right, isBalanced)+1;
		if (!isBalanced) return 0;
		int diff = left_height - right_height;
		if (diff > 1 || diff < -1) {
			isBalanced = false;
		}
		return left_height > right_height ? left_height : right_height;
	}
// private:
// 	std::vector<int> v;
// 	void deepTraverse(TreeNode *sub_tree) {
// 		if (sub_tree->left == NULL && sub_tree->right == NULL) {
// 			v.push_back(sub_tree->val);
// 		}
// 		if (sub_tree->left != NULL) {
// 			sub_tree->left->val = sub_tree->val + 1;
// 			deepTraverse(sub_tree->left);
// 		}
// 		if (sub_tree->right != NULL) {
// 			sub_tree->right->val = sub_tree->val + 1;
// 			deepTraverse(sub_tree->right);
// 		}
// 	}
};

  int main (int argc, char* argv[]) {
  	TreeNode *t = new TreeNode(2);
  	Solution sol;
  	// sol.insertLeftNode(t, 1);
  	// sol.insertLeftNode(t->left, 3);
  	// sol.insertLeftNode(t->left->left, 5);
  	sol.insertRightNode(t, 5);
  	sol.insertRightNode(t->right, 3);
  	cout << sol.isBalanced(t) << endl;
  }