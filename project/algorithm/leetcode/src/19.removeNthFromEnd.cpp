#include"leetcode.h"
 // Definition for singly-linked list.
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
 
class Solution {
public:
	ListNode* removeNthFromEnd(ListNode* head, int n) {
		int nums = 0;
		ListNode* node = head;
		while (node != NULL) { nums++; node = node->next; }

		int k = nums - n;
		node = head;
		if (k == 1) { return head->next; }
		while (k > 1) {
			node = node->next;
			k--;
		}
		node->next = node->next->next;
		return head;
	}
};