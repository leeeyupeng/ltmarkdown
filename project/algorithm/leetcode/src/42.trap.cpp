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
	int trap(vector<int>& height) {
		int i = 0;
		int j = height.size() - 1;

		int left = 0, right = 0;
		int ans = 0;
		while (i < j) {
			if (left <= right) {  left = max(height[i], left); ans += left - height[i]; i++; }
			else {  right = max(height[j], right); ans += right - height[j]; j--; }
		}
		ans += left + right;
		return ans;
	}
};