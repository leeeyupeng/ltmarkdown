#pragma once
//https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-ii/
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
		int ans = 0;
		int p = 0; 
		for (int i = 1; i < n; i++) {
			p=(prices[i] - prices[i - 1]);
			ans = p > 0 ? p + ans : ans;
		}
		return ans;
	}
};
