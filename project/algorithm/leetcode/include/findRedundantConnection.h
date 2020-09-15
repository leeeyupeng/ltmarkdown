#pragma once
//https://leetcode-cn.com/problems/redundant-connection
#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <set>
#include <stack>
#include<string>
#include<algorithm>

#include"datastructure/UnionFindSet.h"

using namespace std;
using namespace lt;
class Solution {
public:
	vector<int> findRedundantConnection(vector<vector<int>>& edges) {
		int n = edges.size();
		UnionFindSet ufs(n + 1);
		for (int i = 0; i < n; i++) {
			if (ufs.connected(edges[i][0], edges[i][1])) {
				return edges[i];
			}
			else {
				ufs.Union(edges[i][0], edges[i][1]);
			}
		}
		return edges[n - 1];
	}
};