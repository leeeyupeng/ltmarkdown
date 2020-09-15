#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <queue>
#include<string>
#include<map>
#include<unordered_map>
using namespace std;

class Solution {
public:
	void wiggleSort(vector<int>& nums) {
		vector<int> numstemp = nums;
		sort(numstemp.begin(), numstemp.end());
		int n = nums.size();
		int i = ((n+1)>>1) - 1;
		int j = n-1;
		int index = 0;
		while (index < n) {
			if (index < n) {
				nums[index++] = numstemp[i--];
			}
			if (index < n) {
				nums[index++] = numstemp[j--];
			}
		}
	}
};