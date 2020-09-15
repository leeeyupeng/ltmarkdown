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
private:
	vector<int> ans;
	void order(TreeNode* node) {
		if (node == NULL) { return; }
		ans.push_back(node->val);
		order(node->left);
		order(node->right);
	}
public:
	vector<int> preorderTraversal(TreeNode* root) {
		order(root);
		return ans;
	}
};