#include <iostream>

using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


class Solution {
public:
    ListNode *rotateRight(ListNode *head, int k) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (k<=0 || !head) return head;
        ListNode *first = head, *second = head;
        int cur = 0;
        while (first->next != NULL) {
        	first = first->next;
        	cur++;
        	if (cur > k) {
        		second = second->next;
        	}
        }
        if (cur < k) {
        	k %= (cur+1);
        }
        first = head, second = head;
        cur = 0;
        while (first->next != NULL) {
        	first = first->next;
        	cur++;
        	if (cur > k) {
        		second = second->next;
        	}
        }
        first->next = head;
        head = second->next;
        second->next = NULL;
        return head;
    }
};