#include"leetcode.h"

class Solution {
private:
	vector<int> rods;
	vector<int> rodssums;
	vector<int> rodssums2;
	int n;
	int maxheight;
	int halfmaxheight;
	vector<bool> vflag;
	int ans;
	
	void DFS(int index,int height ) {
		if (height > halfmaxheight) { return; }
		if (height + rodssums[index] <= ans) { return; }
		for (int i = index; i < n; i++) {
			if (vflag[i] == false) {
				vflag[i] = true;
				DFS(i+1,height + rods[i]);
				vflag[i] = false;
			}
		}
		if (index < n) {
			DFS(index + 1, height);
		}

		if (height > ans) {
			for (int i = n - 1; i >= 0; i--) {
				if (vflag[i] == false) {
					rodssums2[i] = rodssums2[i + 1] + this->rods[i];
				}
			}
			if (DFS2(0, maxheight - (height << 1)))
			{
				ans = max(ans, height);
			}
		}
	}

	bool DFS2(int index,int height2) {
		if (height2 < 0) { return false; }
		if (height2 == 0) { 
			return true;
		}
		if (height2 - rodssums2[index] > 0) { return false; }
		for (int i = index; i < n; i++) {
			if (vflag[i] == false && height2 >= rods[i]) {
				vflag[i] = true;
				if (DFS2(i + 1, height2 - rods[i])) {
					vflag[i] = false;
					return true;
				}
				vflag[i] = false;
			}
		}
		if (index < n) {
			if (DFS2(index + 1,  height2)) { return true; }
		}
	}
public:
	int tallestBillboard(vector<int>& rods) {
		this->rods = rods;
		n = rods.size();
		sort(this->rods.begin(), this->rods.end(), greater<int>());
		rodssums = vector<int>(n+1, 0);
		rodssums[n] = 0;
		for (int i = n - 1; i >= 0; i--) {
			rodssums[i] = rodssums[i + 1] + this->rods[i];
		}

		rodssums2 = vector<int>(n + 1, 0);
		rodssums2[n] = 0;
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
//1,2,3,4,5,6
//	};
//	int ans = s.tallestBillboard(matrix);
//	cout << ans;
//	system("PAUSE");
//
//	return 0;
//	 
//}