#include <iostream>

using namespace std;

struct node
{
	int val;
	node *left;
	node *right;
	node(int x) : val(x), left(NULL), right(NULL) {}
};

void preOrderTraversal (node *r) {
	if (r != NULL) {
		cout << r->val << " ";
		preOrderTraversal(r->left);
		preOrderTraversal(r->right);
	}
}

node *copyBinaryTree(node *root) {
	node *result = NULL;
	if (root != NULL) {
		result = new node(root->val);
		node *left = copyBinaryTree(root->left);
		node *right = copyBinaryTree(root->right);
		result->left = left;
		result->right = right;
	}
	return result;
}

int main (char *argv, int argc) {
	node *root = new node(0);
	root->left = new node(1);
	root->right = new node(2);
	root->left->right = new node(3);
	root->right->left = new node(4);
	root->left->right->right = new node(5);
	root->right->left->right = new node(6);
	preOrderTraversal(root);
	cout << endl;
	preOrderTraversal(copyBinaryTree(root));
	cout << endl;
	return 0;
}