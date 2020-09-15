#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <functional>
#include <queue>
#include<string>
#include<map>
#include<unordered_map>
using namespace std;


 // Definition for singly-linked list.
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
 
class Solution {
public:
	ListNode* deleteDuplicates(ListNode* head) {
		if (head == NULL || head->next == NULL) { return head; }
		ListNode* root = new ListNode(0);
		ListNode* pre = root;
		ListNode* last = head;
		ListNode* node = head->next;
		while (node != NULL) {
			if (last->val == node->val) {
				node = node->next;
			}
			else {
				if (last->next == node) {
					pre->next = last;
					pre = pre->next;
				}
				last = node;
				node = node->next;
			}
		}
		if (last->next == node) {
			pre->next = last;
			pre = pre->next;
		}
		pre->next = NULL;
		ListNode* ans = root->next;
		delete root;
		return ans;
	}
};