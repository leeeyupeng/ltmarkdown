
#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <algorithm>
#include <ctime>
using namespace std;
class Solution {
public:
	int findKSortedArraysMerge(vector<int>& nums1, vector<int>& nums2,int k)
	{
		int m = nums1.size();
		int n = nums2.size();
		vector<int> nums(m + n);
		int i = 0, j = 0;
		for (int kk = 0; kk < m+n; kk++)
		{
			if (i == m)
			{
				nums[kk] = nums2[j];
				j++;
			}
			else if (j == n)
			{
				nums[kk] = nums1[i];
				i++;
			}
			else if(nums1[i] <= nums2[j])
			{
				nums[kk] = nums1[i];
				i++;
			}
			else
			{
				nums[kk] = nums2[j];
				j++;
			}
		}
		return nums[k - 1];
	}
	int findKSortedArraysIJ(vector<int>& nums1, vector<int>& nums2,int k)
	{
		int i = 0, j = 0;
		int m = nums1.size();
		int n = nums2.size();
		while (i + j < k)
		{
			if (i == m)
			{
				j++;
			}
			else if (j == n)
			{
				i++;
			}
			else if(nums1[i] <= nums2[j])
			{
				i++;
			}
			else
			{
				j++;
			}
		}

		int max_left = 0;
		if (i == 0)
		{
			max_left = nums2[j - 1];
		}
		else if (j == 0)
		{
			max_left = nums1[i - 1];
		}
		else
		{
			max_left = nums1[i - 1] > nums2[j - 1] ? nums1[i - 1] : nums2[j - 1];
		}
		return max_left;
	}
	int findKSortedArraysBisection(vector<int>& nums1, vector<int>& nums2,int k)
	{
		int m = nums1.size();
		int n = nums2.size();
		int i = 0;
		int j = k - i;
		int iMin = 0, iMax = m;
		if (m == 0)
		{
			i = 0;
			j = k;
		}
		else if (n == 0)
		{
			i = k;
			j = 0;
		}
		else
		{
			while (iMin <= iMax)
			{
				i = (iMin + iMax) / 2;
				j = k - i;

				if (j < 0)
				{
					iMax = i - 1;
					continue;
				}
				else if (j > n)
				{
					iMin = i + 1;
					continue;
				}

				if (i == m)
				{
					if (nums1[i - 1] <= nums2[j])
					{
						break;
					}
					else
					{
						iMax = i - 1;
						continue;
					}
				}
				else if (i == 0)
				{
					if (nums1[i] >= nums2[j - 1])
					{
						break;
					}
					else
					{
						iMin = i + 1;
						continue;
					}
				}

				if (j == n)
				{
					if (nums1[i] >= nums2[j - 1])
					{
						break;
					}
					else
					{
						iMin = i + 1;
						continue;
					}
				}
				else if (j == 0)
				{
					if (nums1[i - 1] <= nums2[j])
					{
						break;
					}
					else
					{
						iMax = i - 1;
						continue;
					}
				}
				if (nums1[i - 1] > nums2[j])
				{
					iMax = i - 1;
				}
				else if (nums1[i] < nums2[j - 1])
				{
					iMin = i + 1;
				}
				else
				{
					break;
				}
			}
		}

		int max_left = 0;
		if (i == 0)
		{
			max_left = nums2[j - 1];
		}
		else if (j == 0)
		{
			max_left = nums1[i - 1];
		}
		else
		{
			max_left = nums1[i - 1] > nums2[j - 1] ? nums1[i - 1] : nums2[j - 1];
		}
		return max_left;
	}
};