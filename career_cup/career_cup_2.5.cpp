#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct Node {
	int val;
	Node *next;
};

Node *loop_begin_node(Node *head) {
	Node *node = head;
	if (node == NULL) return NULL;
	std::vector<Node *> v;
	v.push_back(node);
	while (node->next) {
		if (find (v.begin(), v.end(), node->next) != v.end()) {
			return node->next;
		} else {
			node = node->next;
			v.push_back(node);
		}
	}
	return NULL;
}

int main (int argc, char *argv[]) {
	Node *node = (Node *)malloc(sizeof(Node));
	Node *n1 = (Node *)malloc(sizeof(n1));
	node->val = 1;
	n1->val = 11111;
	node->next = n1;
	n1->next = n1;
	Node *result = loop_begin_node(node);
	if (result) cout << result->val << endl;	
}