#include"leetcode.h"

#include "tree/BITree_2.h"
using namespace lt::tree;

class Solution {
public:
	vector<int> countSmaller(vector<int>& nums) {
		int n = nums.size();
		vector<int> res = nums;
		BITree bitree;
		for (int i = n - 1; i >= 0; i--) {
			res[i] = bitree.getSum(nums[i] - 1);
			bitree.add(nums[i]);
		}
		return res;
	}
};