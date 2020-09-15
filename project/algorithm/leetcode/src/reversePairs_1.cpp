#include"leetcode.h"
namespace reversePairs {
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

void reversePairs::tree::BITree::add(long long val) {
	long long index = (long long)val + ((long long)INT_MAX) + 1;
	while (index < ((long long)INT_MAX << 1)) {
		map[index] ++;
		index = index + (index & (-index));
	}
}
int reversePairs::tree::BITree::getSum(long long val) {
	long long index = (long long)val + ((long long)INT_MAX) + 1;
	int result = 0;
	while (index > 0) {
		result += map[index];
		index = index - (index & (-index));
	}
	return result;
}
using namespace reversePairs::tree;
class Solution {
public:
	int reversePairs(vector<int>& nums) {
		int n = nums.size();
		int ans = 0;
		BITree bitree;
		long long half = 0;
		for (int i = 0; i < n; i++) {
			half = ((long long)nums[i])  + ((long long)nums[i]);
			if (half > INT_MAX) { }
			else { ans += i - bitree.getSum(half); }
			bitree.add(nums[i]);
		}
		return ans;
	}
};

//int main()
//{
//	Solution s;
//	vector<int> matrix{
//		2147483647,2147483647,2147483647,2147483647,2147483647,2147483647
//};
//	int ans = s.reversePairs(matrix);
//	cout << ans;
//	system("PAUSE");
//
//	return 0;
//
//}