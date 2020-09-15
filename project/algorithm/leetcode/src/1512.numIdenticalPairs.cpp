#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <queue>
#include<string>
#include<map>
#include<unordered_map>
#include<unordered_set>
#include<stack>

#include<cmath>
using namespace std;

class Solution {
public:
	int numIdenticalPairs(vector<int>& nums) {
		int n = nums.size();
		int ans = 0;
		for (int i = 0; i < n; i++) {
			for (int j = i + 1; j < n; j++) {
				if (nums[i] == nums[j]) { ans++; }
			}
		}
		return ans;
	}
};