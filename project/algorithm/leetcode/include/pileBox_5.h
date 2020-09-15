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
	return a[0] + a[1] + a[2] < b[0] + b[1] + b[2];
}
class Solution {
public:
	int pileBox(vector<vector<int>>& box) {
		int n = box.size();
		sort(box.begin(), box.end(), cmp);
		int ans = 0;
		vector<int> dp(n + 1, 0);
		for (int i = 0; i < n; i++) {
			dp[i] = box[i][2];
			for (int j = i - 1; j >= 0; j--) {
				if (box[i][0] > box[j][0] && box[i][1] > box[j][1] && box[i][2] > box[j][2]) {
					dp[i] = max(dp[i], dp[j] + box[i][2]);
				}
			}
			ans = max(ans, dp[i]);
		}
		return ans;
	}
};