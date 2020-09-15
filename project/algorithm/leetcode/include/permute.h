#pragma once
//https://leetcode-cn.com/problems/permutations/
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
	vector<bool> vflag;
	vector<int> vdfs;
	vector<vector<int>> ans;
	void DFS(vector<int>& nums,int index) {
		if (index == n) { ans.push_back(vdfs); return; }
		for (int i = 0; i < n; i++) {
			if (vflag[i] == false) {
				vflag[i] = true;
				vdfs[index] = nums[i];
				DFS(nums, index + 1);
				vflag[i] = false;
			}
		}
	}
public:
	vector<vector<int>> permute(vector<int>& nums) {
		n = nums.size();
		sort(nums.begin(), nums.end());
		vflag.insert(vflag.begin(),n,false);
		vdfs.insert(vdfs.begin(), n, 0);
		DFS(nums,0);
		return ans;
	}
};