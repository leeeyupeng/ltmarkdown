#include"leetcode.h"

class Solution {
private:
	int n;
	bool readdouble(string& s, int& i) {
		bool flag1 = false, flag2 = false;
		//double digit = 1;
		if (i < n && (s[i] == '+' || s[i] == '-')) {
			//digit *= s[i] == '+' ? 1 : -1;
			i++;
		}
		if (i < n && (s[i] >= '0'&&s[i] <= '9')) {
			while (i < n && (s[i] >= '0'&&s[i] <= '9')) {
				//digit *= 10;
				//digit += s[i] - '0';
				i++;
			}
			flag1 = true;
			if (s[i] != '.') { return true; }
		}
		if (i < n && s[i] == '.') {
			i++;
			//double dp = 1.0f;
			if (i < n && (s[i] >= '0'&&s[i] <= '9')) {
				while (i < n && (s[i] >= '0'&&s[i] <= '9')) {
					//dp /= 10.0f;
					//digit += dp * (s[i] - '0');
					i++;
				}
				flag2 = true;
			}
			return flag1 || flag2;
		}
		return false;
	}
	bool readint(string& s, int& i) {
		if (i < n && (s[i] == '+' || s[i] == '-')) {
			//digit *= s[i] == '+' ? 1 : -1;
			i++;
		}
		if (i < n && (s[i] >= '0'&&s[i] <= '9')) {
			while (i < n && (s[i] >= '0'&&s[i] <= '9')) {
				//digit *= 10;
				//digit += s[i] - '0';
				i++;
			}
			return true;
		}
		return false;
	}
public:
	bool isNumber(string s) {
		n = s.length();
		int i = 0;
		while (i < n && s[i] == ' ') { i++; }
		bool flag = readdouble(s, i);
		if (flag == false) { return flag; }
		if (i == n) { return flag; }
		if (s[i] == 'e' || s[i] == 'E') 
		{
			i++;
			bool flag = readint(s, i);
			while (i < n && s[i] == ' ') { i++; }
			if (i < n) { return false; }
			else {
				return flag;
			}
		}
		while (i < n && s[i] == ' ') { i++; }
		if (i == n) { return flag; }
		return false;
	}
};