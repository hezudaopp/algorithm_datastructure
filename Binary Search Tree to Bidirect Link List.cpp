#include <iostream>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode (int x) : val(x), left(NULL), right(NULL){}
};

void binarySearchTreeToBidirectLinkList(TreeNode *curNode, TreeNode *&leftLastNode) {
	if (curNode) {
		if (curNode->left) {
			binarySearchTreeToBidirectLinkList(curNode->left, leftLastNode);
		}
		curNode->left = leftLastNode;
		if (leftLastNode)
			leftLastNode->right = curNode;
		leftLastNode = curNode;
		if (curNode->right) {
			binarySearchTreeToBidirectLinkList(curNode->right, leftLastNode);
		}
	}
}

TreeNode *binarySearchTreeToBidirectLinkList(TreeNode *root) {
	TreeNode *leftLastNode = NULL;
	binarySearchTreeToBidirectLinkList(root, leftLastNode);
	while (leftLastNode && leftLastNode->left) {
		leftLastNode = leftLastNode->left;
	}
	return leftLastNode;
}

int main (char *argv[], int argc) {
	TreeNode *t1 = new TreeNode(3);
	TreeNode *t2 = new TreeNode(1);
	TreeNode *t3 = new TreeNode(5);
	t1->left = t2;
	t1->right = t3;
	TreeNode *t4 = new TreeNode(2);
	TreeNode *t5 = new TreeNode(4);
	t2->right = t4;
	t3->left = t5;
	TreeNode *startNode = binarySearchTreeToBidirectLinkList(t1);
	while (startNode) {
		cout << startNode->val << endl;
		startNode = startNode->right;
	}
	return 0;
}