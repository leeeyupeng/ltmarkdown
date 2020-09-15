#pragma once
#include <vector>
#include <map>
#include <set>
#include <stack>
#include<string>
#include<algorithm>

using namespace std;

//https://leetcode-cn.com/problems/longest-palindromic-substring/
string longestPalindrome(string s) 
{
	int ri = 0,rj = 0,result = 0;
	for (int i = 0; i < s.size(); i++)
	{
		for (int j = i + result; j < s.size(); j++)
		{
			int kmax = (i + j + 1) / 2;
			int k = i;
			for (k = i; k < kmax; k++)
			{
				if (s[k] == s[j - (k - i)])
				{
				}
				else
				{
					break;
				}
			}

			if (k == kmax)
			{
				if (j - i + 1 > result)
				{
					ri = i;
					rj = j;
					result = j - i + 1;
				}
			}
		}
	}

	string resultstr(result,0);
	for (int i = ri; i <= rj; i++)
	{
		resultstr[i - ri] = s[i];
	}
	return resultstr;
}