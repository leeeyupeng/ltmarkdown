#pragma once
#include <iostream>
#include <stack>
#include <queue>
using namespace std;
namespace lt {
	class UnionFindSet {
	private:
		int N;
		vector<int> v;
	public:
		UnionFindSet(int n) {
			N = n;
			v = vector<int>(N);
			for (int i = 0; i < N; i++) {
				v[i] = i;
			}
		}
		int Find(int i) {
			return v[i];
		}

		void Union(int i, int j) {
			int si = v[i];
			int sj = v[j];
			if (si == sj) { return; }
			for (int k = 0; k < N; k++) {
				if (v[k] == sj) { v[k] = si; }
			}
		}

		bool connected(int i, int j) {
			return v[i] == v[j];
		}
	};
}