#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#include "tree/BITree.h"
using namespace lt::tree;
//https://leetcode-cn.com/problems/range-sum-query-mutable/

class NumArray {
private:
	BITree bitree;

	vector<int> nums;
public:
	NumArray(vector<int>& nums) {
		int n = nums.size();
		bitree.init(n);

		this->nums = nums;
		for (int i = 0; i < n; i++) {
			bitree.updateBITree(i,nums[i]);
		}

	}

	void update(int i, int val) {
		bitree.updateBITree(i, val - this->nums[i]);
		this->nums[i] = val;
	}

	int sumRange(int i, int j) {
		return bitree.getSum(j) - bitree.getSum(i - 1);
	}
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(i,val);
 * int param_2 = obj->sumRange(i,j);
 */