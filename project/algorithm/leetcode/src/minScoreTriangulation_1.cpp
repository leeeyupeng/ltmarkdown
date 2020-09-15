#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define MAX 100000000
#define NMAX 50
class Solution {
private:
	int n;
	int dp[NMAX + 1][NMAX + 1];
public:
	int minScoreTriangulation(vector<int>& A) {
		n = A.size();
		for (int i = 0; i < n; i++) {
			dp[i][i] = 0;
			dp[i][i + 1] = 0;
		}
		for (int s = 2; s < n; s++) {
			for (int i = 0; i < n - s; i++) {
				int j = i + s;
				dp[i][j] = MAX;
				for (int k = i + 1; k < j; k++) {
					dp[i][j] = min(dp[i][j], dp[i][k] + A[i] * A[k] * A[j] + dp[k][j]);
				}
			}
		}

		return dp[0][n-1];
	}
};

//#include <algorithm>
//#include <functional>
//int main()
//{
//	Solution s;
//	vector<int> matrix{
//1, 3, 1, 4, 1, 5,
//91, 3, 41, 44, 1, 5,
//21, 53, 31, 34, 1, 5,
//91, 83, 1, 4, 1, 5,
//
//	};
//	using std::placeholders::_1;
//	auto minScoreTriangulation = std::bind(&Solution::minScoreTriangulation, &s, _1);
//	int ans = minScoreTriangulation(matrix);
//	cout << ans;
//	system("PAUSE");
//
//	return 0;
//	 
//}