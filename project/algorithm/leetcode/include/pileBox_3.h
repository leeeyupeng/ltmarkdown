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
	int ans;
	unordered_map<int, int> mapmemory;
	unordered_map<int,int> maph;
	int DFS(vector<vector<int>>& box,int index,int anshh) {
		int w, d, h;
		int k;
		if (index < n) {
			w = box[index][0];
			d = box[index][1];
			h = box[index][2];
			k = index;
			if (mapmemory.find(k) != mapmemory.end()) {
				return  mapmemory[k];
			}
		}
		else{
			w = INT32_MAX;
			d = INT32_MAX;
			h= INT32_MAX;
		}
		int iw, id, ih;
		int ansh = 0;
		int htemp;
		int iiw=0, iid=0, iih=0;
		for (int i = index-1; i >= 0; i--) {
			iw = box[i][0];
			id = box[i][1];
			ih = box[i][2];
			if (iw > iiw || id > iid || ih > iih) {
				if (iw < w&&id < d&&ih < h) {
					if (maph[ih] + anshh > ans) {
						htemp = DFS(box, i, anshh + ih);
						ansh = max(ansh, htemp + ih);
					}
					iiw = iw, iid = id, iih = ih;
				}
			}
		}
		if (index < n) {
			mapmemory.insert({ k, ansh });
		}
		ans = max(ans,ansh);
		return ansh;
	}
public:
	int pileBox(vector<vector<int>>& box) {
		n = box.size();
		sort(box.begin(),box.end(), cmp);
		vector<int> vh(n, 0);
		for (int i = 0; i < n; i++) {
			vh[i] = box[i][2];
		}
		sort(vh.begin(),vh.end());
		maph.insert({vh[0],vh[0]});
		for (int i = 1,j = 0; i < n; i++) {
			if (vh[i] != vh[j]) {
				maph.insert({ vh[i],maph[vh[j]]+vh[i] });
				j = i;
			}
		}
		ans = 0;
		ans = DFS(box,n,0);
		return ans;
	}
};
