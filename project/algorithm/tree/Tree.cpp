//// Tree.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
////
//
//#include <iostream>
//#include <random>
//#include <vector>
//#include<algorithm>
//#include "tree/TreeNode.h"
//#include "tree/BST.h"
//#include "tree/AVLTree.h"
//#include "tree/Heap.h"
//#include "tree/AvlTree2.h"
//#include "tree/Traversal.h"
//using namespace std;
//using namespace tree;
//
//bool compare1(unsigned int a, unsigned int b) 
//{
//	return a > b; 
//}
//
//
//bool compare2(unsigned int a, unsigned int b)
//{
//	return a < b;
//}
//int main()
//{
//	//{
//	//	cout << "BST start" << endl;
//	//	BST<int> m_bst;
//
//	//	vector<int> vv; 
//	//	vector<int> del;
//	//	for (int i = 0; i < 10000000; i++)
//	//	{
//	//		int v = rand();
//	//		if (m_bst.Find(v) == NULL)
//	//		{
//	//			m_bst.Insert(v);
//
//	//			if (i % 2 == 0)
//	//			{
//	//				del.push_back(v);
//	//			}
//	//			else
//	//			{
//	//				vv.push_back(v);
//	//			}
//
//	//			//cout << "i:" << i << "value:" << v << endl;
//	//		}
//	//	}
//	//	{
//	//		vector<int> v = m_bst.GetVector();
//	//		//for (int i = 0; i < v.size(); i++)
//	//		//{
//	//		//	cout << "i:" << i << "value:" << v[i] << endl;
//	//		//}
//	//	}
//	//	for (int i = 0; i < del.size(); i++)
//	//	{
//	//		m_bst.Remove(del[i]);
//	//	}
//	//	sort(del.begin(),del.end());
//	//	//for (int i = 0; i < del.size(); i++)
//	//	//{
//	//	//	cout << "del i:" << i << "value:" << del[i] << endl;
//	//	//}
//	//	{
//	//		vector<int> v = m_bst.GetVector();
//	//		//for (int i = 0; i < v.size(); i++)
//	//		//{
//	//		//	cout << "i:" << i << "value:" << v[i] << endl;
//	//		//}
//	//	}
//	//	{
//	//		sort(vv.begin(), vv.end());
//	//		vector<int> v = m_bst.GetVector();
//	//		for (int i = 0; i < v.size(); i++)
//	//		{
//	//			if (v[i] != vv[i])
//	//			{
//	//				cout << "error eeeeeeeeeeee" << endl;
//	//			}
//	//		}
//	//		cout << "成功" << endl;
//	//	}
//
//	//	m_bst.Clear();
//	//	cout << "BST end" << endl;
//
//	//}
//
//	//{
//	//	cout << "AVLTree Start" << endl;
//	//	AVLTree<int> avltree;
//	//	avltree.Insert(10);
//	//	avltree.Insert(1);
//	//	avltree.Insert(100);
//	//	{
//	//		vector<int> v = avltree.Sort();
//	//		for (int i = 0; i < v.size(); i++)
//	//		{
//	//			cout << "i:" << i << "value:" << v[i] << endl;
//	//		}
//	//	}
//	//	cout << "AVLTree End" << endl;
//	//}
//
//	//{
//	//	cout << "HeapMax Start" << endl;
//	//	HeapMax<unsigned int> heap;
//	//	vector<unsigned int> v;
//	//	for (int i = 0; i < 500000; i++)
//	//	{
//	//		v.push_back(rand());
//	//	}
// // 		heap.Heapify(v);
//	//	vector<unsigned int> s = heap.Sort();
//	//	sort(v.begin(),v.end());
//	//	for (int i = 0; i < v.size(); i++)
//	//	{
//	//		if (v[i] != s[v.size() - 1 - i])
//	//		{
//	//			cout << "Error" << endl; 
//	//			break;
//	//		}
//	//	}
//	//	cout << "Success" << endl;
//	//	cout << endl;
//	//	cout << "HeapMax End" << endl;
//	//}
//
//	/*{
//		cout << "HeapMin Start" << endl;
//		HeapMin<unsigned int> heap;
//		vector<unsigned int> v;
//		for (int i = 0; i < 500000; i++)
//		{
//			v.push_back(rand());
//		}
//		heap.Heapify(v);
//		vector<unsigned int> s = heap.Sort();
//		sort(v.begin(), v.end());
//		for (int i = 0; i < v.size(); i++)
//		{
//			if (v[i] != s[i])
//			{
//				cout << "Error" << endl;
//				break;
//			}
//		}
//		cout << "Success" << endl;
//		cout << endl;
//		cout << "HeapMin End" << endl;
//	}*/
//
//	//{
//	//	cout << "Heap Start" << endl;
//	//	Heap<unsigned int> heap(compare1);
//	//	vector<unsigned int> v;
//	//	for (int i = 0; i < 500000; i++)
//	//	{
//	//		v.push_back(rand());
//	//	}
//	//	heap.Heapify(v);
//	//	vector<unsigned int> s = heap.Sort();
//	//	sort(v.begin(), v.end());
//	//	for (int i = 0; i < v.size(); i++)
//	//	{
//	//		if (v[i] != s[v.size() - 1 - i])
//	//		{
//	//			cout << "Error" << endl;
//	//			break;
//	//		}
//	//	}
//	//	cout << "Success" << endl;
//	//	cout << endl;
//	//	cout << "Heap End" << endl;
//	//}
//
//	//{
//	//	cout << "Heap Start" << endl;
//	//	Heap<unsigned int> heap(compare2);
//	//	vector<unsigned int> v;
//	//	for (int i = 0; i < 500000; i++)
//	//	{
//	//		v.push_back(rand());
//	//	}
//	//	heap.Heapify(v);
//	//	vector<unsigned int> s = heap.Sort();
//	//	sort(v.begin(), v.end());
//	//	for (int i = 0; i < v.size(); i++)
//	//	{
//	//		if (v[i] != s[i])
//	//		{
//	//			cout << "Error" << endl;
//	//			break;
//	//		}
//	//	}
//	//	cout << "Success" << endl;
//	//	cout << endl;
//	//	cout << "Heap End" << endl;
//	//}
//
//	//{
//	//	cout << "AVLTREE2" << endl;
//	//	main2();
//	//}
//
//	{
//		cout << "Traversal" << endl;
//		queue<int> q;
//		for (int i = 0; i < 1000; i++)
//		{
//			q.push(rand()%100);
//			cout << q.back() << ";";
//		}
//		cout << endl;
//
//		queue<int> qq = q;
//
//		TreeNode<int>* root=NULL;
//		LevelBuildTree(root,q);
//		//vector<int> v;
//		//LevelOrder(root, v);
//		//for (int i = 0; i < qq.size(); i++)
//		//{
//		//	if (qq.front() != v[i])
//		//	{
//		//		cout << "ERROR" << endl;
//		//	}
//		//	qq.pop();
//		//}
//		vector<int> v1;
//		_PostOrder(root,v1);
//		vector<int> v2;
//		_PostOrderWithStack(root, v2);
//		if (v1.size() != v2.size())
//		{
//			cout << "Error" << endl;
//		}
//		for (int i = 0; i < v1.size(); i++)
//		{
//			if (v1[i] != v2[i])
//			{
//				cout << "Error" << endl;
//			}
//			cout << v1[i] << ";";
//		}
//		cout << endl;
//	}
//
//}
//
//// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
//// 调试程序: F5 或调试 >“开始调试”菜单
//
//// 入门使用技巧: 
////   1. 使用解决方案资源管理器窗口添加/管理文件
////   2. 使用团队资源管理器窗口连接到源代码管理
////   3. 使用输出窗口查看生成输出和其他消息
////   4. 使用错误列表窗口查看错误
////   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
////   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
