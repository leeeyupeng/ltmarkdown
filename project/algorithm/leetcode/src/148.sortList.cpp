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
	void quicksort(ListNode* &left,ListNode* &right) {
		ListNode* s;
		ListNode* lefts = NULL, *lefte = NULL, *rights = NULL, *righte = NULL;
		ListNode* node = left;
		ListNode* temp;
		s = node;
		node = node->next;
		s->next = NULL;
		while (node != NULL) {
			if (node->val <= s->val) {
				if (lefts == NULL) { lefts = node; lefte = lefts; }
				else {
					lefte->next = node;
					lefte = lefte->next;
				}
			}
			else
			{
				if (rights == NULL) { rights = node; righte = rights; }
				else {
					righte->next = node;
					righte = righte->next;
				}
			}
			temp = node->next;
			node->next = NULL;
			node = temp;
		}		

		if (lefts != NULL) {
			lefte->next == NULL;
			quicksort(lefts, lefte);
		}
		if (rights != NULL) {
			righte->next == NULL;
			quicksort(rights, righte);
		}
		if (lefts == NULL) {
			left = s;
		}
		else {
			left = lefts;
			lefte->next = s;
		}
		if (rights == NULL) {
			s->next = NULL;
			right = s;
		}
		else {
			s->next = rights;
			righte->next = NULL;
			right = righte;
		}
	}
public:
	ListNode* sortList(ListNode* head) {
		if (head == NULL) { return head; }
		ListNode* start = head;
		ListNode* end = head;
		while (end->next != NULL) {
			end = end->next;
		}
		quicksort(start, end);
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