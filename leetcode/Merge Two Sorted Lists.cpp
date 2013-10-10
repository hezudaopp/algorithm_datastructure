#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        ListNode *newList = NULL;
        if (l1 && l2) {
        	if (l1->val <= l2->val) {
        		newList = l1;
        		l1 = l1->next;
        	} else {
        		newList = l2;
        		l2 = l2->next;
        	}
        } else  if (l1) {
        	newList = l1;
        	l1 = l1->next;
        } else if (l2) {
        	newList = l2;
        	l2 = l2->next;
        }
        ListNode *cur = newList;
        while (l1 && l2) {
        	if (l1->val <= l2->val) {
        		cur->next = l1;
        		l1 = l1->next;
        	} else {
        		cur->next = l2;
        		l2 = l2->next;
        	}
        	cur =  cur->next;
        }
        if (l1) {
        	cur->next = l1;
        }
        if (l2) {
        	cur->next = l2;
        }
        return newList;
    }
};

int main (char *argv[], int argc) {
	ListNode *l1 = new ListNode(1), *l2 =new ListNode(2), *l3 = new ListNode(3), *l4 = new ListNode(4), *l5 = new ListNode(5),
	*l6 = new ListNode(6), *l7 = new ListNode(7), *l8 = new ListNode(8), *l9 = new ListNode(9);
	l1->next = l3;
	l3->next = l5;
	l5->next = l7;
	l7->next = l8;
	l8->next = l9;
	l2->next = l4;
	l4->next = l6;
	Solution sol;
	ListNode *newList = sol.mergeTwoLists(l1, l2);
	while (newList) {
		cout << newList->val << endl;
		newList = newList->next;
	}
	return 0;
}