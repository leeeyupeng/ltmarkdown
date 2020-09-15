#include"leetcode.h"

class Solution {
public:
	int minimumOperations(string leaves) {
		int n = leaves.length();
		int ynums = 0;
		for (int i = 0; i < n; i++) { ynums += leaves[i] == 'y' ? 1 : 0; }
		int i = 1; int j = 1;
		int ycount = 0;
		int ycountleft = 0;
		int ycountright = 0;
		ycountleft = leaves[0] == 'y' ? 1 : 0;
		while (j <= ynums) { ycount += leaves[j] == 'y' ? 1 : 0; j++; }
		ycountright = ynums - ycount - ycountleft;
		int ans = ycountleft + ynums - ycount + ycountright;
		while (j < n-1) {
			ycountleft += leaves[i] == 'y' ? 1 : 0;
			ycount -= leaves[i] == 'y' ? 1 : 0;
			ycount += leaves[j] == 'y' ? 1 : 0;
			ycountright -= leaves[j] == 'y' ? 1 : 0;
			ans = min(ans, ycountleft + ynums - ycount + ycountright);
			i++; j++;
		}
		return ans;
	}
};

//int main() {
//
//	Solution s;
//	int ans = s.minimumOperations("rrryyyrryyyrr");
//	cout << "ans:" << ans << endl;
//	//system("PAUSE");
//	getchar();
//	return 0;
//}