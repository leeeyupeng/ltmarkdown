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

// Definition for a binary tree node.
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	vector<vector<int>> levelOrder(TreeNode* root) {
		vector <vector<int>> ans;
		queue<TreeNode*> qnode1;
		
		qnode1.push(root);
		TreeNode* node;
		while (!qnode1.empty()) {
			vector<int> ans1;
			queue<TreeNode*> qnode2;
			while (!qnode1.empty()) {
				node = qnode1.front();
				qnode1.pop();
				if (node == NULL) { continue; }
				ans1.push_back(node->val);
				qnode2.push(node->left); 
				qnode2.push(node->right); 
			}
			qnode1 = qnode2;
			if (!ans1.empty()) {
				ans.push_back(ans1);
			}
		}
		return ans;
	}
};