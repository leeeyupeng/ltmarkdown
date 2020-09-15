#pragma once
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include<string>
#include<queue>
#include<algorithm>

using namespace std;
//https://leetcode-cn.com/problems/house-robber-iii/
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
	
};
struct InNotIn
{
	int in;
	int notin;
	InNotIn(int in, int notin) :in(in), notin(notin) {}
};
InNotIn DFS(TreeNode * node)
{
	if (node == NULL)
	{
		return InNotIn(0,0);
	}
	InNotIn left = DFS(node->left);
	InNotIn right = DFS(node->right);

	InNotIn out(0, 0);
	out.in = left.notin + right.notin + node->val;
	out.notin = (left.in > left.notin ? left.in : left.notin) + (right.in > right.notin ? right.in : right.notin);
	return out;
}
void PostOrder(TreeNode * node, int& in, int& notin)
{
	stack<TreeNode*> s;
	//s.push(node);
	TreeNode* top = NULL;
	TreeNode* pre = node;//用来标记右子树是是否已经访问
	TreeNode* cur = node;
	stack<int> sin;
	stack<int> snotin;
	int leftin, leftnotin, rightin, rightnotin;
	while (cur != NULL || !s.empty())
	{
		if (cur != NULL)
		{
			s.push(cur);
			while (cur != NULL)
			{
				cur = cur->left;
				s.push(cur);
			}
		}

		top = s.top();
		if (top == NULL)
		{
			sin.push(0);
			snotin.push(0);
			s.pop();
		}
		else if (pre == NULL || pre == top->right)
		{
			rightin = sin.top();
			sin.pop();
			leftin = sin.top();
			sin.pop();
			rightnotin = snotin.top();
			snotin.pop();
			leftnotin = snotin.top();
			snotin.pop();

			in = leftnotin + rightnotin + top->val;
			notin = (leftin > leftnotin ? leftin : leftnotin) + (rightin > rightnotin ? rightin : rightnotin);
			sin.push(in);
			snotin.push(notin);

			pre = top;
			s.pop();
		}
		else if (top->right == NULL)
		{
			s.push(top->right);
			pre = top->right;
		}
		else
		{
			cur = top->right;
		}
	}

	if (!sin.empty())
	{
		in = sin.top();
	}
	if (!snotin.empty())
	{
		notin = snotin.top();
	}
}
int rob(TreeNode* root) {

	int in = 0, notin = 0;
	PostOrder(root, in,notin);
	int result = in > notin ? in : notin;
	return result;
}

int Test()
{
	{
		cout << "rob" << endl;
		TreeNode* root;
		
		root = new TreeNode(2);
		root->left = new TreeNode(1);
		root->right = new TreeNode(3);
		root->left->right = new TreeNode(4);
		cout << rob(root) << endl;

	}

	return 0;
}
//层
//int rob(TreeNode* root) {
//	vector<int> v;
//	queue<TreeNode*> q;
//	
//	q.push(root);
//	v.push_back(0);
//	v.push_back(0);
//	v.push_back(0);
//	while (!q.empty())
//	{
//		int val = 0;
//		int size = q.size();
//		for (int i = 0; i < size; i++)
//		{
//			TreeNode* node = q.front();
//			if (node != NULL)
//			{
//				val += node->val;
//				if (node->left != NULL)
//				{
//					q.push(node->left);
//				}
//				if (node->right != NULL)
//				{
//					q.push(node->right);
//				}
//			}
//			q.pop();
//		}
//		v.push_back(val);
//	}
//
//	vector<int> vresult;
//	vresult.push_back(0);
//	vresult.push_back(0);
//	vresult.push_back(0);
//	int result = 0;
//	for (int i = 3; i < v.size(); i++)
//	{
//		int r = (vresult[i - 2] >= vresult[i - 3] ? vresult[i - 2] : vresult[i - 3]) + v[i];
//		vresult.push_back(r);
//		result = r > result ? r : result;
//	}
//	return result;
//}