#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <functional>
#include <queue>
#include<string>
#include<map>
#include<unordered_map>

#if defined(linux)
#include<memory.h>
#include<limits.h>
#endif
using namespace std;

 // Definition for singly-linked list.
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
 
class Solution {
public:
	ListNode* insertionSortList(ListNode* head) {
		if (head == NULL || head->next == NULL) { return head; }
		ListNode* root = new ListNode(INT_MIN);
		ListNode* node = head;

		ListNode* pre;
		ListNode* now;
		while (node != NULL) {
			now = node;
			node = node->next;
			pre = root;
			while (pre->next != NULL && pre->next->val < now->val) { pre = pre->next; }
			now->next = pre->next;
			pre->next = now;			
		}

		ListNode* ans = root->next;
		delete root;
		return ans;
	}
};