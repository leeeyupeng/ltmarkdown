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
		heights.insert(heights.begin(), 1, 0);
		heights.push_back(0);
		int n = heights.size();
		stack<int> s;
		int ans = 0;
		int height = 0;
		for (int i = 0; i < n; i++) {
			if (s.empty()) { s.push(i); }
			else if (heights[s.top()] <= heights[i]) { s.push(i); }
			else {
				while (!s.empty() && heights[s.top()] > heights[i]) {
					height = heights[s.top()];
					s.pop();
					ans = max(ans, height * (i - s.top() - 1));
				}
				s.push(i);
			}
		}
		return ans;
	}
};