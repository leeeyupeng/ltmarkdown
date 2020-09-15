#include"leetcode.h"

#define MAX 2502
class Solution {
private:
	vector<int> rods;
	vector<int> rodssums;
	int n;
	int maxheight;
	int halfmaxheight;
	bool dp[MAX];
	vector<bool> vflag;
	int ans;
	
	void DFS(int index,int height ) {
		if ((maxheight - height) >> 1 <= ans) { return; }

		if (((maxheight - height)&0x1) == 0x0 && (maxheight - height) >> 1 > ans) {
			if(DP((maxheight - height) >> 1))
			{
				ans = max(ans, (maxheight - height) >> 1);
			}
		}

		for (int i = index; i < n; i++) {
			if (vflag[i] == false) {
				if (i == 0 || (rods[i] != rods[i - 1])) {
					vflag[i] = true;
					DFS(i + 1, height + rods[i]);
					vflag[i] = false;
				}
			}
		}
		if (index < n) {
			DFS(index + 1, height);
		}
	}
	bool DP(int height) {
		for (int i = 1; i <= height; i++) {
			dp[i] = false;
		}
		dp[0] = true;
		for (int j = 0; j < n; j++) {
			if (vflag[j] == true) { continue; }
			for (int i = height; i >= rods[j]; i--) {
				dp[i] = dp[i] || dp[i - rods[j]];
			}
		}
		return dp[height];
	}
public:
	int tallestBillboard(vector<int>& rods) {
		this->rods = rods;
		n = rods.size();
		sort(this->rods.begin(), this->rods.end(), less<int>());
		rodssums = vector<int>(n + 1, 0);
		rodssums[n] = 0;
		for (int i = n - 1; i >= 0; i--) {
			rodssums[i] = rodssums[i + 1] + this->rods[i];
		}
		maxheight = rodssums[0];
		halfmaxheight = maxheight >> 1;
		vflag = vector<bool>(n,false);

		ans = 0;
		DFS(0,0);

		return ans;
	}
};

//int main()
//{
//	Solution s;
//	vector<int> matrix{
//33, 30, 41, 34, 37, 29, 26, 31, 42, 33, 38, 27, 33, 31, 35
//	};
//	int ans = s.tallestBillboard(matrix);
//	cout << ans;
//	system("PAUSE");
//
//	return 0;
//	 
//}