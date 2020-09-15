#pragma once
//https://leetcode-cn.com/problems/permutations-ii/
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
	int n;
	vector<int> vflag;
	vector<int> vdfs;
	vector<vector<int>> ans;
	void DFS(vector<int>& nums, int index) {
		if (index == n) { ans.push_back(vdfs); return; }
		for (int i = 0; i < n; i++) {
			if (vflag[i] > 0) {
				vflag[i] --;
				vdfs[index] = nums[i];
				DFS(nums, index + 1);
				vflag[i] ++;
			}
		}
	}
public:
	vector<vector<int>> permuteUnique(vector<int>& nums) {
		n = nums.size();
		vflag.insert(vflag.begin(), n, 0);
		vdfs.insert(vdfs.begin(), n, 0);
		sort(nums.begin(), nums.end());
		for (int i = 0,j=0; i < n; i++) {
			if (nums[i] == nums[j]) { vflag[j]++; }
			else { vflag[i]++; j = i; }
		}

		DFS(nums, 0);
		return ans;
	}
};