#pragma once
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include<string>
#include<algorithm>

using namespace std;

//https://leetcode-cn.com/problems/decode-ways-ii/
int numDecodings(string s) {
	int result = 1;
	long long last1 = 1,last2 = 1, cur = 0;
	for (int i = 0; i < s.size(); i++)
	{
		if (i == 0)
		{
			if (s[i] == '0')
			{
				cur = 0;
			}
			else if (s[i] == '*')
			{
				cur = 9;
			}
			else
			{
				cur = 1;
			}
		}
		else
		{
			if (s[i - 1] == '*' && s[i] == '*')
			{
				cur = last2 * 9 + last1 * 15;
			}
			else if (s[i - 1] == '*')
			{
				if (s[i] == '0')
				{
					cur = last1 * 2;
				}
				else if (s[i] <= '6')
				{
					cur = last2 + last1 * 2;
				}
				else
				{
					cur = last2 + last1 * 1;
				}
			}
			else if (s[i] == '*')
			{
				if (s[i - 1] == '0')
				{
					cur = last2 * 9;
				}
				else if (s[i - 1] == '1')
				{
					cur = last2 * 9 + last1 * 9;
				}
				else if (s[i - 1] == '2')
				{
					cur = last2 * 9 + last1 * 6;
				}
				else
				{
					cur = last2 * 9;
				}
			}
			else
			{
				if (s[i - 1] == '0' && s[i] == '0')
				{
					cur = 0;
				}
				else if (s[i - 1] == '0')
				{
					cur = last2;
				}
				else if (s[i] == '0')
				{
					if (s[i - 1] <= '2')
					{
						cur = last1 * 1;
					}
					else
					{
						cur = 0;
					}
				}
				else if (s[i - 1] == '1')
				{
					cur = last2 + last1 * 1;
				}
				else if (s[i - 1] == '2' && s[i] <= '6')
				{
					cur = last2 + last1 * 1;
				}
				else
				{
					cur = last2;
				}
			}
		}
		if (cur >= 1000000007)
		{
			cur = cur % (1000000007);
		}
		last1 = last2;
		last2 = cur;
	}
	result = (int)cur;
	return result;
}