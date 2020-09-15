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
	ListNode* reverseBetween(ListNode* head, int m, int n) {
		ListNode* root = new ListNode(0);
		root->next = head;
		ListNode* left;
		ListNode* right;
		stack<ListNode*> s;
		int index = 0;
		ListNode* node = root;
		while (node != NULL) {
			if (index == m-1) {
				left = node;
			}
			else if (index == n+1) {
				right = node;
			}
			else if (index >= m && index <= n) {
				s.push(node);
			}
			node = node->next;
			index++;
		}
		node = left;
		while (!s.empty()) {
			node->next = s.top();
			s.pop();
			node = node->next;
		}
		node->next = right;
		ListNode* ans = root->next;
		delete root;
		return ans;
	}
};