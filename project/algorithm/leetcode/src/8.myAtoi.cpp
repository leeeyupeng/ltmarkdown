#include"leetcode.h"

class Solution {
public:
	int myAtoi(string str) {
		long long ans = 0;
		int sign = 0;
		int n = str.length();
		bool flagdigit = false;
		for (int i = 0; i < n; i++) {
			if (str[i] == ' '&& flagdigit == false) { continue; }
			else if (str[i] == '+' && sign == 0 && flagdigit == false) { 
				sign = 1; flagdigit = true;
			}
			else if (str[i] == '-'&& sign == 0 && flagdigit == false) {
				sign = -1; flagdigit = true;
			}
			else if(str[i]>='0'&&str[i]<='9'){
				flagdigit = true;
				if (sign == 0) { sign = 1; }
				if (ans * 10 + (str[i] - '0') > INT_MAX) { ans = INT_MAX; break; }
				else if (ans * 10 + sign * (str[i] - '0') < INT_MIN) { ans = INT_MIN; break; }
				ans = ans * 10 + sign * (str[i] - '0');
			}
			else
			{
				break;
			}
		}
		return ans;
	}
};


//int main() {
//
//	Solution s;
//	int ans = s.myAtoi("-42");
//	cout << "ans:" << ans << endl;
//	system("PAUSE");
//
//	return 0;
//}