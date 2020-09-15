#include"leetcode.h"

#define MAX 2502
class Solution {
private:
	vector<int> rods;
	vector<int> rodssums;
	int n;
	int maxheight;
	int halfmaxheight;
	bool dp1[MAX * 2];
	bool dp2[MAX];
	vector<bool> vflag;
	int ans;
	
	int DP1() {
		for (int i = 1; i <= maxheight; i++) {
			dp1[i] = false;
		}
		dp1[0] = true;
		for (int j = 0; j < n; j++) {
			for (int i = maxheight; i >= rods[j]; i--) {
				dp1[i] = dp1[i] || dp1[i - rods[j]];
			}
		}
		int height;
		for (int i = 0; i < maxheight; i++) {
			height = (maxheight - i) >> 1;
			if (dp1[i] == true && dp1[height] && dp1[height*2] && dp1[height+i] && dp1[height*2+i] && (((maxheight - i) & 0x01) == 0x0)) {
				if (DFS(i,i,n-1)) {
					return (maxheight - i) >> 1;
				}
			}
		}
		return 0;
	}
	bool DFS(int value, int curvalue,int index) {
		if (curvalue == 0) {
			int height = (maxheight - value) >> 1;
			if (DP2(height)) { return true; }
			return false;
		}
		for (int i = index; i >= 0; i--) {
			if (i < n - 1 && rods[i] == rods[i + 1]) { continue; }
			if (curvalue - rods[i] >= 0 && dp1[curvalue - rods[i]] == true) {
				vflag[i] = true;
				if (DFS(value, curvalue - rods[i], i - 1))
				{
					vflag[i] = false;
					return true;
				}
				vflag[i] = false;
			}
		}	
		return false;
	}
	bool DP2(int height) {
		for (int i = 1; i <= height; i++) {
			dp2[i] = false;
		}
		dp2[0] = true;
		for (int j = 0; j < n; j++) {
			if (vflag[j] == true) { continue; }
			for (int i = height; i >= rods[j]; i--) {
				dp2[i] = dp2[i] || dp2[i - rods[j]];
			}
		}
		return dp2[height];
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
		ans = DP1();

		return ans;
	}
};

//int main()
//{
//	Solution s;
//	vector<int> matrix{
//33,30,41,34,37,29,26,31,42,33,38,27,33,31,35
//	};
//	int ans = s.tallestBillboard(matrix);
//	cout << ans;
//	system("PAUSE");
//
//	return 0;
//	 
//}