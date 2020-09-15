#pragma once
namespace tree
{
	template<typename T>
	struct  TreeNode
	{
		T value;
		TreeNode<T>* left=NULL;
		TreeNode<T>* right=NULL;

		TreeNode(T v)
		{
			value = v;
		}
	};
}