#include"leetcode.h"

class Solution {
private:
	int arr[32];
public:
	int divide(int dividend, int divisor) {
		bool flag1 = ((dividend >> 31) & 0x1) == 0x1 ? false : true;
		bool flag2 = ((divisor >> 31) & 0x1) == 0x1 ? false : true;

		int length = 0;

		int value = flag2?-divisor: divisor;
		arr[length] = value;
		length++;
		while (length < 32 && value >= INT_MIN - value) {
			value = value + value;
			arr[length] = value;
			length++;
		}

		int ans = 0;
		int divid = 0;

		for (int i = length - 1; i >= 0; i--) {
			if (flag1==true) {
				if (-(dividend - divid) <= arr[i]) {
					if (flag2) { 
						if ((1 << i) >= 0) { ans += (1 << i); }
						else { { ans += INT_MAX; } }
					}
					else { 
						if ((1 << i) >= 0) { ans -= (1 << i); }
						else { { ans += (1 << i); } }
					}
					divid += -arr[i];
				}
			}
			else if (flag1 == false) {
				if ((dividend - divid) <= arr[i]) {
					if (flag2) { 
						if ((1 << i) >= 0) { ans -= (1 << i); }
						else { { ans +=(1 << i); } }
					}
					else { 
						if ((1 << i) >= 0) { ans += (1 << i); }
						else { { ans += INT_MAX; } }
					}
					divid += arr[i];
				}
			}

		}
		return ans;
	}
};

//int main() {
//
//	Solution s;
//	int ans = s.divide(INT_MIN, -1);
//	cout << "ans:" << ans << endl;
//	system("PAUSE");
//
//	return 0;
//}