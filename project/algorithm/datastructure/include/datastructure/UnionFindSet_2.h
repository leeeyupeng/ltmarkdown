#pragma once
#include <iostream>
#include <stack>
#include <queue>
using namespace std;
namespace lt {
	class UnionFindSet {
	private:
		vector<int> v;
		vector<int> vd;
	public:
		UnionFindSet(int n) {
			v = vector<int>(n);
			vd= vector<int>(n);
			for (int i = 0; i < n; i++) {
				v[i] = i;
				vd[i] = 1;
			}
		}
		int Find(int i) {
			while (v[i] != i) { i = v[i]; }
			return i;
		}

		void Union(int i, int j) {
			int si = Find(i);
			int sj = Find(j);
			if (si == sj) { return; }
			if (vd[si] < vd[sj]) { v[si] = sj; }
			else if (vd[si] == vd[sj]) { v[sj] = si; vd[si]++; }
			else { v[sj] = si; }
		}

		bool connected(int i, int j) {
			return Find(i) == Find(j);
		}
	};
}