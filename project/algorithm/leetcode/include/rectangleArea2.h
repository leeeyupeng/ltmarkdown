#pragma once
#include <vector>
#include <map>
#include <set>
#include <stack>
#include<string>
#include<algorithm>
#include "tree/SegmentTree.h"
using namespace std;
using namespace tree;
//https://leetcode-cn.com/problems/rectangle-area-ii/
//ɨ�����㷨
class Solution {
public:
	int sortinsert(vector<int>& v,int i,int j, int value) {
		if (i == j) { return i; }
		if (v[(i+j) >> 1] <= value) {
			return sortinsert(v,((i + j) >> 1) + 1, j, value);
		}
		else
		{
			return sortinsert(v,0,((i + j) >> 1), value);
		}
	}
	int sortinsert2(vector<vector<int>>& v, int i, int j, vector<vector<int>>& rectangles,int value) {
		if (i == j) { return i; }
		if (v[(i + j) >> 1][0] == 0 && rectangles[v[(i + j) >> 1][1]][0] <= value) {
			return sortinsert2(v, ((i + j) >> 1) + 1, j, rectangles,value);
		}
		else if (v[(i + j) >> 1][0] == 1 && rectangles[v[(i + j) >> 1][1]][2] <= value) {
			return sortinsert2(v, ((i + j) >> 1) + 1, j, rectangles,value);
		}
		else
		{
			return sortinsert2(v, 0, ((i + j) >> 1), rectangles,value);
		}
	}
	int rectangleArea(vector<vector<int>>& rectangles) {
		vector<int> vx;
		vector<int> vy;
		vector<vector<int>> vsegment;
		int i, j, k;
		for (i = 0; i < rectangles.size(); i++) {
			j = sortinsert(vx, 0, vx.size(), rectangles[i][0]);
			if (j == 0 || vx[j - 1] < rectangles[i][0]) { vx.insert(vx.begin() + j, rectangles[i][0]); }
			j = sortinsert(vy, 0, vy.size(), rectangles[i][1]);
			if (j == 0 || vy[j - 1] < rectangles[i][1]) { vy.insert(vy.begin() + j, rectangles[i][1]); }
			j = sortinsert(vx, 0, vx.size(), rectangles[i][2]);
			if (j == 0 || vx[j - 1] < rectangles[i][2]) { vx.insert(vx.begin() + j, rectangles[i][2]); }
			j = sortinsert(vy, 0, vy.size(), rectangles[i][3]);
			if (j == 0 || vy[j - 1] < rectangles[i][3]) { vy.insert(vy.begin() + j, rectangles[i][3]); }
		}
		for (i = 0; i < rectangles.size(); i++) {
			j = sortinsert2(vsegment,0,vsegment.size(), rectangles,rectangles[i][0]);
			vsegment.insert(vsegment.begin() + j, {0,i});

			j = sortinsert2(vsegment, 0, vsegment.size(), rectangles,rectangles[i][2]);
			vsegment.insert(vsegment.begin() + j, { 1,i });
		}

		vector<int> svy;
		map<int, int> map;
		for (i = 1; i < vy.size(); i++) {
			svy.push_back(vy[i]-vy[i-1]);
			map.insert({ vy[i - 1] ,i-1});
		}
		svy.push_back(0);
		map.insert({vy[i-1],i-1});
		long long ans = 0;
		SegmentTree st(0, svy.size()-1, svy);
		i = 0;
		j = 0;
		while (i < vx.size() - 1) {
			int x = vx[i];
			while (j < vsegment.size()) {
				if (vsegment[j][0] == 0) {
					if (rectangles[vsegment[j][1]][0] > x) { break; }
					st.Insert(1, map[rectangles[vsegment[j][1]][1]], map[rectangles[vsegment[j][1]][3]]-1);
				}
				else if (vsegment[j][0] == 1) {
					if (rectangles[vsegment[j][1]][2] > x) { break; }
					st.Delete(1, map[rectangles[vsegment[j][1]][1]], map[rectangles[vsegment[j][1]][3]]-1);
				}
				j++;
			}
			long long value = st.GetValue(1, 0, svy.size() - 1);
			ans += value * (vx[i+1] - vx[i]) % (1000000000 + 7);
			ans %= (1000000000 + 7);
			i++;
		}
		return ans;
	}
};
