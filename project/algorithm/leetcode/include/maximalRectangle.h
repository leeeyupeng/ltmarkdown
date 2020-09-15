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
private:
	int largestRectangleArea(vector<int>& heights) {
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
public:
	int maximalRectangle(vector<vector<char>>& matrix) {
		int n = matrix.size();
		int m = 0;
		if (n > 0) { m = matrix[0].size(); }
		vector<int> heights(m + 2,0);
		int ans = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (matrix[i][j] == '0') { heights[j+1] = 0; }
				else { heights[j+1] = heights[j+1] + 1; }
			}
			ans = max(ans, largestRectangleArea(heights));
		}
		return ans;
	}
};
