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
		unsigned long long left = 0,right = x,mid=0;
		while(left < right) {
			mid = (left + right) >> 1;
			if (mid * mid > x) {
				right = mid - 1;
			}
			else {
				left = mid + 1;
			}
		}
		return left * left<=x?left:left-1;
	}
};