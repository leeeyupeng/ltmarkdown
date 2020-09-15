#include"leetcode.h"

class Solution {
public:
	int reversePairs(vector<int>& nums) {
		int n = nums.size();
		int ans = 0;
		for (int i = 0; i < n; i++) {
			for (int j = i+1; j < n; j++) {
				if ((long long)nums[i] > (long long)nums[j] + (long long)nums[j]) {
					ans++;
				}
			}
		}
		return ans;
	}
};