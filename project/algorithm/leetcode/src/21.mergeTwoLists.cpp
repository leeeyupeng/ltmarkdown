#include"leetcode.h"

 // Definition for singly-linked list.
struct ListNode {
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 
class Solution {
public:
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
		ListNode* head = new ListNode();
		ListNode* node = head;
		ListNode* node1 = l1;
		ListNode* node2 = l2;
		while (node1 != nullptr && node2 != nullptr) {
			if (node1->val <= node2->val) {
				node->next = node1;
				node1 = node1->next;
				node = node->next;
			}
			else {
				node->next = node2;
				node2 = node2->next;
				node = node->next;
			}
		}
		if (node1 != nullptr) { node->next = node1; }
		else { node->next = node2; }
		node = head->next;
		delete head;
		return node;
	}
};