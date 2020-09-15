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

// Definition for a Node.
class Node {
public:
	int val;
	Node* next;
	Node* random;

	Node(int _val) {
		val = _val;
		next = NULL;
		random = NULL;
	}
};

class Solution {
public:
	Node* copyRandomList(Node* head) {
		vector<Node*> v;
		unordered_map<Node*, int> map;
		
		if (head == NULL) { return NULL; }
		Node* ans = new Node(head->val);
		Node* node = head->next;
		Node* node2 = ans;	
		int index = 0;
		map[head] = index;
		index++;
		v.push_back(node2);
		
		while (node != NULL) {
			map[node] = index;
			index++;

			node2->next = new Node(node->val);
			v.push_back(node2->next);
			node = node->next;
			node2 = node2->next;
		}

		node = head;
		node2 = ans;
		while (node != NULL) {
			if (node->random == NULL) {
				node2->random = NULL;
			}
			else {
				node2->random = v[map[node->random]];
			}
			node = node->next;
			node2 = node2->next;
		}
		return ans;
	}
};