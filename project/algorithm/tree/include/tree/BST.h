#pragma once
#include "TreeNode.h"

#include <vector>
#include <iostream>
using namespace std;
namespace tree
{
	template<typename T>
	class BST
	{
	private:
		TreeNode<T>* m_root =NULL;
	public:
		void Insert(T element);
		void Remove(T element);
		bool Contain(T element);
		//TreeNode<T>* Find(T element);
		void Clear();
		vector<T> GetVector();		

	private:
		void _middle_order(vector<T>& v, TreeNode<T> *node);
		void _Remove1(TreeNode<T>* node, TreeNode<T>* parent);
		void _Remove2(TreeNode<T>* node, TreeNode<T>* parent);
		void _Clear(TreeNode<T>* node);
	};

	template<typename T>
	void BST<T>::Insert(T element)
	{
		TreeNode<T>* node = new TreeNode<T>(element);
		if (m_root == NULL)
		{
			m_root = node;
		}
		else
		{
			TreeNode<T>* s = m_root;
			while (s != NULL)
			{
				if (node->value > s->value)
				{
					if (s->right == NULL)
					{
						s->right = node;
						break;
					}
					else
					{
						s = s->right;
						continue;
					}
				}
				else if(node->value < s->value)
				{
					if (s->left == NULL)
					{
						s->left = node;
						break;
					}
					else
					{
						s = s->left;
						continue;
					}
				}
				else
				{
					cout << "重复元素" << endl;
					break;
				}
			}
		}
	}
	template<typename T>
	void BST<T>::Remove(T element)
	{
		TreeNode<T>* s = m_root;
		TreeNode<T>* parent = NULL;
		while (s != NULL)
		{
			if (element == s->value)
			{
				break;
			}
			else if (element > s->value)
			{
				parent = s;
				s = s->right;
			}
			else
			{
				parent = s;
				s = s->left;
			}
		}

		if (s != NULL)
		{
			_Remove2(s,parent);
			delete s;
		}
		else
		{
			cout << "元素不存在" << endl;
		}
	}
	template<typename T>
	bool BST<T>::Contain(T element)
	{
		TreeNode<T>* s = m_root;
		while (s != NULL)
		{
			if (element == s->value)
			{
				break;
			}
			else if (element > s->value)
			{
				s = s->right;
			}
			else
			{
				s = s->left;
			}

		}
		if (s != NULL && s->value == element)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	//template<typename T>
	//TreeNode<T>* BST<T>::Find(T element)
	//{
	//	TreeNode<T>* s = m_root;
	//	while (s != NULL)
	//	{
	//		if (element == s->value)
	//		{
	//			break;
	//		}
	//		else if (element > s->value)
	//		{
	//			s = s->right;
	//		}
	//		else
	//		{
	//			s = s->left;
	//		}
	//		
	//	}
	//	if (s != NULL && s->value == element)
	//	{
	//		return s;
	//	}
	//	else
	//	{
	//		return NULL;
	//	}
	//}
	template<typename T>
	void BST<T>::Clear()
	{
		_Clear(m_root);
	}
	template<typename T>
	void BST<T>::_Clear(TreeNode<T> *node)
	{
		if (node != NULL)
		{
			_Clear(node->left);
			_Clear(node->right);

			delete node;
			node = NULL;
		}
	}
	template<typename T>
	vector<T> BST<T>::GetVector()
	{
		vector<T> v;
		_middle_order(v,m_root);
		return v;
	}
	template<typename T>
	void BST<T>::_middle_order(vector<T>& v,TreeNode<T> *node) {
		if (node != NULL) {
			_middle_order(v,node->left);
			v.push_back(node->value);
			_middle_order(v,node->right);
		}
	}

	template<typename T>
	void BST<T>::_Remove1(TreeNode<T>* node, TreeNode<T>* parent)
	{
		if (node->left == NULL && node->right == NULL)
		{
			if (parent == NULL)
			{
				m_root = NULL;
			}
			else if (parent->left == node)
			{
				parent->left = NULL;
			}
			else if (parent->right == node)
			{
				parent->right = NULL;
			}
		}
		else if (node->left == NULL || node->right == NULL)
		{
			if (parent == NULL)
			{
				m_root = node->right == NULL ? node->left : node->right;
			}
			else if (parent->left == node)
			{
				parent->left = node->right == NULL ? node->left : node->right;
			}
			else if (parent->right == node)
			{
				parent->right = node->right == NULL ? node->left : node->right;
			}
		}
		else
		{
			if (parent == NULL)
			{
				m_root = node->left;

				TreeNode<T>* r = node->left;
				while (r->right != NULL)
				{
					r = r->right;
				}
				r->right = node->right;
			}
			else if (parent->left == node)
			{
				parent->left = node->left;

				TreeNode<T>* r = node->left;
				while (r->right != NULL)
				{
					r = r->right;
				}
				r->right = node->right;
			}
			else if (parent->right == node)
			{
				parent->right = node->right;

				TreeNode<T>* l = node->right;
				while (l->left != NULL)
				{
					l = l->left;
				}
				l->left = node->left;
			}
		}
	}
	template<typename T>
	void BST<T>::_Remove2(TreeNode<T>* node, TreeNode<T>* parent)
	{
		if (node->left == NULL && node->right == NULL)
		{
			if (parent == NULL)
			{
				m_root = NULL;
			}
			else if (parent->left == node)
			{
				parent->left = NULL;
			}
			else if (parent->right == node)
			{
				parent->right = NULL;
			}
		}
		else if (node->left == NULL || node->right == NULL)
		{
			if (parent == NULL)
			{
				m_root = node->right == NULL ? node->left : node->right;
			}
			else if (parent->left == node)
			{
				parent->left = node->right == NULL ? node->left : node->right;
			}
			else if (parent->right == node)
			{
				parent->right = node->right == NULL ? node->left : node->right;
			}
		}
		else
		{
			if (parent == NULL)
			{
				TreeNode<T>* rp = node;
				TreeNode<T>* r = node->left;
				while (r->right != NULL)
				{
					rp = r;
					r = r->right;
				}
				m_root = r;
				r->right = node->right;
				rp->right = r->left;
				if (r != node->left)
				{
					r->left = node->left;
				}
			}
			else if (parent->left == node)
			{
				TreeNode<T>* rp = node;
				TreeNode<T>* r = node->left;
				while (r->right != NULL)
				{
					rp = r;
					r = r->right;
				}
				parent->left = r;
				r->right = node->right;
				rp->right = r->left;
				if (r != node->left)
				{
					r->left = node->left;
				}

			}
			else if (parent->right == node)
			{
				TreeNode<T>* lp = node;
				TreeNode<T>* l = node->right;
				while (l->left != NULL)
				{
					lp = l;
					l = l->left;
				}
				parent->right = l; 
				l->left = node->left;
				lp->left = l->right;
				if (l != node->right)
				{
					l->right = node->right;
				}

				//TreeNode<T>* rp = node;
				//TreeNode<T>* r = node->left;
				//while (r->right != NULL)
				//{
				//	rp = r;
				//	r = r->right;
				//}
				//parent->right = r;
				//r->right = node->right;
				//rp->right = r->left;
				//if (r != node->left)
				//{
				//	r->left = node->left;
				//}
			}
		}
	}
}