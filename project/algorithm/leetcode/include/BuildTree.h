#pragma once
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include<string>
#include<algorithm>

using namespace std;

//https://leetcode-cn.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/
// Definition for a binary tree node.
 struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

 TreeNode* buildTree_p(vector<int>& inorder, vector<int>& postorder, vector<TreeNode*>&  nodes, int i1, int i2, int j1, int j2)
 {
	 int rootindex = -1;
	 for (int i = i1; i < i2; i++)
	 {
		 if (inorder[i] == postorder[j2 - 1])
		 {
			 rootindex = i;
		 }
	 }

	 if (rootindex == -1)
	 {
		 return NULL;
	 }

	 TreeNode* node = nodes[rootindex];

	 if (rootindex > i1)
	 {
		 node->left = buildTree_p(inorder, postorder, nodes, i1, rootindex, j1, j1 + rootindex - i1);
	 }
	 else
	 {
		 node->left = NULL;
	 }
	 if (i2 > rootindex + 1)
	 {
		 node->right = buildTree_p(inorder, postorder, nodes, rootindex + 1, i2, j1 + rootindex - i1, j2 - 1);
	 }
	 else
	 {
		 node->right = NULL;
	 }

	 return node;

 }

TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder)
{
	TreeNode* root = NULL;
	vector<TreeNode*>  nodes;
	for (int i = 0; i < inorder.size(); i++)
	{
		nodes.push_back(new TreeNode(inorder[i]));
	}

	return buildTree_p(inorder,postorder,nodes,0,inorder.size(),0,postorder.size());
}
