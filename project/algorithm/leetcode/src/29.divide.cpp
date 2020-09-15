#include"leetcode.h"

class Solution {
public:
	int divide(int dividend, int divisor) {
		int ans = 0;
		int divid = 0;
		bool flag1 = ((dividend >> 31) & 0x1) == 0x1 ? false : true;
		bool flag2 = ((divisor >> 31) & 0x1) == 0x1 ? false : true;
		while (true) {
			if ((flag1 ? divid - dividend : dividend - divid) > (flag2 ? -divisor : divisor)) { break; }
			divid += (flag1 ^ flag2) ? -divisor : divisor;
			if (flag1 ? dividend < divid : dividend > divid) { break; }
			ans += (flag1 ^ flag2) ? -1 : 1;
		}
		return ans;
	}
};

//int main() {
//
//	Solution s;
//	int ans = s.divide(10, -3);
//	cout << "ans:" << ans << endl;
//	system("PAUSE");
//
//	return 0;
//}