#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <queue>
#include<string>
#include<map>
#include<unordered_map>
using namespace std;

class Solution {
public:
	string itoa(long long num) {
		string ans;
		if ((num >> 63 & 0x1 == 0x1)) { ans += "-"; }
		int llnum = num;
		int value;
		int mod;
		vector<int> v;
		if (llnum == 0) { ans += '0'; return ans; }
		while (llnum != 0) {
			mod = llnum % 10;
			llnum = llnum / 10;
			v.push_back(mod);
		}
		for (int i = v.size() - 1; i >= 0; i--) {
			ans.push_back(abs(v[i]) + '0');
		}
		return ans;
	}
public:
	string fractionToDecimal(int numerator, int denominator) {
		string ans;
		if (numerator == 0) { return "0"; }
		if ((long long)numerator / (long long)denominator == 0) {
			if ((numerator >> 31 & 0x1 == 0x1) ^ (denominator >> 31 & 0x1 == 0x1)) { ans += "-"; }
		}
		ans += itoa((long long)numerator / (long long)denominator);

		vector<int> v;
		unordered_map<int, int> map;
		int count = 0;

		int mod, value;
		long long numerator2 = (long long)numerator % (long long)denominator;
		if (numerator2 == 0) { return ans; }
		while (numerator2 != 0) {
			numerator2 *= 10;
			value = numerator2 / denominator;
			mod = numerator2 % denominator;
			numerator2 = mod;
			if (map.find(mod) != map.end() && v[map[mod]] == value) {
				break;
			}
			v.push_back(value);

			map[numerator2] = count;
			count++;
		}
		int index = -1;
		if (numerator2 != 0) {
			index = map[numerator2];
		}
		ans += '.';
		for (int i = 0; i < v.size(); i++) {
			if (i == index) {
				ans.push_back('(');
			}
			ans.push_back(abs(v[i]) + '0');
		}
		if (index != -1) { ans.push_back(')'); }
		return ans;
	}
};

//int main() {
//
//	Solution s;
//	string ans = s.fractionToDecimal(1,6);
//	cout << "ans:" << ans << endl;
//	system("PAUSE");
//
//	return 0;
//}