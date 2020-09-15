#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <functional>
#include <queue>
#include<string>
#include<map>
#include<unordered_map>
#include<unordered_set>
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
	int dfs(TreeNode* node, int depth) {
		if (node == NULL) { return depth; }
		return max(dfs(node->left, depth + 1), dfs(node->right, depth + 1));
	}
public:
	int maxDepth(TreeNode* root) {
		return dfs(root,0);
	}
};