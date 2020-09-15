#include <iostream>
#include <vector>
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
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
 
class Solution {
public:
	ListNode* oddEvenList(ListNode* head) {
		ListNode* now = head;
		ListNode* odd = NULL;
		ListNode* even = NULL;		
		if (now != NULL) {
			odd = now;
			now = now->next;
		}
		if (now != NULL) {
			even = now;
			now = now->next;
		}

		ListNode* nowodd = odd;
		ListNode* noweven = even;

		while (now != NULL) {
			nowodd->next = now;
			nowodd = nowodd->next;
			now = now->next;

			if (now != NULL) {
				noweven->next = now;
				noweven = noweven->next;
				now = now->next;
			}
		}
		if (nowodd != NULL) { nowodd->next = even; }
		if (noweven != NULL) { noweven->next = NULL; }
		return odd;
	}
};

//int main() {
//
//	Solution s;
//	ListNode* root;
//	root = new ListNode(1);
//	ListNode* node = root;
//	for (int i = 2; i <= 3; i++) {
//		node->next = new ListNode(i);
//		node = node->next;
//	}
//	ListNode* ans = s.oddEvenList(root);
//	//cout << "ans:" << ans << endl;
//	system("PAUSE");
//
//	return 0;
//}