#pragma once
#include "sort.h"
//√∞≈›≈≈–Ú
template <typename T>
void BubbleSort1(T arr[], int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = n - 1; j > i; j--)
		{
			if (arr[j] < arr[j - 1])
			{
				Swap(arr[j],arr[j-1]);
			}
		}
	}
}
//√∞≈›≈≈–Ú
template <typename T>
void BubbleSort2(T arr[], int n)
{
	bool bSwap = false;
	for (int i = 0; i < n; i++)
	{
		bSwap = false;
		for (int j = n - 1; j > i; j--)
		{
			if (arr[j] < arr[j - 1])
			{
				Swap(arr[j], arr[j - 1]);
				bSwap = true;
			}
		}

		if (bSwap == false)
		{
			break;
		}
	}
}

//øÏÀŸ≈≈–Ú
int SelectPivot(int left, int right)
{
	return (left + right) / 2;
}
template<typename T>
void QuickSort(T arr[],int left,int right)
{
	if (left >= right)
	{
		return;
	}
	int pivot = SelectPivot(left,right);
	T temp = arr[pivot];
	arr[pivot] = arr[right];
	int i = left;
	int j = right;
	while (i < j)
	{
		while (i < j)
		{
			if (arr[i] > temp)
			{
				arr[j] = arr[i];
				break;
			}
			i++;
		}
		if (i == j)
		{
			pivot = j;
			break;
		}
		while (i < j)
		{
			if (arr[j] < temp)
			{
				arr[i] = arr[j];
				break;
			}
			j--;
		}
		if (i == j)
		{
			pivot = i;
			break;
		}
	}
	arr[pivot] = temp;
	QuickSort(arr,left,pivot - 1);
	QuickSort(arr,pivot + 1, right);
}
template<typename T>
T QuickSelect(T arr[], int left, int right, int rank)
{
	if (left == right)
	{
		return arr[left];
	}
	int pivot = SelectPivot(left, right);
	T temp = arr[pivot];
	arr[pivot] = arr[right];
	int i = left;
	int j = right;
	while (i < j)
	{
		while (i < j)
		{
			if (arr[i] > temp)
			{
				arr[j] = arr[i];
				break;
			}
			i++;
		}
		if (i == j)
		{
			pivot = j;
			break;
		}
		while (i < j)
		{
			if (arr[j] < temp)
			{
				arr[i] = arr[j];
				break;
			}
			j--;
		}
		if (i == j)
		{
			pivot = i;
			break;
		}
	}
	arr[pivot] = temp;
	if (pivot - left + 1 == rank)
	{
		return temp;
	}
	else if (pivot - left + 1 > rank)
	{
		return QuickSelect(arr, left, pivot - 1, rank);
	}
	else
	{
		return QuickSelect(arr, pivot + 1, right,rank - (pivot - left + 1));
	}
}