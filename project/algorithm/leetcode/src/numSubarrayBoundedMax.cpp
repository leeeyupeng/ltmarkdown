#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	int numSubarrayBoundedMax(vector<int>& A, int L, int R) {
		int ans = 0;
		int n = A.size();
		int imax = 0;
		for (int i = 0; i < n; i++) {
			for (int j = i; j < n; j++) {
				imax = 0;
				for (int k = i; k <= j; k++) {
					imax = max(imax,A[k]);
				}
				if (imax >= L && imax <= R) { ans++; }
			}
		}
		return ans;
	}
};