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
	if (a[0] == b[0]) { return a[1] > b[1]; }
	else { return a[0] < b[0]; }
}
class Solution {
private:
	int Get(vector<int>& tails, int num, int n) {
		int i = 1, j = n;
		int m;
		while (i <= j) {
			m = ((i + j) >> 1);
			if (tails[m] >= num) { j = m - 1; }
			else { i = m + 1; }
		}
		return j;
	}
public:
	int maxEnvelopes(vector<vector<int>>& envelopes) {
		sort(envelopes.begin(), envelopes.end(), cmp);
		int n = envelopes.size();
		int ans = 0;
		vector<int> tails(n + 1, 0);
		int j;
		for (int i = 0; i < n; i++) {
			j = Get(tails, envelopes[i][1], ans);
			tails[j + 1] = envelopes[i][1];
			ans = max(ans, j + 1);
		}
		return ans;
	}
};