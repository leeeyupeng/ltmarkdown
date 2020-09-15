#pragma once
#include <iostream>
#include "sort.h"
using namespace std;
//πÈ≤¢≈≈–Ú
template <typename T>
void Merge1(T arr[], T arrTemp[], int left, int right, int middle)
{
	for (int i = left; i <= right; i++)
	{
		arrTemp[i] = arr[i];
	}

	int i = left;
	int j = middle + 1;
	for (int k = left; k <= right; k++)
	{
		if (i > middle)
		{
			arr[k] = arrTemp[j++];
		}
		else if (j > right)
		{
			arr[k] = arrTemp[i++];
		}
		else if (arrTemp[i] <= arrTemp[j])
		{
			arr[k] = arrTemp[i++];
		}
		else if(arrTemp[i] > arrTemp[j])
		{
			arr[k] = arrTemp[j++];
		}
		else
		{
			cout << "MergeSort1 Error" << endl;
			system("PAUSE");
		}
	}
}
template <typename T>
void MergeSort1(T arr[], T arrTemp[], int left, int right)
{
	if (left >= right)
	{
		return;
	}
	int middle = (left + right) / 2;
	MergeSort1(arr, arrTemp,left, middle);
	MergeSort1(arr, arrTemp, middle + 1, right);
	Merge1(arr, arrTemp, left, right, middle);
}
//πÈ≤¢≈≈–Ú
template <typename T>
void Merge2(T arr[], int left,int right,int middle)
{
	int i = left;
	int j = middle + 1;
	int k = j;


}
template <typename T>
void MergeSort2(T arr[], int left, int right)
{
	if (left >= right)
	{
		return;
	}
	int middle = (left + right) / 2;
	MergeSort2(arr,left,middle);
	MergeSort2(arr, middle + 1, right);
	Merge2(arr, left, right, middle);
}