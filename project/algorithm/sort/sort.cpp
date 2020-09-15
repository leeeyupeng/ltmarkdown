// sort.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <random>
#include<algorithm>
#include<time.h>
#include "include/insertsort.h"
#include "include/selectsort.h"
#include "include/swapsort.h"
#include "include/mergesort.h"
using namespace std;

#define N 10000
int main()
{
	{
		std::cout << "内排序\n";
		int arr[N];
		int arr2[N];
		srand((unsigned)time(NULL));
		for (int i = 0; i < N; i++)
		{
			arr[i] = rand();
			arr2[i] = arr[i];
		}
		cout << endl;
		for (int i = 0; i < N; i++)
		{
			//cout << arr[i] << ";";
		}
		cout << endl;
		{
			//cout << "插入排序:" << endl;
			//ImprovedInsertSort2<int>(arr, N);

			//cout << "选择排序:" << endl;
			//SelectSort<int>(arr, N);

			//cout << "交换排序:" << endl;
			//BubbleSort2<int>(arr, N);

			//cout << "快速排序:" << endl;
			//QuickSort(arr,0,N - 1);

			cout << "归并排序:" << endl;
			int arrTemp[N];
			MergeSort1(arr,arrTemp, 0, N - 1);
			
		}
		{
			int rank = rand() % N + 1;
			cout << "Rank:" << rank << ":" << arr[rank - 1] << endl;

			cout << "Rank:" << rank << ":" << QuickSelect(arr2,0,N-1,rank) << endl;
		}
		for (int i = 1; i < N; i++)
		{
			if (arr[i - 1] > arr[i])
			{
				cout << "Error" << endl;
				system("PAUSE");
			}
		}
		cout << endl;
		for (int i = 0; i < N; i++)
		{
			//cout << arr[i] << ";";
		}
		cout << endl;
	}
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
