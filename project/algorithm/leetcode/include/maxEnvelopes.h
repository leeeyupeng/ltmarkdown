#pragma once
//https://leetcode-cn.com/problems/russian-doll-envelopes/
#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <set>
#include <stack>
#include<string>
#include<algorithm>
using namespace std;

bool cmp(const vector<int>& a, const vector<int>& b) {
	return a[0] + a[1] < b[0] + b[1];
}
class Solution {
public:
	int maxEnvelopes(vector<vector<int>>& envelopes) {
		int n = envelopes.size();
		sort(envelopes.begin(), envelopes.end(), cmp);
		int ans = 0;
		vector<int> dp(n + 1, 1);
		for (int i = 0; i < n; i++) {
			for (int j = i - 1; j >= 0; j--) {
				if (envelopes[i][0] > envelopes[j][0] && envelopes[i][1] > envelopes[j][1]) {
					dp[i] = max(dp[i], dp[j] + 1);
				}
			}
			ans = max(ans, dp[i]);
		}
		return ans;
	}
};