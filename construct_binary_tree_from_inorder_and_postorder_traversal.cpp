#include <vector>
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
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        // cout << 1 << endl;
     	TreeNode *result;
     	constructTree(result, inorder, postorder, 0, inorder.size()-1, 0, postorder.size()-1);
     	return result;
    }

    void constructTree(TreeNode *&t, std::vector<int> &inorder, std::vector<int> &postorder, int in_start, int in_end, int post_start, int post_end) {
    	if (in_start > in_end || post_start > post_end) {
            t = NULL;
            return;
        }
    	t = new TreeNode(postorder[post_end]);
     	// std::vector<int>::iterator it = find(inorder.begin()+begin, inorder.begin()+end, t->val);
        int i;
        for (i=in_start; i<=in_end; i++) {
            if (inorder[i] == t->val) {
                break;
            }
        }
        int offset = i - in_start;
     	if (in_start < i) {
            // cout << offset << endl;
	     	// std::vector<int> leftInorder(inorder.begin(), it);
	     	// std::vector<int> leftPostorder(postorder.begin(), postorder.begin()+offset);
	     	// for (std::vector<int>::iterator i = postorder.begin(); i<postorder.end()-1; ++i) {
	     	// 	if (find(leftInorder.begin(), leftInorder.end(), *i ) != leftInorder.end()) {
	     	// 		leftPostorder.push_back(*i);
	     	// 	}
	     	// 	continue;
	     	// }
            // printVector(inorder, in_start, i-1);
            // printVector(postorder, post_start, post_start+offset-1);
	     	constructTree(t->left, inorder, postorder, in_start, i-1, post_start, post_start+offset-1);
	    }
     	if (i < in_end) {
     		// std::vector<int> rightInorder(it+1, inorder.end());
     		// std::vector<int> rightPostorder(postorder.begin()+offset, postorder.end()-1);
     		// for (std::vector<int>::iterator i = postorder.begin(); i<postorder.end()-1; ++i) {
	     	// 	if (find(rightInorder.begin(), rightInorder.end(), *i) != rightInorder.end()) {
	     	// 		rightPostorder.push_back(*i);
	     	// 	}
	     	// 	continue;
	     	// }
            // printVector(inorder, i+1, in_end);
            // printVector(postorder, post_start+offset, post_end-1);
     		constructTree(t->right, inorder, postorder, i+1, in_end, post_start+offset, post_end-1);
     	}
    }
private:
	void printVector(std::vector<int> v, int start, int end) {
		for (int i=start; i<=end; i++) {
			cout << v[i] << " ";
		}
		cout << endl;
	}
};

int main (int argc, char *argv[]) {
	int my_ints[] = {2,1};
	int my_ints1[] = {2,1};
    std::vector<int> v(my_ints, my_ints+sizeof(my_ints)/sizeof(int));
    std::vector<int> v1(my_ints1, my_ints1+sizeof(my_ints1)/sizeof(int));
    Solution sol;
    sol.buildTree(v, v1);
    return 0;
}