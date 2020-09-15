#pragma once
#include "TreeNode.h"

#include <vector>
#include <iostream>
using namespace std;
namespace tree
{
	template<typename T>
	class HeapMax
	{
	private:
		vector<T> m_vector;
		void _Swap(int index1, int index2)
		{
			T temp = m_vector[index1];
			m_vector[index1] = m_vector[index2];
			m_vector[index2] = temp;
		}
		void _Adapt(int index)
		{
			_Adapt2(index);
		}
		void _Adapt1(int index)
		{
			int indexchild;
			int indexchildleft;
			int indexchildright;
			int notleaf = m_vector.size() / 2 - 1;
			while (index <= notleaf)
			{
				indexchildleft = index * 2 + 1;
				indexchildright = index * 2 + 2;
				if (indexchildright < m_vector.size())
				{
					if (m_vector[indexchildleft] > m_vector[indexchildright])
					{
						indexchild = indexchildleft;
					}
					else
					{
						indexchild = indexchildright;
					}
					if (m_vector[index] < m_vector[indexchild])
					{
						_Swap(index, indexchild);
						index = indexchild;
					}
					else
					{
						break;
					}
				}
				else if (indexchildleft < m_vector.size())
				{
					indexchild = indexchildleft;
					if (m_vector[index] < m_vector[indexchild])
					{
						_Swap(index, indexchild);
						index = indexchild;

						break;
					}
					else
					{
						break;
					}
				}
				else
				{
					cout << "Error" << endl;
				}
			}
		}
		void _Adapt2(int index)
		{
			int indexchild;
			int indexchildleft = index * 2 + 1;
			int indexchildright = index * 2 + 2;
			if (indexchildright < m_vector.size())
			{
				if (m_vector[indexchildleft] > m_vector[indexchildright])
				{
					indexchild = indexchildleft;
				}
				else
				{
					indexchild = indexchildright;
				}
				if (m_vector[index] < m_vector[indexchild])
				{
					_Swap(index, indexchild);
					_Adapt2(indexchild);
				}
			}
			else if (indexchildleft < m_vector.size())
			{
				indexchild = indexchildleft;
				if (m_vector[index] < m_vector[indexchild])
				{
					_Swap(index, indexchild);
					_Adapt2(indexchild);
				}
			}
		}
		void _Heapify1(const vector<T>& v)
		{
			m_vector = v;

			int index = 0;
			int indexchild;
			int indexchildleft;
			int indexchildright;
			int notleaf = m_vector.size() / 2 - 1;
			for (int i = notleaf; i >= 0; i--)
			{
				_Adapt(i);
			}
		}
		void _Heapify2(const vector<T>& v)
		{
			for (int i = 0; i < v.size(); i++)
			{
				Push(v[i]);
			}
		}
	public:
		void Heapify(const vector<T>& v)
		{
			_Heapify1(v);
		}
		void Push(T c)
		{
			m_vector.push_back(c);
			int index = m_vector.size() - 1;
			int indexparent;
			while (index > 0)
			{
				indexparent = (index - 1) / 2;
				if (m_vector[indexparent] < m_vector[index])
				{
					_Swap(index, indexparent);
				}
				index = indexparent;
			}
		}
		void Pop()
		{
			if (Empty())
			{
				return;
			}
			m_vector[0] = m_vector.back();
			m_vector.pop_back();
			
			_Adapt(0);
		}
		T Top()
		{
			if (Empty())
			{
				return NULL;
			}
			return m_vector[0];
		}

		int Size()
		{
			return m_vector.size();
		}
		bool Empty()
		{
			return m_vector.empty();
		}

		vector<T> Sort()
		{
			vector<T> v;
			while (!Empty())
			{
				v.push_back(Top());
				Pop();
			}
			return v;
		}
	};

	template<typename T>
	class HeapMin
	{
	private:
		vector<T> m_vector;
		void _Swap(int index1, int index2)
		{
			T temp = m_vector[index1];
			m_vector[index1] = m_vector[index2];
			m_vector[index2] = temp;
		}

		void _Adapt(int index)
		{
			_Adapt2(index);
		}
		void _Adapt1(int index)
		{
			int indexchild;
			int indexchildleft;
			int indexchildright;
			int notleaf = m_vector.size() / 2 - 1;
			while (index <= notleaf)
			{
				indexchildleft = index * 2 + 1;
				indexchildright = index * 2 + 2;
				if (indexchildright < m_vector.size())
				{
					if (m_vector[indexchildleft] < m_vector[indexchildright])
					{
						indexchild = indexchildleft;
					}
					else
					{
						indexchild = indexchildright;
					}
					if (m_vector[index] > m_vector[indexchild])
					{
						_Swap(index, indexchild);
						index = indexchild;
					}
					else
					{
						break;
					}
				}
				else if (indexchildleft < m_vector.size())
				{
					indexchild = indexchildleft;
					if (m_vector[index] > m_vector[indexchild])
					{
						_Swap(index, indexchild);
						index = indexchild;

						break;
					}
					else
					{
						break;
					}
				}
				else
				{
					cout << "Error" << endl;
				}
			}
		}
		void _Adapt2(int index)
		{
			int indexchild;
			int indexchildleft = index * 2 + 1;
			int indexchildright = index * 2 + 2;
			if (indexchildright < m_vector.size())
			{
				if (m_vector[indexchildleft] < m_vector[indexchildright])
				{
					indexchild = indexchildleft;
				}
				else
				{
					indexchild = indexchildright;
				}
				if (m_vector[index] > m_vector[indexchild])
				{
					_Swap(index, indexchild);
					_Adapt2(indexchild);
				}
			}
			else if (indexchildleft < m_vector.size())
			{
				indexchild = indexchildleft;
				if (m_vector[index] > m_vector[indexchild])
				{
					_Swap(index, indexchild);
					_Adapt2(indexchild);
				}
			}
		}
		void _Heapify1(const vector<T>& v)
		{
			m_vector = v;

			int index = 0;
			int notleaf = m_vector.size() / 2 - 1;
			for (int i = notleaf; i >= 0; i--)
			{
				_Adapt(i);
			}
		}
		void _Heapify2(const vector<T>& v)
		{
			for (int i = 0; i < v.size(); i++)
			{
				Push(v[i]);
			}
		}
	public:
		void Heapify(const vector<T>& v)
		{
			_Heapify1(v);
		}
		void Push(T c)
		{
			m_vector.push_back(c);
			int index = m_vector.size() - 1;
			int indexparent;
			while (index > 0)
			{
				indexparent = (index - 1) / 2;
				if (m_vector[indexparent] > m_vector[index])
				{
					_Swap(index, indexparent);
				}
				index = indexparent;
			}
		}
		void Pop()
		{
			if (Empty())
			{
				return;
			}
			m_vector[0] = m_vector.back();
			m_vector.pop_back();

			_Adapt(0);
		}
		T Top()
		{
			if (Empty())
			{
				return NULL;
			}
			return m_vector[0];
		}

		int Size()
		{
			return m_vector.size();
		}
		bool Empty()
		{
			return m_vector.empty();
		}

		vector<T> Sort()
		{
			vector<T> v;
			while (!Empty())
			{
				v.push_back(Top());
				Pop();
			}
			return v;
		}
	};


	template<typename T>
	class Heap
	{
	private:
		vector<T> m_vector;

		bool(*compare)(T a, T b);
		void _Swap(int index1, int index2)
		{
			T temp = m_vector[index1];
			m_vector[index1] = m_vector[index2];
			m_vector[index2] = temp;
		}

		void _Adapt(int index)
		{
			_Adapt2(index);
		}
		void _Adapt1(int index)
		{
			int indexchild;
			int indexchildleft;
			int indexchildright;
			int notleaf = m_vector.size() / 2 - 1;
			while (index <= notleaf)
			{
				indexchildleft = index * 2 + 1;
				indexchildright = index * 2 + 2;
				if (indexchildright < m_vector.size())
				{
					if (compare(m_vector[indexchildleft], m_vector[indexchildright]))
					{
						indexchild = indexchildleft;
					}
					else
					{
						indexchild = indexchildright;
					}
					if (!compare(m_vector[index] , m_vector[indexchild]))
					{
						_Swap(index, indexchild);
						index = indexchild;
					}
					else
					{
						break;
					}
				}
				else if (indexchildleft < m_vector.size())
				{
					indexchild = indexchildleft;
					if (!compare(m_vector[index], m_vector[indexchild]))
					{
						_Swap(index, indexchild);
						index = indexchild;

						break;
					}
					else
					{
						break;
					}
				}
				else
				{
					cout << "Error" << endl;
				}
			}
		}
		void _Adapt2(int index)
		{
			int indexchild;
			int indexchildleft = index * 2 + 1;
			int indexchildright = index * 2 + 2;
			if (indexchildright < m_vector.size())
			{
				if (compare(m_vector[indexchildleft] , m_vector[indexchildright]))
				{
					indexchild = indexchildleft;
				}
				else
				{
					indexchild = indexchildright;
				}
				if (!compare(m_vector[index], m_vector[indexchild]))
				{
					_Swap(index, indexchild);
					_Adapt2(indexchild);
				}
			}
			else if (indexchildleft < m_vector.size())
			{
				indexchild = indexchildleft;
				if (!compare(m_vector[index], m_vector[indexchild]))
				{
					_Swap(index, indexchild);
					_Adapt2(indexchild);
				}
			}
		}
		void _Heapify1(const vector<T>& v)
		{
			m_vector = v;

			int index = 0;
			int notleaf = m_vector.size() / 2 - 1;
			for (int i = notleaf; i >= 0; i--)
			{
				_Adapt(i);
			}
		}
		void _Heapify2(const vector<T>& v)
		{
			for (int i = 0; i < v.size(); i++)
			{
				Push(v[i]);
			}
		}
	public:
		Heap(bool(*c)(T a, T b)):compare(c)
		{
		}
		void Heapify(const vector<T>& v)
		{
			_Heapify1(v);
		}
		void Push(T c)
		{
			m_vector.push_back(c);
			int index = m_vector.size() - 1;
			int indexparent;
			while (index > 0)
			{
				indexparent = (index - 1) / 2;
				if (!compare(m_vector[indexparent] , m_vector[index]))
				{
					_Swap(index, indexparent);
				}
				index = indexparent;
			}
		}
		void Pop()
		{
			if (Empty())
			{
				return;
			}
			m_vector[0] = m_vector.back();
			m_vector.pop_back();

			_Adapt(0);
		}
		T Top()
		{
			if (Empty())
			{
				return NULL;
			}
			return m_vector[0];
		}

		int Size()
		{
			return m_vector.size();
		}
		bool Empty()
		{
			return m_vector.empty();
		}

		vector<T> Sort()
		{
			vector<T> v;
			while (!Empty())
			{
				v.push_back(Top());
				Pop();
			}
			return v;
		}
	};
}