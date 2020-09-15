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
//https://leetcode-cn.com/problems/median-of-two-sorted-arrays/
class Solution {
public:
	//int Bisection(vector<int>& nums1, vector<int>& nums2, int i, int j)
	//{
	//	int index1 = (i + j) / 2;
	//	int index2 = (nums1.size() + nums2.size() + 1) / 2 - index1;

	//	if (index1 < nums1.size() && index2 <= nums2.size() && nums1[index1] < nums2[index2 - 1])
	//	{
	//		return Bisection(nums1, nums2, index1 + 1, j);
	//	}
	//	else if (index1 > 0 && index2 <nums2.size() && nums1[index1 - 1] > nums2[index2])
	//	{
	//		return Bisection(nums1, nums2, i, index1 - 1);
	//	}
	//	return index1;
	//}
	//double findMedianSortedArrays2(vector<int>& nums1, vector<int>& nums2) 
	//{
	//	int i = 0, j = nums1.size();
	//	i = (nums1.size() - nums2.size() + 1) / 2;
	//	i = i >= 0 ? i : 0;
	//	j = (nums1.size() + nums2.size() + 1) / 2;
	//	j = j <= nums1.size() ? j : nums1.size();

	//	int index1 = Bisection(nums1,nums2,i,j);
	//	int index2 = (nums1.size() + nums2.size() + 1) / 2 - index1;

	//	int max_left;
	//	if (index1 == 0)
	//	{
	//		max_left = nums2[index2 - 1];
	//	}
	//	else if (index2 == 0)
	//	{
	//		max_left = nums1[index1 - 1];
	//	}
	//	else
	//	{
	//		max_left = nums1[index1 - 1] > nums2[index2 - 1] ? nums1[index1 - 1] : nums2[index2 - 1];
	//	}

	//	if ((nums1.size() + nums2.size()) % 2 == 1)
	//	{
	//		return max_left;
	//	}

	//	int min_right;
	//	if (index1 == nums1.size())
	//	{
	//		min_right = nums2[index2];
	//	}
	//	else if (index2 == nums2.size())
	//	{
	//		min_right = nums1[index1];
	//	}
	//	else
	//	{
	//		min_right = nums1[index1] < nums2[index2] ? nums1[index1] : nums2[index2];
	//	}
	//	return (max_left + min_right) * 0.5f;

	//}

	//double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)
	//{
	//	if (nums1.size() > nums2.size())
	//	{
	//		return findMedianSortedArrays2(nums2,nums1);
	//	}
	//	else
	//	{
	//		return findMedianSortedArrays2(nums1, nums2);
	//	}
	//}

	//double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)
	//{
	//	int m = nums1.size();
	//	int n = nums2.size();
	//	vector<int> nums(m + n);
	//	int i = 0, j = 0;
	//	for (int k = 0; k < m+n; k++)
	//	{
	//		if (i == m)
	//		{
	//			nums[k] = nums2[j];
	//			j++;
	//		}
	//		else if (j == n)
	//		{
	//			nums[k] = nums1[i];
	//			i++;
	//		}
	//		else if(nums1[i] <= nums2[j])
	//		{
	//			nums[k] = nums1[i];
	//			i++;
	//		}
	//		else
	//		{
	//			nums[k] = nums2[j];
	//			j++;
	//		}
	//	}

	//	if ((m+n) % 2 == 1)
	//	{
	//		return nums[(m + n) / 2];
	//	}
	//	else
	//	{
	//		return (nums[(m + n) / 2 - 1] + nums[(m + n) / 2]) * 0.5f;
	//	}
	//}

	//double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)
	//{
	//	int i = 0, j = 0;
	//	int m = nums1.size();
	//	int n = nums2.size();
	//	while (i + j < (m + n + 1) / 2)
	//	{
	//		if (i == m)
	//		{
	//			j++;
	//		}
	//		else if (j == n)
	//		{
	//			i++;
	//		}
	//		else if(nums1[i] <= nums2[j])
	//		{
	//			i++;
	//		}
	//		else
	//		{
	//			j++;
	//		}
	//	}

	//	int max_left = 0;
	//	if (i == 0)
	//	{
	//		max_left = nums2[j - 1];
	//	}
	//	else if (j == 0)
	//	{
	//		max_left = nums1[i - 1];
	//	}
	//	else
	//	{
	//		max_left = nums1[i - 1] > nums2[j - 1] ? nums1[i - 1] : nums2[j - 1];
	//	}

	//	if ((m+n) % 2 == 1)
	//	{

	//		return max_left;
	//	}

	//	int min_right = 0;
	//	if (i == m)
	//	{
	//		min_right = nums2[j];
	//	}
	//	else if (j == n)
	//	{
	//		min_right = nums1[i];
	//	}
	//	else
	//	{
	//		min_right = nums1[i] < nums2[j] ? nums1[i] : nums2[j];
	//	}
	//	return (max_left+min_right) * 0.5f;
	//}

	//double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)
	//{

	//	int m = nums1.size();
	//	int n = nums2.size();
	//	int i = 0;
	//	int j = (m + n + 1) / 2 - i;
	//	int iMin = 0, iMax = m;
	//	if (m == 0)
	//	{
	//		i = 0;
	//		j = (m + n + 1) / 2;
	//	}
	//	else if (n == 0)
	//	{
	//		i = (m + n + 1) / 2;
	//		j = 0;
	//	}
	//	else
	//	{
	//		while (iMin <= iMax)
	//		{
	//			i = (iMin + iMax) / 2;
	//			j = (m + n + 1) / 2 - i;

	//			if (j < 0)
	//			{
	//				iMax = i - 1;
	//				continue;
	//			}
	//			else if (j > n)
	//			{
	//				iMin = i + 1;
	//				continue;
	//			}

	//			if (i == m)
	//			{
	//				if (nums1[i - 1] <= nums2[j])
	//				{
	//					break;
	//				}
	//				else
	//				{
	//					iMax = i - 1;
	//					continue;
	//				}
	//			}
	//			else if (i == 0)
	//			{
	//				if (nums1[i] >= nums2[j - 1])
	//				{
	//					break;
	//				}
	//				else
	//				{
	//					iMin = i + 1;
	//					continue;
	//				}
	//			}

	//			if (j == n)
	//			{
	//				if (nums1[i] >= nums2[j - 1])
	//				{
	//					break;
	//				}
	//				else
	//				{
	//					iMin = i + 1;
	//					continue;
	//				}
	//			}
	//			else if (j == 0)
	//			{
	//				if (nums1[i - 1] <= nums2[j])
	//				{
	//					break;
	//				}
	//				else
	//				{
	//					iMax = i - 1;
	//					continue;
	//				}
	//			}
	//			if (nums1[i - 1] > nums2[j])
	//			{
	//				iMax = i - 1;
	//			}
	//			else if (nums1[i] < nums2[j - 1])
	//			{
	//				iMin = i + 1;
	//			}
	//			else
	//			{
	//				break;
	//			}
	//		}
	//	}

	//	int max_left = 0;
	//	if (i == 0)
	//	{
	//		max_left = nums2[j - 1];
	//	}
	//	else if (j == 0)
	//	{
	//		max_left = nums1[i - 1];
	//	}
	//	else
	//	{
	//		max_left = nums1[i - 1] > nums2[j - 1] ? nums1[i - 1] : nums2[j - 1];
	//	}

	//	if ((m + n) % 2 == 1)
	//	{

	//		return max_left;
	//	}

	//	int min_right = 0;
	//	if (i == m)
	//	{
	//		min_right = nums2[j];
	//	}
	//	else if (j == n)
	//	{
	//		min_right = nums1[i];
	//	}
	//	else
	//	{
	//		min_right = nums1[i] < nums2[j] ? nums1[i] : nums2[j];
	//	}
	//	return (max_left + min_right) * 0.5f;
	//}

	int findKSortedArraysBisection(vector<int>& nums1, vector<int>& nums2, int k)
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
				if (i == m && j == n)
				{
					break;
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
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)
	{
		int n = nums1.size();
		int m = nums2.size();
		if ((n + m) % 2 == 1)
		{
			return findKSortedArraysBisection(nums1,nums2,(n+m)/2 + 1);
		}
		else
		{
			return (findKSortedArraysBisection(nums1, nums2, (n + m) / 2) + findKSortedArraysBisection(nums1, nums2, (n + m) / 2 + 1)) * 0.5f;
		}
	}
};