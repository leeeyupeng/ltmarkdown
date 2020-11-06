#include <iostream>
#include <thread>
#include <vector>
#include <functional>
#include <algorithm>
#include<string.h>

#include "algorithm_sort.hpp"
using namespace std;


#define NUMS 50000000
void print(int* arr, int length) {
	for (int i = 0; i < length; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}
bool check(int* arr1, int* arr2, int length) {
	for (int i = 0; i < length; i++) {
		if (arr1[i] != arr2[i]) { return false; }
	}
	return true;
}
int main() {
	int* arr;
	arr = (int*)malloc(sizeof(int) * NUMS);
	for (int i = 0; i < NUMS; i++) {
		arr[i] = rand();
	}


	cout << "���ݸ���:" << NUMS << endl;
	int *arralgorithm = (int*)malloc(sizeof(int) * NUMS);
	{
		cout << "algorithm_sort:" << endl;
		memcpy(arralgorithm, arr, sizeof(int) * NUMS);
		clock_t start = clock();
		sort(arralgorithm, arralgorithm+NUMS);
		clock_t end = clock();
		cout << "algorithm_sort ��ʱ: " << end - start << "����" << endl;
		//print(arralgorithm, NUMS);
	}

	//{
	//	cout << "insert_sort:" << endl;
	//	int *arrtemp = (int*)malloc(sizeof(int) * NUMS);
	//	memcpy(arrtemp,arr ,sizeof(int) * NUMS);
	//	clock_t start = clock();
	//	insert_sort(arrtemp,NUMS);
	//	clock_t end = clock();
	//	cout << "insert_sort ��ʱ: " << end - start <<"����"<< endl;
	//	if (!check(arralgorithm, arrtemp, NUMS)) {
	//		cout << "insert_sort:�������" << endl;
	//		print(arrtemp, NUMS);
	//	}
	//	
	//}
	{
		cout << "merge_sort:" << endl;
		int *arrtemp= (int*)malloc(sizeof(int) * NUMS);
		memcpy(arrtemp, arr, sizeof(int) * NUMS);
		clock_t start = clock();
		merge_sort(arrtemp, NUMS);
		clock_t end = clock();
		cout << "merge_sort ��ʱ: " << end - start << "����" << endl;
		
		if (!check(arralgorithm, arrtemp, NUMS)) {
			cout << "merge_sort:�������" << endl;
			print(arrtemp, NUMS);
		}		
	}
	{
		cout << "parallel_merge_sort:" << endl;
		int *arrtemp = (int*)malloc(sizeof(int) * NUMS);
		memcpy(arrtemp, arr, sizeof(int) * NUMS);
		int threadnums = std::thread::hardware_concurrency();
		clock_t start = clock();
		parallel_merge_sort(arrtemp, NUMS, threadnums);
		clock_t end = clock();
		cout << "parallel_merge_sort �߳�����:" << threadnums << endl;
		cout << "parallel_merge_sort ��ʱ: " << end - start << "����" << endl;

		if (!check(arralgorithm, arrtemp, NUMS)) {
			cout << "parallel_merge_sort:�������" << endl;
			print(arrtemp, NUMS);
		}
		
	}
	cout << endl;
	return 0;
}