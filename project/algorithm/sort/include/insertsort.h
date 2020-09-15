#pragma once

#include "sort.h"
//≤Â»Î≈≈–Ú
template<typename T>
void ImprovedInsertSort1(T array[],int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = i - 1; j >= 0; j--)
		{
			if (array[j] > array[j + 1])
			{
				Swap(array[j], array[j + 1]);
			}
			else
			{
				break;
			}
		}
	}
}

//≤Â»Î≈≈–Ú
template<typename T>
void ImprovedInsertSort2(T array[], int n)
{
	for (int i = 0; i < n; i++)
	{
		T temp = array[i];
		for (int j = i - 1; j >= 0; j--)
		{
			if (array[j] > temp)
			{
				array[j + 1] = array[j];
			}
			else
			{
				array[j + 1] = temp;
				break;
			}
		}
	}
}
