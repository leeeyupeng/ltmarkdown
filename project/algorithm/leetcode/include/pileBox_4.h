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

bool cmp(const vector<int>& a, const vector<int>& b) {
	return a[0] + a[1] + a[2] < b[0] + b[1] + b[2];
}
class Solution {
private:
	int n;
	unordered_map<long long, int> mapmemory;
	int DFS(vector<vector<int>>& box, int index) {
		int w, d, h;
		long long k;
		if (index < n) {
			w = box[index][0];
			d = box[index][1];
			h = box[index][2];
			k = ((long long)w) * 10000 * 10000 + d * 10000 + h;
			if (mapmemory.find(k) != mapmemory.end()) {
				return  mapmemory[k];
			}
		}
		else {
			w = INT32_MAX;
			d = INT32_MAX;
			h = INT32_MAX;
		}
		int iw, id, ih;
		int ansh = 0;
		int htemp;
		int iiw = 0, iid = 0, iih = 0;
		for (int i = index - 1; i >= 0; i--) {
			iw = box[i][0];
			id = box[i][1];
			ih = box[i][2];
			if (iw > iiw || id > iid || ih > iih) {
				if (iw < w&&id < d&&ih < h) {
					htemp = DFS(box, i);
					ansh = max(ansh, htemp + ih);
					iiw = iw, iid = id, iih = ih;
				}
			}
		}
		if (index < n) {
			mapmemory.insert({ k, ansh });
		}
		return ansh;
	}
public:
	int pileBox(vector<vector<int>>& box) {
		n = box.size();
		sort(box.begin(), box.end(), cmp);
		int ans = DFS(box, n);
		return ans;
	}
};

