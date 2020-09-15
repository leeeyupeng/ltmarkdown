#pragma once
//https://leetcode-cn.com/problems/maximal-rectangle/
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
	int maximalRectangle(vector<vector<char>>& matrix) {
		int n = matrix.size();
		int m = 0;
		if (n > 0) { m = matrix[0].size(); }
		vector<vector<int>> heights(n + 1,vector<int>(m + 1,0));
		vector<vector<vector<int>>> dp(n + 1,vector<vector<int>>(m + 1, vector<int>(n + 1, 0)));
		int ans = 0;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				if (matrix[i-1][j-1] == '0') { continue; }
				heights[i][j] = heights[i-1][j] + 1;
				for (int k = 1; k <= heights[i][j]; k++) {
					dp[i][j][k] = dp[i][j-1][k] + k;
					ans = max(ans, dp[i][j][k]);
				}
			}
		}
		return ans;
	}
};
