#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	int numSubarrayBoundedMax(vector<int>& A, int L, int R) {
		int ans = 0;
		int n = A.size();
		int up = -1;
		int lastmax = -1;
		int curmax = -1;
		for (int i = 0; i < n; i++) {
			if (A[i] < L) { continue; }
			lastmax = curmax; curmax = i;
			ans += (lastmax - up) * (curmax - lastmax);
			if (A[i] > R) {
				up = i; 
			 }
		}
		lastmax = curmax;
		ans += (lastmax - up) * (n - lastmax);
		return ans;
	}
};

//int main()
//{
//	Solution s;
//	vector<int> matrix{
//2,1,4,3
//	};
//	int ans = s.numSubarrayBoundedMax(matrix,2,3);
//	cout << ans;
//	system("PAUSE");
//
//	return 0;
//	 
//}