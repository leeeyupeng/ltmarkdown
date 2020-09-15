#pragma once
//https://leetcode-cn.com/problems/single-element-in-a-sorted-array/
#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <set>
#include <stack>
#include<string>
#include<algorithm>

using namespace std;
class Solution {
public:
	int singleNonDuplicate(vector<int>& nums) {
		int n = nums.size();
		int i = 0, j = n;
		int m = n;
		while (i < j-1) {
			m = (i + j) >> 1;
			m |= 0x1;
			if (nums[m] == nums[m-1]) {
				j = m + 1;
			}
			else {
				i = m+1;
			}
		}
		return nums[i];
	}
};