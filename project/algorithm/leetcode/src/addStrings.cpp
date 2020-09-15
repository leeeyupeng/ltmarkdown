#include <iostream>
#include <string>
using namespace std;
class Solution {
public:
	string addStrings(string num1, string num2) {
		int n1 = num1.size();
		int n2 = num2.size();
		char carry = 0;
		int index1 = n1;
		int index2 = n2;
		string ans;
		char c;
		while (index1 > 0 || index2 > 0 || carry > 0) {
			if (index1 > 0 && index2 > 0) {
				c = carry + (num1[--index1] - '0') + (num2[--index2] - '0');
				carry = c>=10?1:0;
				ans.push_back((c >= 10 ? c - 10:c) + '0');
			}
			else if (index1 > 0) {
				c = carry + (num1[--index1] - '0');
				carry = c >= 10 ? 1 : 0;
				ans.push_back((c >= 10 ? c - 10 : c) + '0');
			}
			else if(index2 > 0) {
				c = carry + (num2[--index2] - '0');
				carry = c >= 10 ? 1 : 0;
				ans.push_back((c >= 10 ? c - 10 : c) + '0');
				index2--;
			}
			else
			{
				ans.push_back(carry + '0');
				carry = 0;
			}
		}
		int i = 0;
		int j = ans.size() - 1;
		while (i < j) {
			swap(ans[i++],ans[j--]);
		}
		return ans;
	}
};

//int main()
//{
//	Solution s;
//	string num1 = "88123";
//	string num2 = "986";
//	string ans = s.addStrings(num1,num2);
//	cout << ans;
//	system("PAUSE");
//
//	return 0;
//
//}