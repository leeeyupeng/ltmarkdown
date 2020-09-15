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
			if ((m - i) & 0x01 == 0x01) {
				if (nums[m] == nums[m+1]) {
					j = m;
				}
				else {
					i = m+1;
				}
			}
			else {
				if (nums[m] == nums[m+1]) {
					i = m + 2;
				}
				else {
					j = m;
				}
			}
		}
		return nums[i];
	}
};