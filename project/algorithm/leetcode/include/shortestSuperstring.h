#pragma once
#include <iostream>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <string>
#include <map>
#include <set>
#include <algorithm>
#include <ctime>
using namespace std;
//https://leetcode-cn.com/problems/find-the-shortest-superstring/
class Solution {
public:
	vector<string> AA;
	int n;
	int maxlength;
	vector<vector<int>> matrix;

	vector<int> vans;
	string ans;
	vector<int> vmaxcount;
	int maxcountall;
	int anscount = INT32_MIN;
	int count = 0;
	void Perm(vector<int>& v, int k, int length, int maxcount)
	{
		if (k == n - 1) {
			if (k != 0) { count += matrix[v[k - 1]][v[k]]; }
			if (anscount >= count) {}
			else {
				anscount = count;
				vans = v;
			}
			if (k != 0) { count -= matrix[v[k - 1]][v[k]]; };
		}
		else if (k == 0) {
			for (int i = k; i < n; i++)
			{
				swap(v[k], v[i]);
				length += AA[v[k]].length();
				maxcount -= vmaxcount[v[k]];
				Perm(v, k + 1, length, maxcount);
				maxcount += vmaxcount[v[k]];
				length -= AA[v[k]].length();
				swap(v[k], v[i]);
			}
		}
		else {
			for (int i = k; i < n; i++)
			{
				swap(v[k], v[i]);
				count += matrix[v[k - 1]][v[k]];
				length += AA[v[k]].length();
				maxcount -= vmaxcount[v[k]];
				if (maxcount + count <= anscount) {
				}
				else {
					Perm(v, k + 1, length, maxcount);
				}
				maxcount += vmaxcount[v[k]];
				length -= AA[v[k]].length();
				count -= matrix[v[k - 1]][v[k]];
				swap(v[k], v[i]);
			}
		}
	}

	string shortestSuperstring(vector<string>& A) {
		vector<int> substring;
		for (int i = 0; i < A.size(); i++) {
			for (int j = 0; j < A.size(); j++) {
				if (i != j && A[i].length() <= A[j].length()) {
					if (A[j].find(A[i]) != string::npos) {
						substring.push_back(i);
						break;
					}
				}
			}
		}
		while (!substring.empty())
		{
			A.erase(A.begin() + substring.back());
			substring.pop_back();
		}
		AA = A;
		n = A.size();

		maxlength = 0;
		for (int i = 0; i < n; i++) { maxlength += A[i].length(); }

		matrix.insert(matrix.begin(), n, {});
		for (int i = 0; i < n; i++) {
			matrix[i].insert(matrix[i].begin(), n, 0);
		}

		int count = 0;
		int k;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (i != j) {
					count = min(A[i].length(), A[j].length());
					while (count > 0)
					{
						for (k = 0; k < count; k++)
						{
							if (A[i][A[i].length() - count + k] == A[j][k]) { continue; }
							else { break; }
						}
						if (k == count) { break; }
						count--;
					}
					matrix[i][j] = count;
				}
			}
		}
		vmaxcount.insert(vmaxcount.begin(), n, 0);

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				vmaxcount[i] = max(vmaxcount[i], matrix[i][j]);
				vmaxcount[j] = max(vmaxcount[j], matrix[i][j]);
			}
		}
		maxcountall = 0;
		for (int i = 0; i < n; i++) {
			maxcountall += vmaxcount[i];
		}

		vector<int> perm(n);
		for (int i = 0; i < n; i++)
		{
			perm[i] = i;
		}
		Perm(perm, 0, 0, maxcountall);


		string s = AA[vans[0]];
		for (int i = 1; i < n; i++) {
			s.append(AA[vans[i]].substr(matrix[vans[i - 1]][vans[i]], AA[vans[i]].length() - matrix[vans[i - 1]][vans[i]]));
		}
		if (ans.empty() || ans.length() > s.length()) { ans = s; }
		return ans;
	}
};