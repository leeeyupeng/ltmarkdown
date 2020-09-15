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
	string addBinary(string a, string b) {
		string ans;
		int n = a.length();
		int m = b.length();
		if (n == m && n == 0) { return "0"; }
		reverse(a.begin(), a.end());
		reverse(b.begin(), b.end());
		int index=0;
		bool carry = false;
		while (index < n&&index < m) {
			if (a[index] == '1'&&b[index] == '1') {
				if (carry) { ans.push_back('1'); }
				else { ans.push_back('0'); carry = true; }
			}
			else if (a[index] == '1' || b[index] == '1') {
				if (carry) { ans.push_back('0');}
				else { ans.push_back('1');  }
			}
			else {
				if (carry) { ans.push_back('1'); carry = false; }
				else { ans.push_back('0'); }
			}
			index++;
		}
		while (index < n) {
			if (a[index] == '1') {
				if (carry) { ans.push_back('0'); carry = true;}
				else { ans.push_back('1');  }				
			}
			else {
				if (carry) { ans.push_back('1'); carry = false; }
				else { ans.push_back('0'); }
			}
			index++;
		}
		while (index < m) {
			if (b[index] == '1') {
				if (carry) { ans.push_back('0'); carry = true; }
				else { ans.push_back('1'); }
			}
			else {
				if (carry) { ans.push_back('1'); carry = false; }
				else { ans.push_back('0'); }
			}
			index++;
		}

		if (carry) { ans.push_back('1'); }
		reverse(ans.begin(),ans.end());
		return ans;
	}
};