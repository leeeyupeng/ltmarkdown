#pragma once
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include<string>
#include<algorithm>

//https://leetcode-cn.com/problems/trapping-rain-water/
using namespace std;
int trap(const vector<int>& height) {
	stack<int> staIndex;
	stack<int> staHeight;
	int result = 0;
	for (int i = 0; i < height.size(); i++)
	{
		if (height[i] == 0)
		{
			continue;
		}
		if (staHeight.empty() && height[i]> 0)
		{
			staIndex.push(i);
			staHeight.push(height[i]);

			continue;
		}
		int heightLast = 0;
		while (!staHeight.empty() && height[i] >= staHeight.top())
		{
			int index = staIndex.top();
			staIndex.pop();
			int indexheight = staHeight.top();
			staHeight.pop();

			result += (indexheight - heightLast) * (i - index - 1);
			heightLast = indexheight;
		}
		if (!staHeight.empty() && height[i] > 0)
		{
			int index = staIndex.top();
			int indexheight = staHeight.top();

			result += (height[i] - heightLast) * (i - index - 1);
		}
		if (height[i] > 0)
		{
			staIndex.push(i);
			staHeight.push(height[i]);
		}
	}

	return result;
}

int trap2(const vector<int>& height) 
{
	if (height.size() == 0)
	{
		return 0;
	}
	vector<int> left(height.size());
	vector<int> right(height.size());
	left[0] = (height[0]);
	for (int i = 1; i < height.size(); i++)
	{
		left[i] = (height[i] > left[i - 1]? height[i] : left[i - 1]);
	}
	right[height.size() -1] = (height[height.size() - 1]);
	for (int i = height.size() - 2; i >=0; i--)
	{
		right[i] = (height[i] > right[i + 1] ? height[i] : right[i + 1]);
	}

	int result = 0;
	for (int i = 1; i < height.size() - 1; i++)
	{
		int min = left[i - 1] < right[i + 1] ? left[i - 1] : right[i + 1];
		if (height[i] < min)
		{
			result += min - height[i];
		}
	}
	return result;
}

int trap3(const vector<int>& height)
{
	if (height.size() == 0)
	{
		return 0;
	}

	int left = 0, right = height.size();
	int maxleft = 0, maxright = 0;
	int result = 0;
	while (left < right)
	{
		if (maxleft < maxright)
		{
			if (maxleft > height[left])
			{
				result += maxleft - height[left];
			}
			maxleft = height[left] > maxleft ? height[left] : maxleft;
			left++;
		}
		else
		{
			if (maxright > height[right - 1])
			{
				result += maxright - height[right -1];
			}
			maxright = height[right - 1] > maxright ? height[right - 1] : maxright;
			right--;
		}
	}
	return result;
}