#pragma once
#include "TreeNode.h"
#include <vector>
using namespace tree;
using namespace std;
namespace tree
{
	template<typename T>
	class AVLTree
	{
		template<typename T>
		struct  AVLTreeNode
		{
			T value;
			AVLTreeNode<T>* left = NULL;
			AVLTreeNode<T>* right = NULL;
			int height;

			AVLTreeNode(T e, int h) :value(e), height(h)
			{

			}
		};
	private:
		AVLTreeNode<T>* m_root = NULL;
	public:
		void Insert(T element);
		void Remove(T element);
		bool Contain(T element);
		void Clear();
		//AVLTreeNode<T>* Find(T element);
		vector<T> Sort();

	private:
		void _ReBalance(AVLTreeNode<T>** node);
		void _LL(AVLTreeNode<T>** node);
		void _RR(AVLTreeNode<T>** node);
		void _LR(AVLTreeNode<T>** node);
		void _RL(AVLTreeNode<T>** node);
		void _LRotation(AVLTreeNode<T>** node);
		void _RRotation(AVLTreeNode<T>** node);
		void middle_order(vector<T>& v, AVLTreeNode<T> *node);
		void _Insert(AVLTreeNode<T>** node, T element);
	};

	template<typename T>
	void AVLTree<T>::Insert(T element)
	{
		_Insert(&m_root, element);
	}

	template<typename T>
	void AVLTree<T>::_Insert(AVLTreeNode<T>** node,T element)
	{
		if (*node == NULL)
		{
			*node = new AVLTreeNode<T>(element,0);
			_ReBalance(node);
		}
		else if ((*node)->value > element)
		{
			_Insert(&((*node)->left),element);
			_ReBalance(node);
		}
		else if ((*node)->value < element)
		{
			_Insert(&((*node)->right), element);
			_ReBalance(node);
		}
		else
		{
			cout << "ÖØ¸´ÔªËØ" << endl;
			return;
		}
	}
	template<typename T>
	void AVLTree<T>::Remove(T element)
	{
	}
	template<typename T>
	bool AVLTree<T>::Contain(T element)
	{
	}

	//template<typename T>
	//AVLTreeNode<T>* AVLTree<T>::Find(T element)
	//{
	//}
	template<typename T>
	void AVLTree<T>::Clear()
	{
	}
	template<typename T>
	void AVLTree<T>::_ReBalance(AVLTreeNode<T>** node)
	{
		//if()
	}
	template<typename T>
	void AVLTree<T>::_LL(AVLTreeNode<T>** node)
	{

	}
	template<typename T>
	void AVLTree<T>::_RR(AVLTreeNode<T>** node)
	{
	}
	template<typename T>
	void AVLTree<T>::_LR(AVLTreeNode<T>** node)
	{

	}
	template<typename T>
	void AVLTree<T>::_RL(AVLTreeNode<T>** node)
	{
	}
	template<typename T>
	void AVLTree<T>::_LRotation(AVLTreeNode<T>** node)
	{
	}
	template<typename T>
	void AVLTree<T>::_RRotation(AVLTreeNode<T>** node)
	{
	}
	template<typename T>
	vector<T> AVLTree<T>::Sort()
	{
		vector<T> v;
		middle_order(v, m_root);
		return v;
	}
	template<typename T>
	void AVLTree<T>::middle_order(vector<T>& v, AVLTreeNode<T> *node) {
		if (node != NULL) {
			middle_order(v, static_cast<AVLTreeNode<T>*>(node->left));
			v.push_back(node->value);
			middle_order(v, static_cast<AVLTreeNode<T>*>(node->right));
		}
	}
}