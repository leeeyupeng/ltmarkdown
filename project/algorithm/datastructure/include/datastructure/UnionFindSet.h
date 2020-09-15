#pragma once
#include <iostream>
#include <stack>
#include <queue>
using namespace std;
namespace lt {
	class UnionFindSet {
	private:
		vector<int> v;
		vector<int> vs;
	public:
		UnionFindSet(int n) {
			v = vector<int>(n);
			vs = vector<int>(n);
			for (int i = 0; i < n; i++) {
				v[i] = i;
				vs[i] = 1;
			}
		}
		int Find(int i) {
			while (v[i] != i) {
				v[i] = v[v[i]];
				i = v[i];
			}
			return i;
		}

		void Union(int i, int j) {
			int si = Find(i);
			int sj = Find(j);
			if (si == sj) { return; }
			if (vs[si] < vs[sj]) { v[si] = sj; vs[sj] += vs[si]; }
			else if (vs[si] == vs[sj]) { v[sj] = si; vs[si] += vs[sj]; }
			else { v[sj] = si; vs[si] += vs[sj]; }
		}

		bool connected(int i, int j) {
			return Find(i) == Find(j);
		}
	};
}