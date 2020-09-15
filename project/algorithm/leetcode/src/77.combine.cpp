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
	int k;
	vector<vector<int>> ans;
	vector<int> path;
	void dfs(int index,int count) {
		if (count == k) { ans.push_back(path); return; }
		path.push_back(index);
		dfs(index + 1, count + 1);
		path.pop_back();
		if (count + n - index + 1 > k) {
			dfs(index+1, count);
		}
	}
public:
	vector<vector<int>> combine(int n, int k) {
		this->n = n;
		this->k = k;
		dfs(1,0);
		return ans;
	}
};