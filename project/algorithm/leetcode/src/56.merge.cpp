#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <functional>
#include <queue>
#include<string>
#include<map>
#include<unordered_map>
using namespace std;

class Solution {
private:
	bool cmp(vector<int>& a, vector<int>& b) {
		if (a[1] == b[1]) { return a[0] <= b[0]; }
		return a[1] < b[1];
	}
public:
	vector<vector<int>> merge(vector<vector<int>>& intervals) {
		int n = intervals.size();
		if (n <= 0) { return intervals; }
		sort(intervals.begin(), intervals.end(), std::bind(&Solution::cmp, this, std::placeholders::_1, std::placeholders::_2));

		vector<vector<int>> ans;
		vector<int> cur = intervals[0];
		for (int i = 1; i < n; i++) {
			if (cur[1] == intervals[i][1]) {
				cur[0] = min(cur[0], intervals[i][0]);
			}
			else if (cur[1] >= intervals[i][0]) {
				cur[0] = min(cur[0], intervals[i][0]);
				cur[1] = max(cur[1],intervals[i][1]);
			}
			else {
				ans.push_back(cur);
				cur = intervals[i];
			}
		}
		ans.push_back(cur);
		return ans;
	}
};