#pragma once
#include <iostream>
#include <stack>
#include <queue>
#include "TreeNode.h"
using namespace tree;
using namespace std;
//前序遍历
template<typename T>
void PreOrder(TreeNode<T>* root,vector<T>& v)
{

}
template<typename T>
void _PreOrder(TreeNode<T>* node,vector<T>& v)
{
	if (node == NULL)
	{
		return;
	}
	v.push_back(node->value);
	_PreOrder(node->left,v);
	_PreOrder(node->right, v);
}
template<typename T>
void _PreOrderWithStack(TreeNode<T>* root,vector<T>& v)
{
	stack<TreeNode<T>*> s;
	s.push(root);
	while (!s.empty())
	{
		TreeNode<T>* top = s.top();
		s.pop();
		if (top == NULL)
		{
			continue;
		}
		v.push_back(top->value);
		s.push(top->right);
		s.push(top->left);
	}
}
//中序遍历
template<typename T>
void InOrder(TreeNode<T>* root,vector<T>& v)
{

}
template<typename T>
void _InOrder(TreeNode<T>* node,vector<T>& v)
{
	if (node == NULL)
	{
		return;
	}
	_InOrder(node->left, v);
	v.push_back(node->value);
	_InOrder(node->right, v);
}
template<typename T>
void _InOrderWithStack(TreeNode<T>* root, vector<T>& v)
{
	stack<TreeNode<T>*> s;
	TreeNode<T>* cur = root;

	while (cur != NULL || !s.empty())
	{
		while (cur != NULL)
		{
			s.push(cur);
			cur = cur->left;
		}

		TreeNode<T>* top = s.top();
		v.push_back(top->value);
		s.pop();
		cur = top->right;
	}
}
//后序遍历
template<typename T>
void PostOrder(TreeNode<T>* root)
{

}
template<typename T>
void _PostOrder(TreeNode<T>* node, vector<T>& v)
{
	if (node == NULL)
	{
		return;
	}
	
	_PostOrder(node->left, v);
	_PostOrder(node->right, v);
	v.push_back(node->value);
}
template<typename T>
void _PostOrderWithStack(TreeNode<T>* root, vector<T>& v)
{
	stack<TreeNode<T>*> s;
	TreeNode<T>* cur = root;
	TreeNode<T>* pre = NULL;
	while (cur != NULL || !s.empty())
	{
		while (cur != NULL)
		{
			s.push(cur);
			cur = cur->left;
		}

		TreeNode<T>* top = s.top();
		if (top->right == NULL)
		{
			v.push_back(top->value);
			pre = top;
			s.pop();			
		}
		else if(pre == top->right)
		{
			v.push_back(top->value);
			pre = top;
			s.pop();
		}
		else
		{
			cur = top->right;
		}
	}
}
//层序遍历
template<typename T>
void LevelOrder(TreeNode<T>* root,vector<T> & v)
{
	queue<TreeNode<T>*> q;
	q.push(root);
	while(!q.empty())
	{ 
		TreeNode<T>* front = q.front();
		q.pop();
		if (front == NULL)
		{
			continue;
		}
		v.push_back(front->value);
		q.push(front->left);
		q.push(front->right);
	}
}

template<typename T>
void LevelBuildTree(TreeNode<T>*& root,queue<T> v)
{
	queue<TreeNode<T>*> tq;
	//tq.push(root);

	while (!v.empty())
	{
		if (tq.empty())
		{
			TreeNode<T>* node;
			T e = v.front();
			v.pop();
			node = new TreeNode<T>(e);
			tq.push(node);

			root = node;
		}
		else
		{
			TreeNode<T>* parent = tq.front();
			tq.pop();

			TreeNode<T>* node;
			if (!v.empty()) 
			{
				T e = v.front();
				v.pop();
				node = new TreeNode<T>(e);
				tq.push(node);
				parent->left = node;
			}

			if (!v.empty())
			{
				T e = v.front();
				v.pop();
				node = new TreeNode<T>(e);
				tq.push(node);
				parent->right = node;
			}

		}

	}
}


