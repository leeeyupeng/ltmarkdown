#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <queue>
#include<string>
#include<map>
#include<unordered_map>
using namespace std;

#define MAX 505
class Solution {
private:
	bool dp[MAX];
	vector<vector<int>> path[MAX];
public:
	vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
		int n = candidates.size();
		sort(candidates.begin(),candidates.end());
		for (int i = 1; i <= target; i++) {
			dp[i] = false;
		}
		dp[0] = true;
		path[0].push_back({});
		for (int i = 0; i < n; i++) {
			for (int t = candidates[i]; t <= target; t++) {				
				if (dp[t - candidates[i]] == true) {
					for (int k = 0; k < path[t - candidates[i]].size(); k++) {
						path[t].push_back(path[t - candidates[i]][k]);
						path[t].back().push_back(candidates[i]);
					}
				}
				dp[t] = dp[t] || dp[t - candidates[i]];
			}
		}
		return path[target];
	}
};

//int main()
//{
//	Solution s;
//	vector<int> nums{
//2,3,5,6,4,1
//	};
//	int k = 8;
//	vector<vector<int>> ans = s.combinationSum(nums,k);
//	system("PAUSE");
//	return 0;
//}