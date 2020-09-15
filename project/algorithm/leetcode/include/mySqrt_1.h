#pragma once
//https://leetcode-cn.com/problems/sqrtx/
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
	int mySqrt(int x) {
		double eps = 1e-12;
		double x2 = x,last = 0;
		while (abs(x2-last)>eps) {
			last = x2;
			x2 = (x2 + x / x2)*0.5f;
		}
		return floor(x2+eps);
	}
};