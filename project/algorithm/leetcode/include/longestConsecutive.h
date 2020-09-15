#pragma once
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include<string>
#include<algorithm>

using namespace std;
//https://leetcode-cn.com/problems/longest-consecutive-sequence
//并查集
int longestConsecutive(const vector<int>& nums) 
{
	map<int, int> map;
	for (int i = 0; i < nums.size(); i++)
	{
		map.insert({ nums[i],nums[i] });
	}
	for (int i = 0; i < nums.size(); i++)
	{
		if (map.find(nums[i] - 1) != map.end())
		{
			map[nums[i]] = nums[i] - 1;
		}
		else
		{
			map[nums[i]] = nums[i];
		}
	}
	int result = 0;
	for (int i = 0; i < nums.size(); i++)
	{
		if (map.find(nums[i] + 1) != map.end())
		{
			continue;
		}
		int temp = 1;
		int j = nums[i];
		while (map[j] == j - 1)
		{
			temp++;
			j--;
		}

		result = temp > result ? temp : result;
	}
	return result;
}

//并查集
int longestConsecutive2(const vector<int>& nums)
{
	int result = 0;
	map<int, int> map;
	for (int i = 0; i < nums.size(); i++)
	{
		map.insert({ nums[i],nums[i] });
	}
	for (int i = 0; i < nums.size(); i++)
	{
		if (map.find(nums[i] - 1) == map.end())
		{
			int j = nums[i];
			while (map.find(j + 1) != map.end())
			{
				map[j + 1] = map[j];
				j++;
			}
			result = j - map[nums[i]] + 1 > result ? j - map[nums[i]] + 1 : result;
		}
	}
	return result;
}