#pragma once
//https://leetcode-cn.com/problems/largest-rectangle-in-histogram/
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
	int largestRectangleArea(vector<int>& heights) {
		int n=heights.size();
		int m = 0;
		set<int> sheight;
		for (int i = 0; i < n; i++) {
			if (sheight.find(heights[i]) == sheight.end()) {
				sheight.insert(heights[i]);
			}
		}
		m = sheight.size();
		vector<int> vheight(m);
		set<int>::iterator ite = sheight.begin();
		for (int i = 0; i < m; i++) {
			vheight[i] = *ite;
			ite++;
		}
		vector<vector<long long>> dp(n + 1,vector<long long >(m + 1,0));
		long long ans = 0;
		int height;
		for (int i = 1; i <= n; i++) {
			for (int j = 0; j < m && vheight[j]<=heights[i-1]; j++) {
				dp[i][j] = dp[i - 1][j] + vheight[j];
				ans = max(ans, dp[i][j]);
			}
		}
		return ans;
	}
};