#pragma once
#include "sort.h"
//—°‘Ò≈≈–Ú
template <typename T>
void SelectSort(T arr[], int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		int min = i;
		for (int j = i + 1; j < n; j++)
		{
			if (arr[j] < arr[min])
			{
				min = j;
			}
		}
		if (i != min)
		{
			Swap(arr[i], arr[min]);
		}
	}
}
