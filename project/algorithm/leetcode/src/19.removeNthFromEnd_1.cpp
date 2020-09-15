#include"leetcode.h"
 // Definition for singly-linked list.
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
 
class Solution {
private:
	vector<ListNode*> vnode;
public:
	ListNode* removeNthFromEnd(ListNode* head, int n) {
		int nums = 0;
		ListNode* node = head;
		while (node != NULL) { vnode.push_back(node); nums++; node = node->next; }

		int k = nums - n;
		if (k == 0) { return head->next; }
		node = vnode[k-1];
		node->next = node->next->next;
		return head;
	}
};