#include"leetcode.h"

class Solution {
public:
	int minimumOperations(string leaves) {
		int n = leaves.length();
		int rcount = 0;
		int ycountleft = 0;
		int ycountright = 0;
		ycountleft = leaves[0] == 'y' ? 1 : 0;		
		rcount = leaves[1] == 'r' ? 1 : 0;
		for (int k = 2; k < n; k++) {
			ycountright = leaves[k] == 'y' ? 1 : 0;
		}
		int ans = ycountleft + rcount + ycountright;
		int i = 1, j = 1;
		while (j < n - 1) {
			while (leaves[i] == 'r') { i++; rcount--; }
			while (leaves[j] == 'y') { j++; ycountright--; }
			ans = min(ans, ycountleft + rcount + ycountright);
		}
		return ans;
	}
};

// int main() {

// 	Solution s;
// 	int ans = s.minimumOperations("rrryyyrryyyrr");
// 	cout << "ans:" << ans << endl;
// 	//system("PAUSE");
// 	getchar();
// 	return 0;
// }