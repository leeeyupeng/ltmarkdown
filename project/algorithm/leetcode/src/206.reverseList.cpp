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
	ListNode* reverseList(ListNode* head) {
		if (head == NULL) { return NULL; }
		ListNode* node = head;
		stack<ListNode*>  s;
		while (node != NULL) {
			s.push(node);
			node = node->next;
		}
		node = s.top();
		s.pop();
		ListNode* ans = node;
		while (!s.empty()) {
			node->next = s.top();
			s.pop();
			node = node->next;
		}
		node->next = NULL;
		return ans;
	}
};