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
using namespace std;

class Solution {
public:
	int singleNumber(vector<int>& nums) {
		unordered_map<int,int> us;
		int n = nums.size();
		for (int i = 0; i < n; i++) {
			us[nums[i]]++;
		}
		unordered_map<int, int>::iterator ite;
		for (ite = us.begin(); ite != us.end(); ite++) {
			if (ite->second == 1) { return ite->first; }
		}
		return 0;
	}
};