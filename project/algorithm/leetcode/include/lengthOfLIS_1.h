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
private:
	int Get(vector<int>& tails,int num,int n) {
		int i = 1, j = n;
		int m;
		while (i < j) {
			m = ((i + j) >> 1);
			if (tails[m] >= num) { j = m-1; }
			else { i = m+1; }
		}
		return j;
	}
public:
	int lengthOfLIS(vector<int>& nums) {
		int n = nums.size();
		int ans = 0;
		vector<int> tails(n + 1,0);
		int j;
		for (int i = 0; i < n; i++) {
			j = Get(tails,nums[i],ans);
			tails[j+1] = nums[i];
			ans = max(ans,j+1);
		}
		return ans;
	}
};