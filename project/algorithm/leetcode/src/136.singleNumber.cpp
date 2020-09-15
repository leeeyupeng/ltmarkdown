#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <queue>
#include<string>
#include<map>
#include<unordered_map>
#include<stack>
using namespace std;

class Solution {
public:
	int singleNumber(vector<int>& nums) {
		int ans = 0;
		int n = nums.size();
		for (int i = 0; i < n; i++) {
			ans ^= nums[i];
		}
		return ans;
	}
};