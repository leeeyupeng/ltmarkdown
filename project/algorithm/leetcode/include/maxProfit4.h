#pragma once
//https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-iv/
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
	int maxProfit(int k, vector<int>& prices) {
		vector<int> pp;
		int p = 0;
		int n = prices.size();
		int jj = -1;
		for (int i = 1; i < n; i++) {
			p = prices[i] - prices[i - 1];
			if (jj == -1) { pp.push_back(p); jj++; }
			else if (pp[jj] >= 0 && p >= 0) { pp[jj] += p; }
			else if (pp[jj] <= 0 && p <= 0) { pp[jj] += p; }
			else { pp.push_back(p); jj++; }
		}
		n = pp.size();
		if (k >= (n + 1) / 2) {
			int ans = 0;
			if (n == 0) { return ans; }
			int i;
			if (pp[0] > 0) { i = 0; }
			else { i = 1; }
			while (i < n) {
				ans += pp[i];
				i += 2;
			}
			return ans;
		}
		k = min(k, (n + 1) / 2);
		vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));
		vector<vector<int>> dp2(n + 1, vector<int>(k + 1, 0));
		int ans = 0;
		for (int i = 1; i <= n; i++) {
			p = pp[i - 1];
			for (int j = 1; j <= k && j <= i; j++) {
				dp[i][j] = max(dp[i - 1][j], dp2[i - 1][j - 1]) + p;
				dp2[i][j] = max(dp2[i - 1][j], dp[i][j]);
			}
		}
		ans = dp2[n][k];
		return ans;
	}
};

