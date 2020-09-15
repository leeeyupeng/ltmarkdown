#pragma once
#include <vector>
#include <map>
#include <set>
#include <stack>
#include<string>
#include<algorithm>

#include "FiniteAutomata.h"
using namespace std;

class Node;
class FiniteAutomata;
//https://leetcode-cn.com/problems/wildcard-matching/
//FA 有限自动机
bool isMatch_FA(string s, string p)
{
	if (s.empty() && p.empty())
	{
		return true;
	}
	else if (p.empty())
	{
		return false;
	}
	else if (s.empty())
	{
		for (int j = 0; j < p.length(); j++)
		{
			if (p[j] != '*')
			{
				return false;
			}
		}
		return true;
	}
	FiniteAutomata fa(p);
	return fa.Pattern(s);
}

int isMatchState(string s, string p, int state, int i, int j)
{
	if (i < s.size() && j < p.size())
	{
		if (state == 0 || state == 1)
		{
			if (s[i] == p[j] || p[j] == '?')
			{
				state = isMatchState(s, p, state, i + 1, j + 1);
			}
			else if (p[j] == '*')
			{
				state = isMatchState(s, p, 2, i, j + 1);
			}
			else
			{
				state = -1;
			}
		}
		else if (state == 2)
		{
			if (s[i] == p[j] || p[j] == '?')
			{
				int statetemp = isMatchState(s, p, 1, i + 1, j + 1);
				if (statetemp != -1)
				{
					return statetemp;
				}
			}
			else if (p[j] == '*')
			{
				int statetemp = isMatchState(s, p, 2, i, j + 1);
				if (statetemp != -1)
				{
					return statetemp;
				}
			}

			state = isMatchState(s, p, state, i + 1, j);
		}
	}
	else if (j < p.size())
	{
		for (int i = j; i < p.size(); i++)
		{
			if (p[i] != '*')
			{
				state = -1;
				break;
			}
		}
	}
	else if(i < s.size())
	{
		if (state != 2)
		{
			state = -1;
		}
	}
	return state;
}
bool isMatch_DFA(string s, string p) 
{
	if (s.empty() && p.empty())
	{
		return true;
	}
	else if (p.empty())
	{
		return false;
	}
	int state= isMatchState(s, p, 0, 0, 0);
	return state != -1;

}

//动态规划
bool isMatch_DP(string s, string p)
{
	if (s.empty() && p.empty())
	{
		return true;
	}
	else if (p.empty())
	{
		return false;
	}
	else if (s.empty())
	{
		for (int j = 0; j < p.length(); j++)
		{
			if (p[j] != '*')
			{
				return false;
			}
		}
		return true;
	}
	bool ** dp = new bool*[s.length() + 1];
	for (int i = 0; i < s.length() + 1; i++)
	{
		dp[i] = new bool[p.length() + 1]{ false };
	}

	dp[0][0] = true;
	for (int i = 1; i < s.length() + 1; i++)
	{
		dp[i][0] = false;
	}
	for (int j = 1; j < p.length() + 1; j++)
	{
		if (p[j - 1] == '*')
		{
			dp[0][j] = true;
		}
		else
		{
			break;
		}
	}

	for (int i = 1; i <= s.length(); i++)
	{
		for (int j = 1; j <= p.length(); j++)
		{
			if (s[i - 1] == p[j - 1])
			{
				dp[i][j] = dp[(i - 1)][j - 1];
			}
			else if (p[j - 1] == '*')
			{
				dp[i][j] = dp[(i - 1)][j] || dp[(i)][j - 1];
			}
			else if (p[j - 1] == '?')
			{
				dp[i][j] = dp[(i - 1)][j - 1];
			}
			else
			{
				dp[i][j] = false;
			}
		}
	}

	bool result = dp[(s.length())][p.length()];

	for (int i = 0; i < s.length() + 1; i++)
	{
		delete[] dp[i];
	}
	delete[] dp;
	return result;
}
//动态KMP算法
bool PATTERN_KMP(const string&s, const string&p)
{
	vector<int> next(p.size() + 1, 0);

	int i = 0,j = 0;
	int pstart = 0;

	next[0] = -1;

	bool star = false;
	while(i < s.size() && j < p.size())
	{
		if (p[j] == '*')
		{
			star = true;
			j++;

			next[j] = j - 1;
			pstart = j;

			continue;
		}

		if (p[j] == s[i])
		{
			int pj = j - 1;
			while (pj>= pstart && !(p[next[pj] + 1] == p[j] || p[next[pj] + 1] == '?'))
			{
				pj = next[pj];
			}
			if (pj>= pstart && (p[next[pj] + 1] == p[j] || p[next[pj] + 1] == '?'))
			{
				next[j] = next[pj] + 1;
			}
			else
			{
				next[j] = next[pstart];
			}

			i++;
			j++;
		}
		else if (p[j] == '?')
		{
			int pj = j-1;
			while (pj>= pstart && !(p[next[pj] + 1] == s[i] || p[next[pj] + 1] == '?'))
			{
				pj = next[pj];
			}
			if (pj>= pstart && (p[next[pj] + 1] == s[i] || p[next[pj] + 1] == '?'))
			{
				next[j] = next[pj] + 1;
			}
			else
			{
				next[j] = next[pstart];
			}

			i++;
			j++;
		}
		else
		{
			if (j - 1 >= pstart) 
			{
				j = next[j - 1] + 1;
			}
			else
			{
				i++;
			}

			if (star == false)
			{
				return false;
			}
			else if (star == true)
			{
				continue; 
			}
		}

		if (star == true && i < s.size()  && j == p.size())
		{
			j = next[j - 1] + 1;			
		}
	}

	if (i == s.size())
	{
		while (j < p.size())
		{
			if (p[j] != '*')
			{
				return false; 
			}
			j++;
		}
		return true;
	}
	else if (j == p.size())
	{
		if (p[j - 1] != '*')
		{
			return false;
		}
		return true;
	}
	else
	{
		return true;
	}
}

//BF算法
bool PATTERN_BF(const string&s, const string&p)
{
	int i = 0, j = 0;
	bool star = false;

	while (i < s.size() && j < p.size())
	{
		if (p[j] == '*')
		{
			star = true;
			j++;
		}

		int k = 0;
		while (i + k < s.size() && j + k < p.size())
		{
			if (p[j + k] == '*')
			{
				i = i + k;
				j = j + k;
				break;
			}
			if (s[i + k] == p[j + k] || p[j + k] == '?')
			{
				k++;
			}
			else
			{
				if (star == true)
				{
					i++;
					break;
				}
				else
				{
					return false;
				}
			}

			if (i + k == s.size() && j + k == p.size())
			{
				i = i + k;
				j = j + k;
			}
			else if (j + k == p.size())
			{
				if (star == true)
				{
					i++;
					break;
				}
				else
				{
					return false;
				}
			}
			else if (i + k == s.size())
			{
				i = i + k;
				j = j + k;
			}
		}
	}

	if (i == s.size() && j == p.size())
	{
		return true;
	}
	else if (i == s.size())
	{
		int k = j;
		while (k < p.size())
		{
			if (p[k] == '*')
			{
				k++;
			}
			else
			{
				return false;
			}
		}
		return true;
	}
	else if (j == p.size())
	{
		if (p[j - 1] == '*')
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	return false;
}