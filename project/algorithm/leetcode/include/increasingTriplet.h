#pragma once
//https://leetcode-cn.com/problems/increasing-triplet-subsequence/
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
	bool increasingTriplet(vector<int>& nums) {
		int n = nums.size();
		int ans = 0;
		vector<int> tails(3,INT32_MAX);
		int j;
		for (int i = 0; i < n; i++) {
			if (tails[1] >= nums[i]) {
				tails[1] = nums[i];
			}
			else if(tails[2]>=nums[i]){
				tails[2] = nums[i];
			}
			else {
				return true;
			}
		}
		return false;
	}
};