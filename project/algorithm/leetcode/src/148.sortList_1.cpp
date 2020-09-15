#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <queue>
#include<string>
#include<map>
#include<unordered_map>
#include<stack>
using namespace std;


 // Definition for singly-linked list.
  struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };
 
class Solution {
private:
	void mergesort(ListNode* &node,int n) {
		ListNode* left = node;
		ListNode* right = NULL;
		ListNode* middle = node;
		int i = n >> 1;
		while (i > 0) {
			middle = middle->next;
			i--;
		}
		right = middle;

		right = middle;
		mergesort(left,n>>1);
		mergesort(right, n-(n >> 1));
		while (left != NULL && right != NULL) {
			if (left->val <= right->val) {

			}
			else {
			}
		}

	}
public:
	ListNode* sortList(ListNode* head) {
		if (head == NULL) { return head; }
		ListNode* start = head;
		ListNode* end = head;
		int n = 1;
		while (end->next != NULL) {
			end = end->next;
			n++;
		}

		mergesort(start, n);
		return start;
	}
};

//int main() {
//
//	Solution s;
//	ListNode* root;
//	root = new ListNode(8);
//	ListNode* node = root;
//	node->next = new ListNode(2);
//	node = node->next;
//	node->next = new ListNode(6);
//	node = node->next;
//	node->next = new ListNode(5);
//	node = node->next;
//	node->next = new ListNode(48);
//	node = node->next;
//	node->next = new ListNode(2);
//	ListNode* ans = s.sortList(root);
//	//cout << "ans:" << ans << endl;
//	system("PAUSE");
//
//	return 0;
//}