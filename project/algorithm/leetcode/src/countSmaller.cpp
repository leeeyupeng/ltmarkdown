#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
	vector<int> countSmaller(vector<int>& nums) {
		int n = nums.size();
		vector<int> res = nums;
		for (int i = 0; i < n; i++) {
			res[i] = 0;
			for (int j = i + 1; j < n; j++) {
				if (nums[i] > nums[j]) { res[i] ++; }
			}
		}
		return res;
	}
};