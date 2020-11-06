#include<iostream>
#include<algorithm>
using namespace std;

template<typename T>
void _merge_sort(T* arr,int left,int right, T* arrtemp);

template<typename T>
void _merge_sort_merge(T* arr, int left, int mid, int right, T* arrtemp);
template<typename T>
inline void swap(T &a, T &b) {
	a ^= b;
	b ^= a;
	a ^= b;
}
template<typename T>
void insert_sort(T* arr, int length) {
	int index;
	for (int i = 1; i < length; i++) {
		T value = arr[i];
		index = i;	
		index--;
		while (index >= 0 && arr[index] > value) {
			arr[index+1] = arr[index];
			index--;
		}
		arr[index + 1] = value;
	}
}
# define MINNUMSTOINSERTSORT 28
template<typename T>
void merge_sort(T* arr,int length) {
	T* arrtemp = (T*)malloc(sizeof(T)*length);
	_merge_sort(arr,0,length, arrtemp);
	//memcpy(arr, arrtemp, sizeof(T)*length);
}
template<typename T>
void _merge_sort(T* arr,int left,int right, T* arrtemp) {
	if (right - left <= MINNUMSTOINSERTSORT) {
		insert_sort(arr+left,right-left);
		return;
	}

	int mid = (left + right) >> 1;
	_merge_sort(arr,left,mid, arrtemp);
	_merge_sort(arr, mid,right, arrtemp);
	_merge_sort_merge(arr,left,mid,right, arrtemp);
}
template<typename T>
void _merge_sort_merge(T* arr, int left, int mid, int right, T* arrtemp) {
	int l = left, r = mid;
	int index = left;
	while (l < mid && r < right) {
		if (arr[l] < arr[r]) {
			arrtemp[index++] = arr[l++];
		}
		else {
			arrtemp[index++] = arr[r++];
		}
	}
	// ����һ����ʣ�µ�����Ԫ��ֱ�Ӹ��Ƶ��ϲ�����β
	while (l < mid) {
		arrtemp[index++] = arr[l++];
	}
	while (r < right) {
		arrtemp[index++] = arr[r++];
	}
	for (int i = left; i < right; i++) {
		arr[i] = arrtemp[i];
	}
	//memcpy(arr+left,arrtemp+left,sizeof(T)*(right-left));
} 

# define MINNUMSTHREAD 10000
template<typename T>
void parallel_merge_sort(T* arr, int length,int& threadnums) {
	T* arrtemp = (T*)malloc(sizeof(T)*length);
	//_parallel_merge_sort(arr, 0, length, arrtemp);
	int threadlength = (length + threadnums - 1) / threadnums;
	threadlength = max(threadlength,MINNUMSTHREAD);
	threadnums = min(threadnums, (length + threadlength - 1) / threadlength);
	int count = threadnums;
	vector<thread*> vt;
	for (int i = 0; i < count; i++) {
		//merge_sort(arr+ i * threadlength, min(threadlength, length - i * threadlength));
		thread* th = new thread(_merge_sort<int>, arr,i * threadlength, min((i+1) * threadlength, length), arrtemp);
		vt.push_back(th);
		//th.join();
	}
	for (int i = 0; i < count; i++) {
		vt[i]->join();
	}
	//for (int i = 0; i < count; i++) {
	//	vt[i].
	//}
	for (int i = 0; i < count; i++) {
		free(vt[i]);
	}
	vt.clear();
	for (int i = 1; i < count; i++) {
		_merge_sort_merge(arr, 0, i * threadlength, min((i+1) * threadlength, length), arrtemp);
	}
}