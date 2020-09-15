#pragma once
#include <vector>
#include <map>
#include <set>
#include <stack>
#include<string>
#include<algorithm>
using namespace std;
//https://leetcode-cn.com/problems/rectangle-area-ii/
//
class Solution {
public:
	int rectangleArea(vector<vector<int>>& rectangles) {
		vector<int> vx;
		vector<int> vy;
		int i, j,k;
		for (i = 0; i < rectangles.size(); i++) {
			for (j = 0; j < vx.size(); j++) {
				if (vx[j] > rectangles[i][0]) { break; }
			}
			if (j == 0 || vx[j-1] < rectangles[i][0]) {vx.insert(vx.begin() + j, rectangles[i][0]);}

			for (j = 0; j < vy.size(); j++) {
				if (vy[j] > rectangles[i][1]) { break; }
			}
			if (j == 0 || vy[j - 1] < rectangles[i][1]) { vy.insert(vy.begin() + j, rectangles[i][1]); }

			for (j = 0; j < vx.size(); j++) {
				if (vx[j] > rectangles[i][2]) { break; }
			}
			if (j == 0 || vx[j - 1] < rectangles[i][2]) { vx.insert(vx.begin() + j, rectangles[i][2]); }

			for (j = 0; j < vy.size(); j++) {
				if (vy[j] > rectangles[i][3]) { break; }
			}
			if (j == 0 || vy[j - 1] < rectangles[i][3]) { vy.insert(vy.begin() + j, rectangles[i][3]); }
		}

		long long ans = 0;
		for (i = 1; i < vx.size(); i++) {
			for (j = 1; j < vy.size(); j++) {
				for (k = 0; k < rectangles.size(); k++) {
					if (vx[i - 1] >= rectangles[k][0]
						&& vy[j - 1] >= rectangles[k][1]
						&& vx[i] <= rectangles[k][2]
						&& vy[j] <= rectangles[k][3]) {
						ans += (long long)(vx[i] - vx[i - 1]) * (long long)(vy[j] - vy[j - 1]) % (1000000000 + 7);
						ans %= (1000000000 + 7);
						break;
					}
				}
			}
		}
		ans %= (1000000000 + 7);
		return ans;
	}
};