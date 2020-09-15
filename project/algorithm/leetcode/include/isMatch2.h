#pragma once
#include <iostream>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <string>
#include <map>
#include <set>
#include <algorithm>
using namespace std;
//https://leetcode-cn.com/problems/regular-expression-matching/
class Solution {
public:
	bool isMatch(string s, string p) {
		int n = s.length();
		int m = p.length();
		vector<vector<bool>> dp(n + 1);
		for (int i = 0; i < n + 1; i++) {
			dp[i].insert(dp[i].begin(),m + 1,false);
		}

		dp[0][0] = true;

		for (int j = 0; j < m + 1; j++) {
			if (j > 1 && p[j-1] == '*') {
				dp[0][j] = dp[0][j] || dp[0][j - 2];
			}
		}
		for (int i = 1; i < n + 1; i++) {
			for (int j = 1; j < m + 1; j++) {
				if (s[i-1] == p[j-1]) {
					dp[i][j] = dp[i-1][j-1];
				}
				else if (p[j-1] == '.') {
					dp[i][j] = dp[i-1][j-1];
				}
				else if (p[j-1] == '*') {
					if (j > 1) { dp[i][j] = dp[i][j] || dp[i][j - 2]; }
					if (j > 1 && (s[i-1] == p[j - 2] || p[j - 2] == '.')) {
						dp[i][j] = dp[i][j] || dp[i-1][j-1];
						dp[i][j] = dp[i][j] || dp[i-1][j];
					}
				}
			}
		}
		return dp[n][m];
	}
};