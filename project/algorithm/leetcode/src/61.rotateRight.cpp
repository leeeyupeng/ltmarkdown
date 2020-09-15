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
	ListNode* rotateRight(ListNode* head, int k) {
		if (head == NULL || head->next == NULL) { return head; }
		ListNode* node = head;
		int n = 0;
		while (node != NULL) { node = node->next; n++; }
		k = k % n;
		if (k == 0) { return head; }
		node = head;
		ListNode* left1 = head;
		ListNode* right1;
		ListNode* left2;
		ListNode* right2;
		int index = 1;
		while (node != NULL) {
			if (index == n-k) { right1 = node; }
			else if (index == n-k+1) { left2 = node; }
			if (node->next == NULL) { right2 = node; }
			node = node->next;
			index++;
		}
		right2->next = left1;
		right1->next = NULL;
		return left2;
	}
};