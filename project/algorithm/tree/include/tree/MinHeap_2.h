#pragma once
#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <functional>
#include <queue>
#include<string>
#include<map>
#include<unordered_map>
#include<unordered_set>
#if defined(linux)
#include<memory.h>
#include<limits.h>
#endif

using namespace std;
namespace lt {
	namespace tree
	{
		template<class T>
		inline void swap(T& a, T& b) {
			T temp = a;
			a = b;
			b = temp;
		}
#define RESIZE 256		
		template<typename T>
		class MinHeap
		{
			typedef std::function<bool(const T&, const T&)> cmpfunc;
		private:
			int length;
			int size;
			T* m_arr;
		public:
			cmpfunc cmp;
			void resize(int _size);
		public:
			MinHeap(cmpfunc _cmp);
			MinHeap(int _size, cmpfunc _cmp);
			MinHeap(int _size, T _arr[], int _length, cmpfunc _cmp);
			~MinHeap();
			void Push(T _e);
			void Pop();
			T Top();
			bool Empty();
		};

		template<class T>
		void MinHeap<T>::resize(int _size) {
			m_arr = (T*)realloc(m_arr, sizeof(T) * _size);
			size = _size;
		}

		template<class T>
		MinHeap<T>::MinHeap(cmpfunc _cmp) :MinHeap<T>::MinHeap(RESIZE, _cmp) {
		}

		template<class T>
		MinHeap<T>::MinHeap(int _size, cmpfunc _cmp) : size(_size), length(0), cmp(_cmp) {
			m_arr = (T*)malloc(sizeof(T) * size);
		} 

		template<class T>
		MinHeap<T>::MinHeap(int _size, T _arr[], int _length, cmpfunc _cmp) : MinHeap<T>::MinHeap(_size, _cmp){
			//m_arr = (T*)malloc(sizeof(T) * size);
			//memcpy(m_arr + 1, _arr, sizeof(T)*length);

			//����
			length = _length;
			memcpy(m_arr + 1, _arr, sizeof(T)*length);

			int leftleaf = (length + 1) >> 1;
			int index = 0;
			for (int i = length; i >= leftleaf; i--) {
				index = i;
				while (index > 1) {
					if (cmp(m_arr[index], m_arr[index >> 1])) {
						swap(m_arr[index], m_arr[index >> 1]);						
					}
					index = index >> 1;
					//else { break; }
				}
			}

		}
		template<class T>
		MinHeap<T>::~MinHeap() {
			free(m_arr);
			m_arr = NULL;
			size = 0;
			length = 0;
		}

		template<class T>
		void MinHeap<T>::Push(T _e) {
			length++;
			if (size < length + 1) { resize(size + RESIZE); }
			m_arr[length] = _e;

			int index = length;
			while (index > 1) {
				if (cmp(m_arr[index], m_arr[index >> 1])) {
					swap(m_arr[index], m_arr[index >> 1]);
					index = index >> 1;
				}
				else { break; }
			}
		}

		template<class T>
		void MinHeap<T>::Pop() {
			m_arr[1] = m_arr[length];
			length--;

			int index = 1;
			int leaf = 0;
			while ((index << 1) <= length) {
				leaf = (index << 1);
				if (leaf + 1 <= length && cmp(m_arr[leaf + 1] , m_arr[leaf])) {
					leaf = leaf + 1;
				}
				
				if (cmp(m_arr[leaf], m_arr[index])) {
					swap(m_arr[index], m_arr[leaf]);
					index = leaf;
				}
				else {
					break;
				}
			}
		}
		template<class T>
		T MinHeap<T>::Top() {
			return m_arr[1];
		}

		template<class T>
		bool MinHeap<T>::Empty() {
			return length == 0;
		}
	}
}
