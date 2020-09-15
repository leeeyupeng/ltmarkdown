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

using namespace std;
class Solution {
public:
	vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
		int n = edges.size();	
		vector<bool> vans(n,false);
		for (int k = 0; k < n; k++) {
			int root = edges[k][0];
			vector<bool> vFlagNode(n + 1, false);
			vector<bool> vFlagEdge(n, false);
			vFlagNode[root] = true;
			int nodecount = 1;
			for (int i = k; i < n;) {
				if (vFlagEdge[i] == false) {
					if (vFlagNode[edges[i][1]] == true) {
						break;
					}
					if (vFlagNode[edges[i][0]] == true
						&& vFlagNode[edges[i][1]] == false) {
						vFlagEdge[i] = true;
						vFlagNode[edges[i][1]] = true;
						i = 0;
						nodecount++;
						continue;
					}
					i++;
				}
			}
			if(nodecount != n) { continue; }

			for (int i = 0; i < n; i++) {
				if (vFlagEdge[i] == false) {
					vans[i] = true;
					break;
				}
			}
		}
 		for (int i = n - 1; i >= 0; i--) {
			if (vans[i] == true) { return edges[i]; }
		}
		return edges[n - 1];
	}
};