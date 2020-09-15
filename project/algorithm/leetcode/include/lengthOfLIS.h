#pragma once
//https://leetcode-cn.com/problems/longest-increasing-subsequence/
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
	int lengthOfLIS(vector<int>& nums) {
		int n = nums.size();
		int ans = 0;
		vector<int> dp(n + 1, 1);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < i; j++) {
				if (nums[i] > nums[j]) {
					dp[i] = max(dp[i], dp[j] + 1);
				}
			}
			ans = max(ans,dp[i]);
		}
		return ans;
	}
};