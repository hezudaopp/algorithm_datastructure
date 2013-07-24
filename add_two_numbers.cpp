#include <iostream>

using namespace std;

struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int last = 0;
        ListNode *cur_l1 = l1, *cur_l2 = l2;
        ListNode *result = new ListNode(-1);
        ListNode *cur = result;
        // cout << result << endl;
        while (cur_l1 != NULL || cur_l2 != NULL || last  == 1) {
        	int val1 = (cur_l1 == NULL) ? 0 : cur_l1->val;
        	int val2 = (cur_l2 == NULL) ? 0 : cur_l2->val;
        	int sum = val1 + val2 + last;
        	// cout << val1 << " " << val2 << " " << sum << endl;
        	if (sum >= 10 ) {
        		last = 1;
        		cur = appendNode(cur, sum-10);
        	} else {
        		last = 0;
        		cur = appendNode(cur, sum);
        	}
        	// cout << cur << result << endl;
        	if (cur_l1 != NULL) cur_l1 = cur_l1->next;
        	if (cur_l2 != NULL) cur_l2 = cur_l2->next;
        }
        return result->next;
    }

	ListNode *appendNode(ListNode *res, int val) {
		// cout << val << endl;
		ListNode *l = new ListNode(val);
		res->next = l;
		res = res->next;
		return res;
	}
};

int main (int argc, char *argv[]) {
	Solution sol;
	ListNode *l1 = new ListNode(9);
	ListNode *h1 = l1;
	h1 = sol.appendNode(h1, 1);
	h1 = sol.appendNode(h1, 6);
	ListNode *l2 = new ListNode(0);
	// ListNode *h2 = l2;
	// h2 = sol.appendNode(h2, 6);
	// h2 = sol.appendNode(h2, 4);
	ListNode *result = sol.addTwoNumbers(l1, l2);
	cout << result->val << endl;
}