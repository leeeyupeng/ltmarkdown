#pragma once
//https://leetcode-cn.com/problems/erect-the-fence/
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
	if (a[1] == b[1]) { return a[0] < b[0]; };
	return a[1] < b[1];
}
class Solution {
public:
	vector<vector<int>> outerTrees(vector<vector<int>>& points) {
		int n = points.size();
		sort(points.begin(), points.end(), cmp);
		vector<int> left;
		int index = -1;
		for (int i = 0; i < n; i++) {
			if (i > 0 && points[i-1][1] == points[i][1]) { continue; }
			while (index > 0
				&& (points[i][1] - points[left[index]][1]) * (points[i][0] - points[left[index - 1]][0])
				> (points[i][1] - points[left[index - 1]][1]) * (points[i][0] - points[left[index]][0])) {
				left.pop_back();
				index--;
			}
			left.push_back(i);
			index++;
		}

		index = -1;
		vector<int> right;
		for (int i = 0; i < n; i++) {
			if (i < n - 1 && points[i][1] == points[i+1][1]) { continue; }
			while (index > 0
				&& (points[i][1] - points[right[index]][1]) * (points[i][0] - points[right[index - 1]][0])
				< (points[i][1] - points[right[index - 1]][1]) * (points[i][0] - points[right[index]][0])) {
				right.pop_back();
				index--;
			}
			right.push_back(i);
			index++;
		}

		vector<vector<int>> vans;
		set<int> sans;
		for (int i = left[0]; i <= right[0]; i++) {
			if (sans.find(i) == sans.end()) {
				sans.insert(i);
				vans.push_back(points[i]);
			}
		}

		for (int i = 1; i < left.size()-1; i++) {
			if (sans.find(left[i]) == sans.end()) {
				sans.insert(left[i]);
				vans.push_back(points[left[i]]);
			}
		}
		for (int i = 1; i < right.size()-1; i++) {
			if (sans.find(right[i]) == sans.end()) {
				sans.insert(right[i]);
				vans.push_back(points[right[i]]);
			}
		}

			for (int i = left[left.size() - 1]; i <= right[right.size() - 1]; i++) {
				if (sans.find(i) == sans.end()) {
					sans.insert(i);
					vans.push_back(points[i]);
				}
		}
		return vans;
	}
};