#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <queue>
#include<string>
#include<map>
#include<unordered_map>
using namespace std;

 // Definition for a binary tree node.
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 
struct NodeData {
	int val;
	int min;
	int max;
	bool isValidBST;
};
class Solution {
private:
	NodeData DFS(TreeNode* node) {
		NodeData data;
		data.val = node->val;
		data.min = node->val;
		data.max = node->val;
		if (node->left != NULL) {
			NodeData leftNode = DFS(node->left);
			if (leftNode.isValidBST == false) { data.isValidBST = false; return data; }
			if(leftNode.max >= data.val) { data.isValidBST = false; return data; }
			data.min = leftNode.min;
		}
		if (node->right != NULL) {
			NodeData rightNode = DFS(node->right);
			if (rightNode.isValidBST == false) { data.isValidBST = false; return data; }
			if (rightNode.min <= data.val) { data.isValidBST = false; return data; }
			data.max = rightNode.max;
		}
		data.isValidBST = true;
		return data;
	}
public:
	bool isValidBST(TreeNode* root) {
		if (root == NULL) { return true; }
		NodeData data = DFS(root);
		return data.isValidBST;
	}
};