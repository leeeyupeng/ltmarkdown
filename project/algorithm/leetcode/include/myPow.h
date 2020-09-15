#pragma once
//https://leetcode-cn.com/problems/powx-n/
#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <set>
#include <stack>
#include<string>
#include<algorithm>

using namespace std;
class Solution {
public:
	double myPow(double x, int n) {
		double ans= 1;
		double xx = x;
		long long nn = abs(n);
		while (nn != 0 && xx!=1.0f) {
			ans *= (nn & 0x1) == 0x1 ? xx : 1;
			nn >>= 1;
			xx *= xx;
		}
		return n>=0?ans:1/ans;
	}
};