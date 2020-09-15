#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <queue>
#include<string>
#include<map>
#include<unordered_map>
using namespace std;

struct indexstr {
	int index;
	string str;
};
bool cmp(const indexstr& ia, const indexstr& ib) {
	const string& a = ia.str;
	const string& b = ib.str;
	int i,j;
	for (i = 0,j=0; i < a.length() && j < b.length(); ) {
		if (a[i] == b[j]) { 			
			if (i == a.length() -1 && j == b.length() - 1) { break; }
			else if (i == a.length() - 1) { i = 0; j++; }
			else if (j == b.length() - 1) { j = 0; i++; }
			else {
				i++; j++;
			}
			continue;
		}
		return a[i] > b[j];
	}
	return ia.index < ib.index;
};
class Solution {
private:

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
	string largestNumber(vector<int>& nums) {
		int n = nums.size();
		vector<indexstr> vnums(n);
		for (int i = 0; i < n; i++) {
			vnums[i] = { i,itoa(nums[i]) };
		}

		sort(vnums.begin(),vnums.end(),cmp);
		string ans;
		if (n > 0 && vnums[0].str == "0") { return "0"; }
		for (int i = 0; i < n; i++) {
			ans += vnums[i].str;
		}
		return ans;
	}
};


//int main() {
//
//	Solution s;
//	vector<int> v = {
//0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
//	};
//	string ans = s.largestNumber(v);
//	cout << "ans:" << ans << endl;
//	system("PAUSE");
//
//	return 0;
//}