#pragma once
//https://leetcode-cn.com/problems/pile-box-lcci/
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
	int pileBox(vector<vector<int>>& box) {
		int n = box.size();
		vector<int> vw,vd,vh;
		for (int i = 0; i < n; i++) {
			vw.push_back(box[i][0]);
			vd.push_back(box[i][1]);
			vh.push_back(box[i][2]);
		}
		sort(vw.begin(), vw.end());
		sort(vd.begin(), vd.end());
		sort(vh.begin(), vh.end());
		unordered_map<int, int> mapw, mapd, maph;

		mapw.insert({vw[0],1});
		int index = 1;
		for (int i = 1; i < n; i++) {
			if (vw[i] != vw[i - 1]) { mapw.insert({ vw[i],++index }); }
		}

		mapd.insert({ vd[0],1 });
		index = 1;
		for (int i = 1; i < n; i++) {
			if (vd[i] != vd[i - 1]) { mapd.insert({ vd[i],++index }); }
		}

		maph.insert({ vh[0],1 });
		index = 1;
		for (int i = 1; i < n; i++) {
			if (vh[i] != vh[i - 1]) { maph.insert({ vh[i],++index }); }
		}

		int nw, nd, nh;
		nw = mapw.size();
		nd = mapd.size();
		nh = maph.size();

		vector<vector<vector<int>>> dp(nw+1, vector<vector<int>>(nd+1, vector<int>(nh+1,0)));
		int indexw, indexd, indexh;

		for (int iw = 1; iw <= nw; iw++) {
			for (int id = 1; id <= nd; id++) {
				for (int ih = 1; ih <= nh; ih++) {

					for (int iw2 = 1; iw2 < iw; iw2++) {
						for (int id2 = 1; id2 < id; id2++) {
							for (int ih2 = 1; ih2 < ih; ih2++) {
								dp[iw][id][ih] = max(dp[iw][id][ih], dp[iw2][id2][ih2]);
							}
						}
					}
					for (int i = 0; i < n; i++) {
						indexw = mapw[box[i][0]];
						indexd = mapd[box[i][1]];
						indexh = maph[box[i][2]];
						if (indexw <= iw && indexd <= id&&indexh <= ih) {
							dp[iw][id][ih] = max(dp[iw][id][ih], box[i][2] + dp[indexw - 1][indexd - 1][indexh - 1]);
						}
					}
				}
			}

		}
		int ans = 0;
		ans += dp[nw][nd][nh];
		return ans;
	}
};
