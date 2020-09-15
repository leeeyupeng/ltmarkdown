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
private:
	 void dfs(ListNode* node, ListNode* &left, ListNode* &right) {
		 if (node->next == NULL) {
			 left = node;
			 right = node;
		 }
		 else {
			 dfs(node->next, left, right);
			 right->next = node;
			 right = right->next;
		 }
	}
public:
	ListNode* reverseList(ListNode* head) {
		if (head == NULL) { return NULL; }
		ListNode* node = head;
		ListNode* left;
		ListNode* right;
		dfs(node, left, right);
		right->next = NULL;
		return left;
	}
};