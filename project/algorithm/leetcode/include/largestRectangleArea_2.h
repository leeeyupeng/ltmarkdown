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
		int n = heights.size();
		int is, ie;
		int ans = 0;
		for (int i = 0; i < n; i++) {
			is = i - 1;
			ie = i + 1;
			while (is >= 0 && heights[is] >= heights[i]) { is--; }
			while (ie < n && heights[ie] >= heights[i]) { ie++; }
			ans = max(ans,heights[i] * (ie-is - 1));
		}
		return ans;
	}
};