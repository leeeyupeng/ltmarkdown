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
private:
	int n;
	int target;
	vector<int> path;
	vector<vector<int>> ans;
	vector<bool> visit;
	void dfs(vector<int>& candidates, int index,int sums) {
		if (sums == target) { ans.push_back(path); return; }
		
		if (index < n && sums + candidates[index] <= target) {
			if (index == 0 || candidates[index - 1] != candidates[index] || (candidates[index - 1] == candidates[index] && visit[index - 1] == true)) {
				path.push_back(candidates[index]);
				visit[index] = true;
				dfs(candidates, index + 1, sums + candidates[index]);
				visit[index] = false;
				path.pop_back();
			}

			dfs(candidates, index + 1, sums);
		}
	}
public:
	vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
		this->n = candidates.size();
		this->target = target;
		sort(candidates.begin(),candidates.end());
		visit = vector<bool>(n);
		for (int i = 0; i < n; i++) {
			visit[i] = false;
		}
		dfs(candidates,0,0);
		return ans;
	}
};