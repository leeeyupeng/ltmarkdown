#pragma once
//https://leetcode-cn.com/problems/add-two-numbers/
#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <set>
#include <stack>
#include<string>
#include<algorithm>

using namespace std;
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {		
		stack<char> s1;
		while (l1 != NULL) {
			s1.push(l1->val);
			l1 = l1->next;
		}
		stack<char> s2;
		while (l2 != NULL) {
			s2.push(l2->val);
			l2 = l2->next;
		}
		ListNode* ans=NULL;
		ListNode* ll=NULL;
		char temp = 0;
		char flagCarry = 0;
		while (!s1.empty() || !s2.empty() || flagCarry == 1) {
			temp = (s1.empty() ? 0 : s1.top()) + (s2.empty() ? 0 : s2.top()) + flagCarry;
			if (!s1.empty()) { s1.pop(); }
			if (!s2.empty()) { s2.pop(); }
			flagCarry = temp >= 10 ? 1 : 0;
			ans = new ListNode(temp - (flagCarry == 1 ? 10 : 0));
			ans->next = ll;
			ll = ans;
		}
		return ans;
	}
};
