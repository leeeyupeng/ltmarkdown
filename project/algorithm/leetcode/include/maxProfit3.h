#pragma once
//https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-iii/
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
	int maxProfit(vector<int>& prices) {
		int n = prices.size();
		vector<int> dp1(n, 0);
		vector<int> dp2(n + 1, 0);
		int p = 0;
		for (int i = 1; i < n; i++) {
			p = (prices[i] - prices[i - 1]);
			dp1[i] = dp1[i - 1] > 0 ? dp1[i - 1] + p : p;
		}
		int maxTemp = 0;
		for (int i = 0; i < n; i++) {
			if (dp1[i] > maxTemp) { maxTemp = dp1[i]; }
			else { dp1[i] = maxTemp; }
		}
		for (int i = n-1; i > 0; i--) {
			p = (prices[i] - prices[i - 1]);
			dp2[i] = dp2[i + 1] > 0 ? dp2[i + 1] + p : p;
		}
		maxTemp = 0;
		for (int i = n-1; i >0; i--) {
			if (dp2[i] > maxTemp) { maxTemp = dp2[i]; }
			else { dp2[i] = maxTemp; }
		}
		int ans = 0;
		for (int i = 0; i < n - 1; i++) {
			ans = max(ans,dp1[i] + dp2[i + 1]);
			ans = max(ans, dp1[i]);
			ans = max(ans, dp2[i + 1]);
		}
		return ans;
	}
};

