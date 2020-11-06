#pragma once
#include <algorithm>
namespace lt {
	template<class IT, class T>
	void mergesortmerge(IT begin1, IT end1, IT begin2, IT end2);


	template<class T>
	inline void swap(T &a, T &b) {
		T temp;
		temp = a;
		a = b;
		b = temp;
	}
	inline void swap(int &a, int &b) {
		a ^= b;
		b ^= a;
		a ^= b;
	}
	template<class IT, class T>
	void fill(IT begin, IT end, T value) {
		IT ite = begin;
		while (ite != end) {
			(*ite) = value;
			ite++;
		}
	}
	//void fill(std::vector<int>::iterator begin, std::vector<int>::iterator end, int value);

	template<class IT,class T>
	T accumulate(IT begin, IT end, T init) {
		T ans = init;
		IT ite = begin;
		while (ite != end) {
			ans += (*ite);
			ite++;
		}
		return ans;
	}
	template<class IT>
	void bubblesort(const IT begin, const IT end) {
		IT itei, itej;
		for (itei = end-1; itei != begin; itei--) {
			for (itej = begin; itej!= itei; itej++) {
				if ((*itej) > (*(itej+1))) {
					swap((*itej),(*(itej + 1)));
				}
			}
		}
	}
	template<class IT,class T>
	void quicksort(IT begin, IT end) {
		IT itei=begin, itej = end-1;
		T temp = *(end - 1);
		while (itei < itej) {
			while (itei < itej && *itei <= temp) {itei++; }
			if (itei == itej) {
				*itej = temp; break;
			}
			else { *itej = *itei; }
			while (itei < itej && *itej >= temp) { itej--; }
			if (itei == itej) {
				*itej = temp; break;
			}
			else { *itei = *itej; }
		}
		if (itei != begin) { quicksort<IT,T>(begin,itei); }
		if(itej!=end-1) { quicksort<IT, T>(itej+1, end); }
	}
	template<typename T>
	void quicksort2(typename std::vector<T>::iterator  begin, typename std::vector<T>::iterator  end) {
		typename std::vector<T>::iterator itei = begin, itej = end - 1;
		T temp = *(end - 1);
		while (itei < itej) {
			while (itei < itej && *itei <= temp) { itei++; }
			if (itei == itej) {
				*itej = temp; break;
			}
			else { *itej = *itei; }
			while (itei < itej && *itej >= temp) { itej--; }
			if (itei == itej) {
				*itej = temp; break;
			}
			else { *itei = *itej; }
		}
		if (itei != begin) { quicksort2<int>(begin, itei); }
		if (itej != end - 1) { quicksort2<int>(itej + 1, end); }
	}

	template<class IT, class T>
	void mergesort(IT begin, IT end) {
		if (begin+1 == end) { return; }
		IT mid = begin + (distance(begin,end) >> 1);
		mergesort<IT,T>(begin,mid);
		mergesort<IT, T>(mid, end);
		mergesortmerge<IT, T>(begin,mid,mid,end);
	}
	template<class IT, class T>
	void mergesortmerge(IT begin1, IT end1, IT begin2, IT end2) {
		int n1 = distance(begin1,end1);
		int n2 = distance(begin2,end2);
		vector<T> v(n1+n2);
		IT i = begin1, j = begin2;
		typename vector<T>::iterator s = v.begin();
		while (i != end1 || j != end2) {
			if (i != end1 && j != end2) {
				if (*i <= *j) { *s = *i; s++; i++; }
				else { *s = *j; s++; j++; }
			}
			else if (i != end1) {
				*s = *i; s++; i++;
			}
			else if (j != end2) {
				*s = *j; s++; j++;
			}
		}

		s = v.begin();
		i = begin1, j = begin2;
		while (i != end1) { *i = *s; i++; s++; }
		while (j != end2) { *j = *s; j++; s++; }
	}
}