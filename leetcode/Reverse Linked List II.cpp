#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        int start = 1;
        ListNode *cur = head;
        ListNode *preNode = NULL;
        while (cur && start < m) {
        	preNode = cur;
        	cur = cur->next;
        	start++;
        }
        ListNode *pre = NULL;
        while (cur && start <= n) {
        	ListNode *next = cur->next;
        	cur->next = pre;
        	pre = cur;
        	cur = next;
        	start++;
        }
        if (preNode) {
        	if (preNode->next) {
        		preNode->next->next = cur;
        	}
        	preNode->next = pre;
        } else {
        	head->next = cur;
        	head = pre;
        }
        return head;
    }
};

int main (char *argv, int argc) {
	ListNode *l1 = new ListNode(1), *l2 =new ListNode(2), *l3 = new ListNode(3), *l4 = new ListNode(4), *l5 = new ListNode(5);
	l1->next = l2;
	l2->next = l3;
	l3->next = l4;
	l4->next = l5;
	ListNode *cur = l1;
	while (cur) {
		cout << cur->val << " ";
		cur = cur->next;
	}
	cout << endl;
	Solution sol;
	cur = sol.reverseBetween(l1, 1, 4);
	while (cur) {
		cout << cur->val << " ";
		cur = cur->next;
	}
	cout << endl;
	return 0;
}