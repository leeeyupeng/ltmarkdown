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
#include <ctime>
#include <regex>
using namespace std;
//https://leetcode-cn.com/problems/wildcard-matching/
class Solution {
public:
	bool isMatch(string s, string p) {

		int j = p.length()-1;
		while (j >= 0) {
			if (p[j] == '*') {
				p.insert(j,1,'.');
			}
			if (p[j] == '?') {
				p[j] = '.';
			}
			j--;
		}
		std::regex reg(p);
		return std::regex_match(s, reg);
	}
};