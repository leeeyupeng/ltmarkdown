#pragma once
//https://leetcode-cn.com/problems/redundant-connection-ii/
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
	vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
		int n = edges.size();
		{
			vector<int> vParent(n + 1, -1);
			for (int i = 0; i < n; i++) {
				if (vParent[edges[i][1]] == -1) {
					vParent[edges[i][1]] = i;
				}
				else
				{
					int j = vParent[edges[i][1]];
					vector<int> temp;
					temp = edges[n - 1];
					edges[n - 1] = edges[i];
					edges[i] = temp;

					temp = edges[n - 2];
					edges[n - 2] = edges[j];
					edges[j] = temp;
					break;
				}
			}
		}

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