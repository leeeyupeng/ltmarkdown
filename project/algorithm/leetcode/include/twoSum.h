#pragma once
//https://leetcode-cn.com/problems/two-sum/
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
	vector<int> twoSum(vector<int>& nums, int target) {
		vector<int> ans(2, 0);
		unordered_map<int, int> map0;
		unordered_map<int, int> map;
		for (int i = 0; i < nums.size(); i++) {
			if (nums[i] >= target >> 1) {
				if (map0.find(nums[i]) == map0.end()) {
					map.insert({ nums[i],i });
				}
				else {
					map[nums[i]] = i;
				}
			}
			if (nums[i] <= target >> 1) {
				if (map0.find(nums[i]) == map0.end()) {
					map0.insert({ nums[i],i });
				}
			}
		}
		int i,j;

		unordered_map<int, int>::iterator iter;
		for (iter = map0.begin(); iter != map0.end(); iter++) {
			if (iter->first <= target >> 1) {
				if (map.find(target - iter->first) != map.end()) {
					i = iter->second;
					j = map[target - iter->first];
					if (i > j) { ans[0] = j; ans[1] = i; break; }
					else if (i < j) { ans[0] = i; ans[1] = j; break; }
				}
			}
		}
		return ans;
	}
};