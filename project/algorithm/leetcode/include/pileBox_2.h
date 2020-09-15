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
private:
	int n;
	unordered_map<int, int> mapw, mapd, maph;
	vector<int> vw, vd, vh;
	int nw, nd, nh;
	int index2w, index2d, index2h;
	int ans = 0;
	unordered_map<long long, int> mapmemory;
	int DFS(vector<vector<int>>& box, int indexw,int indexd,int indexh)
	{
		long long k = ((long long)indexw) * 10000 * 10000 + indexd * 10000 + indexh;
		if (mapmemory.find(k)!= mapmemory.end()) {
			return  mapmemory[k];
		}
		int h = 0;
		int hh = 0;
		for (int i = 0; i < n; i++)
		{
			index2w = mapw[box[i][0]];
			index2d = mapd[box[i][1]];
			index2h = maph[box[i][2]];
			if (index2w < indexw && index2d < indexd && index2h < indexh) {
				hh = DFS(box, index2w,index2d,index2h);
				h = max(h, hh + box[i][2]);
			}
		}		
		mapmemory.insert({ k, h});
		return h;
	}
public:
	int pileBox(vector<vector<int>>& box) {
		n = box.size();
		for (int i = 0; i < n; i++) {
			vw.push_back(box[i][0]);
			vd.push_back(box[i][1]);
			vh.push_back(box[i][2]);
		}
		sort(vw.begin(), vw.end());
		sort(vd.begin(), vd.end());
		sort(vh.begin(), vh.end());


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

		nw = mapw.size();
		nd = mapd.size();
		nh = maph.size();

		ans = DFS(box,nw+2,nd+2,nh+2);
		return ans;
	}
};
