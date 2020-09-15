#include"leetcode.h"

#include "tree/BITree_3.h"
using namespace lt::tree;
class Solution {
public:
	int countRangeSum(vector<int>& nums, int lower, int upper) {
		int n = nums.size();
		BITree_3 bitree;
		bitree.init(n);
		for (int i = 0; i < n; i++) {
			bitree.updateBITree(i,nums[i]);
		}

		int ans = 0;
		long long value;
		for (int i = 0; i < n; i++) {
			for (int j = i; j < n; j++) {
				value = bitree.getSum(j) - bitree.getSum(i-1);
				if (value >= lower && value <= upper) { ans++; }
			}
		}
		return ans;
	}
};

//int main()
//{
//	Solution s;
//	vector<int> matrix{
//3,-4,-1,0
//	};
//	int ans = s.countRangeSum(matrix,-1,0);
//	cout << ans;
//	system("PAUSE");
//
//	return 0;
//	 
//}