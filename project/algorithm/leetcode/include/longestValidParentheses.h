#pragma once
#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <algorithm>
#include <ctime>
using namespace std;
//https://leetcode-cn.com/problems/longest-valid-parentheses/
class Solution {
public:	
	int longestValidParentheses(string s) 
	{
		int ans = 0;
		int n = s.length();
		int left = 0, right = 0;
		for (int i = 0; i < n; i++)
		{
			if (s[i] == '(') { left++; }
			else { 
				right++; 
				if (left == right) { ans = max(ans, left + right); }
				else if (left < right) { left = 0; right = 0; }
			}
		}
		left = 0; right = 0;
		for (int i = n - 1; i >= 0; i--)
		{
			if (s[i] == ')') { right++; }
			else {
				left++;
				if (left == right) { ans = max(ans, left + left);  }
				else if (right < left) { left = 0; right = 0; break; }
			}
		}
		return ans;
	}
};