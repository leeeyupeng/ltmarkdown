#pragma once
#include <iostream>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <string>
#include <map>
#include <set>
#include <algorithm>
using namespace std;

class Solution {
public:
	string dec2hex(string num) {
		string ans(num.length(),'0');
		int value;
		for (int i = 0; i < num.length(); i++) {

		}
		return ans;
	}
	string multiply(string num1, string num2) {
		if (num1.length() < num2.length()) {
			swap(num1,num2);
		}
		string num1hex = dec2hex(num1);
		string num2hex = dec2hex(num2);
		string ans;
		return ans;
	}
};