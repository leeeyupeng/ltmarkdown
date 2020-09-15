#pragma once
#include <iostream>
#include <stack>
#include <queue>
using namespace std;
namespace lt {
	class UnionFindSet {
	private:
		vector<int> v;
	public:
		UnionFindSet(int n) {
			v = vector<int>(n);
			for (int i = 0; i < n; i++) {
				v[i] = i;
			}
		}
		int Find(int i) {
			while (v[i] != i) { 
				v[i] = v[v[i]]; 
				i = v[i]; }
			return i;
		}

		void Union(int i, int j) {
			v[Find(j)] = Find(i);
		}

		bool connected(int i, int j) {
			return Find(i) == Find(j);
		}
	};
}