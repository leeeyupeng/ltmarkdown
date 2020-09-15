#include"leetcode.h"

class Solution {
private:
	vector<int> rods;
	vector<int> remain;
	int n;
	int maxheight;
	int halfmaxheight;
	int ans;

	void DFS(int index, int leftheight,int rightheight) {
		if (leftheight == rightheight) { ans = max(ans, leftheight); }
		if (abs(leftheight - rightheight) > remain[index]) { return; }
		if ((leftheight + rightheight + remain[index]) <= ans + ans) { return; }
		if (leftheight > halfmaxheight || rightheight > halfmaxheight) { return; }
		for (int i = index; i < n; i++) {
			DFS(i+1,leftheight+rods[i],rightheight);
			DFS(i+1, leftheight, rightheight + rods[i]);
		}
	}

public:
	int tallestBillboard(vector<int>& rods) {
		this->rods = rods;
		n = rods.size();
		sort(this->rods.begin(), this->rods.end(), greater<int>());
		remain = vector<int>(n + 1, 0);
		remain[n] = 0;
		for (int i = n - 1; i >= 0; i--) {
			remain[i] = remain[i + 1] + this->rods[i];
		}

		maxheight = remain[0];
		halfmaxheight = maxheight >> 1;
		ans = 0;
		DFS(0, 0,0);

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