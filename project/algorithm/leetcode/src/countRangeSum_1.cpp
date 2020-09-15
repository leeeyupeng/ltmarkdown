#include"leetcode.h"
namespace lt {
	namespace tree
	{
		//BinaryIndexedTree
		class BITree {
		private:
			unordered_map<long long, int> map;
		public:
			void add(long long val);
			//void insertBITree(int val);
			int getSum(long long val);
		};
	}
}

void lt::tree::BITree::add(long long val) {
	long long index = (long long)val + ((long long)INT_MAX << 16) + 1;
	while (index < ((long long)INT_MAX << 18)) {
		map[index] ++;
		index = index + (index & (-index));
	}
}
int lt::tree::BITree::getSum(long long val) {
	long long index = (long long)val + ((long long)INT_MAX << 16) + 1;
	int result = 0;
	while (index > 0) {
		result += map[index];
		index = index - (index & (-index));
	}
	return result;
}

using namespace lt::tree;
class Solution {
public:
	int countRangeSum(vector<int>& nums, int lower, int upper) {
		int n = nums.size();
		BITree bitree;
		long long presum = 0;
		int ans = 0;
		for (int i = 0; i < n; i++) {
			bitree.add(presum);
			presum += nums[i];
			ans += bitree.getSum(presum - lower)- bitree.getSum(presum - upper - 1);			
		}
		return ans;
	}
};

//int main()
//{
//	Solution s;
//	vector<int> matrix{
//-2147483647,0,-2147483647,2147483647
//	};
//	int ans = s.countRangeSum(matrix,-564,3864);
//	cout << ans;
//	system("PAUSE");
//
//	return 0;
//	 
//}