#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <queue>
#include<string>
#include<map>
#include<unordered_map>
using namespace std;

 //Definition for a binary tree node.
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 
class Solution {
	vector<int> path;
	vector<string> ans;
	void write() {
		if (path.empty()) { return; }
		string str;
		int i;
		for (i = 0; i < path.size() - 1; i++) {
			str += to_string(path[i]) + "->";
		}
		str += to_string(path[i]);
		ans.push_back(str);
	}
	void dfs(TreeNode* node) {
		path.push_back(node->val);
		if (node->left == NULL && node->right == NULL) {
			write();
		}

		if (node->left != NULL) {
			dfs(node->left);
		}
		if (node->right != NULL) {
			dfs(node->right);
		}
		path.pop_back();
	}
public:
	vector<string> binaryTreePaths(TreeNode* root) {
		if (root == NULL) { return vector<string>(); }
		dfs(root);
		return ans;
	}
};