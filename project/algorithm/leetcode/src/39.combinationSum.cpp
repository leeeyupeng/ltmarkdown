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
	bool binary(vector<int>& candidates, int target,int n,int value, vector<int>& vsums) {
		int index = 0;
		int sums = 0;
		while (index < n &&value!=0) {
			if ((value & 0x1) == 0x1) { vsums.push_back(candidates[index]); sums += candidates[index]; }
			index++;
			value = value>>1;
		}
		return sums == target;
	}
public:
	vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
		int n = candidates.size();
		sort(candidates.begin(),candidates.end());
		vector<int> vsums;
		vector<vector<int>> ans;
		for (int i = 1; i < (1 << n); i++) {
			if (binary(candidates, target, n, i, vsums)) {
				ans.push_back(vsums);				
			}
			vsums.clear();
		}
		return ans;
	}
};

//int main()
//{
//	Solution s;
//	vector<int> nums{
//2,3,6,7
//	};
//	int k = 7;
//	vector<vector<int>> ans = s.combinationSum(nums,k);
//	system("PAUSE");
//	return 0;
//}