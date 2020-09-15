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
	vector<string> ans;
	void dfs(TreeNode* node, string& path) {		
		if (node->left == NULL && node->right == NULL) {
			string str = to_string(node->val);
			int length = str.length();
			for (int i = 0; i < length; i++) {
				path.push_back(str[i]);
			}
			ans.push_back(path);
			for (int i = 0; i < length; i++) {
				path.pop_back();
			}
			return;
		}		
		string str = to_string(node->val);
		int length = str.length();
		for (int i = 0; i < length; i++) {
			path.push_back(str[i]);
		}
		path.push_back('-');
		path.push_back('>');
		if (node->left != NULL) {
			dfs(node->left,path);
		}
		if (node->right != NULL) {
			dfs(node->right, path);
		}
		path.pop_back();
		path.pop_back();
		for (int i = 0; i < length; i++) {
			path.pop_back();
		}
	}
public:
	vector<string> binaryTreePaths(TreeNode* root) {
		if (root == NULL) { return vector<string>(); }
		string path;
		dfs(root,path);
		return ans;
	}
};