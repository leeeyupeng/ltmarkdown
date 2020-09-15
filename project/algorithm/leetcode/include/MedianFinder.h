#pragma once
#include <iostream>
#include <random>
#include <vector>
#include<algorithm>
#include "../../tree/include/Heap.h"
using namespace std;
using namespace tree;

//https://leetcode-cn.com/problems/find-median-from-data-stream

//class MedianFinder {
//private:
//	HeapMax<int> m_left;
//	HeapMin<int> m_right;
//public:
//	/** initialize your data structure here. */
//	MedianFinder() {
//
//	}
//
//	void addNum(int num) {
//		if (m_left.Top() > num)
//		{
//			m_left.Push(num);
//		}
//		else if(m_right.Top() < num)
//		{
//			m_right.Push(num);
//		}
//		else
//		{
//			if (m_right.Size() > m_left.Size())
//			{
//				m_left.Push(num);
//			}
//			else
//			{
//				m_right.Push(num);
//			}
//		}
//		while (m_right.Size() > m_left.Size())
//		{
//			m_left.Push(m_right.Top());
//			m_right.Pop();
//		}
//		while (m_left.Size() > m_right.Size() + 1)
//		{
//			m_right.Push(m_left.Top());
//			m_left.Pop();
//		}
//	}
//
//	double findMedian() {
//		if (m_right.Size() == m_left.Size())
//		{
//			return (m_left.Top() + m_right.Top()) * 0.5f;
//		}
//		else
//		{
//			return m_left.Top();
//		}
//	}
//};

bool compare1(int a, int b)
{
	return a > b;
}
bool compare2(int a, int b)
{
	return a < b;
}
class MedianFinder {
private:
	Heap<int> m_left;
	Heap<int> m_right;
public:
	/** initialize your data structure here. */
	MedianFinder():m_left(compare1),m_right(compare2) {

	}

	void addNum(int num) {
		if (m_left.Top() > num)
		{
			m_left.Push(num);
		}
		else if (m_right.Top() < num)
		{
			m_right.Push(num);
		}
		else
		{
			if (m_right.Size() > m_left.Size())
			{
				m_left.Push(num);
			}
			else
			{
				m_right.Push(num);
			}
		}
		while (m_right.Size() > m_left.Size())
		{
			m_left.Push(m_right.Top());
			m_right.Pop();
		}
		while (m_left.Size() > m_right.Size() + 1)
		{
			m_right.Push(m_left.Top());
			m_left.Pop();
		}
	}

	double findMedian() {
		if (m_right.Size() == m_left.Size())
		{
			return (m_left.Top() + m_right.Top()) * 0.5f;
		}
		else
		{
			return m_left.Top();
		}
	}
};
