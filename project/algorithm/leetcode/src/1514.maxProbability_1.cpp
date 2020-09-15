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

#include<cmath>
using namespace std;


class Solution {
public:
	double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
		int en = edges.size();

		vector<double> v(n);
		for (int i = 0; i < n; i++) { v[i] = 0; }
		vector<bool> vvisit(n);
		for (int i = 0; i < n; i++) { vvisit[i] = false; }
		v[start] = 1;
		int key;
		double ans = 0;
		int icount = n;
		int top;
		int a, b;
		while (icount > 0) {
			icount--;
			top = -1;
			for (int i = 0; i < n; i++) {
				if (vvisit[i] == false) {
					if (top == -1 || v[top] < v[i]) {
						top = i;
					}
				}
			}

			vvisit[top] = true;
			if (top == end) {
				ans = v[top]; break;
			}

			for (int i = 0; i < en; i++) {
				a = edges[i][0];
				b = edges[i][1];
				if (a == top && vvisit[b] == false) {
					v[b] = max(v[b], v[top] * succProb[i]);
				}
				else if (b == top && vvisit[a] == false) {
					v[a] = max(v[a], v[top] * succProb[i]);
				}

			}
		}
		return ans;
	}
};