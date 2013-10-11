#include <iostream>

using namespace std;

typedef struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode (int v) : val(v), left(NULL), right (NULL) {}
} Node;

bool containsTree (Node *t1, Node *t2) {
	if (t2 == NULL) return true;
	if (t1 == NULL && t2 == NULL) return true;
	if (t1 == NULL) return false;
	if (t1->val != t2->val) {
		return false;
	} else {
		return (containsTree(t1->left, t2->left) && containsTree (t1->right, t2->right));
	}
}

int main (char *argv[], int argc) {
	Node *t1 = new Node(2);
	Node *t2 = new Node(2);
	Node *t3 = new Node(3);
	t1->left = t3;
	cout << containsTree (t2, t1) << endl;
	return 0;
}