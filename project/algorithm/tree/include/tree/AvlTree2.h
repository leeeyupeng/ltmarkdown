//#include <iostream>
//#include <math.h>
//#include <stdlib.h>
//using namespace std;
////建立一个整数类型
//typedef struct obj_n_t
//{
//	int obj_key;
//} obj_node_t;
////建立树结点的基本机构
//typedef struct tree_n_t
//{
//	int key;
//	struct tree_n_t *left, *right;
//	int height;
//} tree_node_t;
////建立堆栈
//#define MAXSIZE 512
//tree_node_t *stack[MAXSIZE]; //warning!the tree can contain 256 leaves at most!
//int i = 0; //堆栈计数器
////堆栈清空
//void stack_clear()
//{
//	while (i != 0)
//	{
//		stack[i - 1] = NULL;
//		i--;
//	}
//}
////堆栈为空
//int stack_empty()
//{
//	return(i == 0);
//}
////入栈函数
//int push(tree_node_t *node)
//{
//	if (i < MAXSIZE)
//	{
//		stack[i++] = node;
//		return(0);
//	}
//	else
//		return(-1);
//}
////出栈函数
//tree_node_t *pop()
//{
//	if (i > 0)
//		return(stack[--i]);
//	else
//		return(0);
//}
////建立get_node函数，用于动态分配内存空间
//tree_node_t *get_node()
//{
//	tree_node_t *tmp;
//	tmp = (tree_node_t *)malloc(sizeof(tree_node_t));
//	return(tmp);
//}
////建立return_node函数，用于释放内存
//void return_node(tree_node_t *free_node)
//{
//	free(free_node);
//}
////建立左旋转函数
//void left_rotation(tree_node_t *node)
//{
//	tree_node_t *tmp;
//	int tmp_key;
//	tmp = node->left;
//	tmp_key = node->key;
//	node->left = node->right;
//	node->key = node->right->key;
//	node->right = node->left->right;
//	node->left->right = node->left->left;
//	node->left->left = tmp;
//	node->left->key = tmp_key;
//}
////建立右旋转函数
//void right_rotation(tree_node_t *node)
//{
//	tree_node_t *tmp;
//	int tmp_key;
//	tmp = node->right;
//	tmp_key = node->key;
//	node->right = node->left;
//	node->key = node->left->key;
//	node->left = node->right->left;
//	node->right->left = node->right->right;
//	node->right->right = tmp;
//	node->right->key = tmp_key;
//}
//int rebalance(tree_node_t *node)
//{
//	int finished = 0;
//	while (!stack_empty() && !finished)
//	{
//		int tmp_height, old_height;
//		node = pop(); //back to the root along the search path
//		old_height = node->height;
//		if (node->left->height - node->right->height == 2)
//		{
//			if (node->left->left->height - node->right->height == 1)
//			{
//				right_rotation(node);
//				node->right->height = node->right->left->height + 1;
//				node->height = node->right->height + 1;
//			}
//			else
//			{
//				left_rotation(node->left);
//				right_rotation(node);
//				tmp_height = node->left->left->height;
//				node->left->height = tmp_height + 1;
//				node->right->height = tmp_height + 1;
//				node->height = tmp_height + 2;
//			}
//		}
//		else if (node->left->height - node->right->height == -2)
//		{
//			if (node->right->right->height - node->left->height == 1)
//			{
//				left_rotation(node);
//				node->left->height = node->left->right->height + 1;
//				node->height = node->left->height + 1;
//			}
//			else
//			{
//				right_rotation(node->right);
//				left_rotation(node);
//				tmp_height = node->right->right->height;
//				node->left->height = tmp_height + 1;
//				node->right->height = tmp_height + 1;
//				node->height = tmp_height + 2;
//			}
//		}
//		else
//		{
//			if (node->left->height > node->right->height)
//				node->height = node->left->height + 1;
//			else
//				node->height = node->right->height + 1;
//		}
//		if (node->height == old_height)
//			finished = 1;
//	}
//	stack_clear();
//	return(0);
//}
////建立creat_tree函数，用于建立一颗空树
//tree_node_t *creat_tree()
//{
//	tree_node_t *root;
//	root = get_node();
//	root->left = root->right = NULL;
//	root->height = 0;
//	return(root); //build up an empty tree.the first insert bases on the empty tree.
//}
////建立find函数，用于查找一个对象
//obj_node_t *find(tree_node_t *tree, int query_key)
//{
//	tree_node_t *tmp;
//	if (tree->left == NULL)
//		return(NULL);
//	else
//	{
//		tmp = tree;
//		while (tmp->right != NULL)
//		{
//			if (query_key < tmp->key)
//				tmp = tmp->left;
//			else
//				tmp = tmp->right;
//		}
//		if (tmp->key == query_key)
//			return((obj_node_t*)tmp->left);
//		else
//			return(NULL);
//	}
//}
////建立插入函数
//int insert(tree_node_t *tree, obj_node_t *new_obj)
//{
//	tree_node_t *tmp = NULL;
//	int query_key, new_key;
//	query_key = new_key = new_obj->obj_key;
//	if (tree->left == NULL)
//	{
//		tree->left = (tree_node_t *)new_obj;
//		tree->key = new_key;
//		tree->height = 0;
//		tree->right = NULL;
//	}
//	else
//	{
//		stack_clear();
//		tmp = tree;
//		while (tmp->right != NULL)
//		{
//			//use stack to remember the path from root to the position at which the new object should be inserted.
//			//then after inserting,we can rebalance from the parrent node of the leaf which pointing to new object to the root node.
//			push(tmp);
//			if (query_key < tmp->key)
//				tmp = tmp->left;
//			else
//				tmp = tmp->right;
//		}
//		if (tmp->key == query_key)
//			return(-1);
//		else
//		{
//			tree_node_t *old_leaf, *new_leaf;
//			//It must allocate 2 node space in memory.
//			//One for the new one,another for the old one.
//			//the previous node becomes the parrent of the new node.
//			//when we delete a leaf,it will free two node memory spaces as well.
//			old_leaf = get_node();
//			old_leaf->left = tmp->left;
//			old_leaf->key = tmp->key;
//			old_leaf->right = NULL;
//			old_leaf->height = 0;
//			new_leaf = get_node();
//			new_leaf->left = (tree_node_t *)new_obj;
//			new_leaf->key = new_key;
//			new_leaf->right = NULL;
//			new_leaf->height = 0;
//			if (tmp->key < new_key)
//			{
//				tmp->left = old_leaf;
//				tmp->right = new_leaf;
//				tmp->key = new_key;
//			}
//			else
//			{
//				tmp->left = new_leaf;
//				tmp->right = old_leaf;
//			}
//			tmp->height = 1;
//		}
//	}
//	rebalance(tmp);
//	return(0);
//}
////建立删除函数
//int del(tree_node_t *tree, int key)
//{
//	tree_node_t *tmp=NULL, *upper =NULL, *other=NULL;
//	if (tree->left == NULL)
//		return(-1);
//	else if (tree->right == NULL)
//	{
//		if (tree->key == key)
//		{
//			tree->left = NULL;
//			return(0);
//		}
//		else
//			return(-1);
//	}
//	else
//	{
//		tmp = tree;
//		stack_clear();
//		while (tmp->right != NULL)
//		{
//			upper = tmp;
//			push(upper);
//			if (key < tmp->key)
//			{
//				tmp = upper->left;
//				other = upper->right;
//			}
//			else
//			{
//				tmp = upper->right;
//				other = upper->left;
//			}
//		}
//		if (tmp->key != key)
//			return(-1);
//		else
//		{
//			upper->key = other->key;
//			upper->left = other->left;
//			upper->right = other->right;
//			upper->height = upper->height - 1;
//			return_node(tmp);
//			return_node(other);
//			rebalance(pop());
//			//here must pop,then rebalance can run from the parrent of upper,because upper has become a leaf.
//			return(0);
//		}
//	}
//}
////建立测试遍历函数
//int travel(tree_node_t *tree)
//{
//	stack_clear();
//	if (tree->left == NULL)
//		push(tree);
//	else if (tree->left != NULL)
//	{
//		int m = 0;
//		push(tree);
//		while (i != m)
//		{
//			if (stack[m]->left != NULL && stack[m]->right != NULL)
//			{
//				push(stack[m]->left);
//				push(stack[m]->right);
//			}
//			m++;
//		}
//	}
//	return(0);
//}
////建立测试函数
//int test_structure(tree_node_t *tree)
//{
//	travel(tree);
//	int state = -1;
//	while (!stack_empty())
//	{
//		--i;
//		if (stack[i]->right == NULL && stack[i]->height == 0) //this statement is leaf,but also contains an empty tree
//			state = 0;
//		else if (stack[i]->left != NULL && stack[i]->right != NULL)
//		{
//			if (abs(stack[i]->height - stack[i]->height) <= 1)
//				state = 0;
//			else
//			{
//				state = -1;
//				stack_clear();
//			}
//		}
//	}
//	stack_clear();
//	return(state);
//}
////建立remove_tree函数
//int remove_tree(tree_node_t *tree)
//{
//	travel(tree);
//	if (stack_empty())
//		return(-1);
//	else
//	{
//		while (!stack_empty())
//		{
//			return_node(pop());
//		}
//		return(0);
//	}
//}
//void main2()
//{
//	tree_node_t *atree = NULL;
//	obj_node_t obj[256], *f; //MAXSIZE=n(number of leaf)+(n-1) number of node
//	int n, j = 0;
//	cout << "Now Let's start this program! There is no tree in memory.\n";
//	int item = 10;
//	while (item != 0)
//	{
//		cout << "\nRoot address = " << atree << "\n";
//		cout << "\n1.Create a tree\n";
//		cout << "\n2.Insert a int type object\n";
//		cout << "\n3.Test the structure of the tree\n";
//		cout << "\n4.Find a object\n";
//		cout << "\n5.Travel\n";
//		cout << "\n6.Delete a object\n";
//		cout << "\n7.Remove the Tree\n";
//		cout << "\n0.Exit\n";
//		cout << "\nPlease select:";
//		cin >> item;
//		cout << "\n\n\n";
//		switch (item)
//		{
//		case 1:
//		{
//			atree = creat_tree();
//			cout << "\nA new empty tree has been built up!\n";
//			break;
//		}
//		case 2:
//		{
//			if (atree != NULL)
//				while (n != 3458)
//				{
//					cout << "Please insert a new object.\nOnly one object every time(3458 is an end code) : ";
//					cin >> n;
//					if (n != 3458)
//					{
//						obj[j].obj_key = n;
//						if (insert(atree, &obj[j]) == 0)
//						{
//							j++;
//							cout << "Integer " << n << " has been input!\n\n";
//						}
//						else
//							cout << "\n\nInsert failed!\n\n";
//					}
//				}
//			else
//				cout << "\n\nNo tree in memory,insert Fail!\n\n";
//			break;
//		}
//		case 3:
//		{
//			if (atree != NULL)
//			{
//				//n = test_structure(atree);
//				//if (n == -1)
//				//	cout << "\n\nIt's not a correct AVL tree.\n\n";
//				//if (n == 0)
//				//	cout << "\n\nIt's a AVL tree\n\n";
//			}
//			else
//				cout << "\n\nNo tree in memory,Test Fail!\n\n";
//			break;
//		}
//		case 4:
//		{
//			if (atree != NULL)
//			{
//				cout << "\n\nWhat do you want to find? : ";
//				cin >> n;
//				f = find(atree, n);
//				if (f == NULL)
//				{
//					cout << "\n\nSorry," << n << " can't be found!\n\n";
//				}
//				else
//				{
//					cout << "\n\nObject " << f->obj_key << " has been found!\n\n";
//				}
//			}
//			else
//				cout << "\n\nNo tree in memory,Find Fail!\n\n";
//			break;
//		}
//		case 5:
//		{
//			if (atree != NULL)
//			{
//				travel(atree);
//				for (int count = 0; count < i; count++)
//				{
//					cout << " " << stack[count]->key << ",";
//				}
//			}
//			else
//				cout << "\n\nNo tree in memory,Travel Fail!\n\n";
//			break;
//		}
//		case 6:
//		{
//			if (atree != NULL)
//			{
//				cout << "\n\nWhich object do you want to delete?\n\n";
//				cin >> n;
//				if (del(atree, n) == 0)
//				{
//					cout << "\n\n" << n << " has been deleted!\n\n";
//				}
//				else
//					cout << "\n\nNo this object\n\n";
//			}
//			else
//				cout << "\n\nNo tree in memory,Delete Fail!\n\n";
//			break;
//		}
//		case 7:
//		{
//			if (atree != NULL)
//			{
//				remove_tree(atree);
//				cout << "\n\nThe Tree has been removed!\n\n";
//				atree = NULL;
//			}
//			else
//				cout << "\n\nNo tree in memory,Removing Fail!\n\n";
//		}
//		default:
//			cout << "\n\nNo this operation!\n\n";
//		}
//		n = 0;
//	}
//}