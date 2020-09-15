#include"leetcode.h"
class Solution {
public:
	vector<vector<int>> threeSum(vector<int>& nums) {
		vector<vector<int>> ans;
		int n = nums.size();
		sort(nums.begin(),nums.end());
		unordered_map<int, int> map;
		for (int i = 0; i < n; i++) {
			map[nums[i]] = i;
		}
		int num;
		for (int i = 0; i < n; i++)
		{
			if (i != 0 && nums[i] == nums[i - 1]) { continue; }
			for (int j = i+1; j < n; j++) 
			{
				if (j != i+1 && nums[j] == nums[j - 1]) { continue; }
				num = 0 - nums[i] - nums[j];
				if (map.find(num) != map.end() && map[num] > j) {
					ans.push_back({ nums[i] , nums[j] , num });
				}
			}
		}
		return ans;
	}
};