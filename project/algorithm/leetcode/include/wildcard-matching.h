#include <iostream>
#include <string>
#include <stack>
#include <queue>
#include <list>
#include <vector>
#include <set>
#include <map>
using namespace std;
//https://leetcode-cn.com/problems/wildcard-matching/

namespace wildcardmatchingDP
{
	class Solution {
	public:
		bool isMatch(string s, string p) {
			vector<vector<bool>> dp;
			dp.resize(s.length() + 1, vector<bool>(p.length() + 1));

			dp[0][0] = true;
			for (int j = 1; j < p.length() + 1; j++)
			{
				if (p[j - 1] == '*')
				{
					
					dp[0][j] = dp[0][j - 1];
				}
			}
			for (int i = 1; i < s.length() + 1; i++)
			{
				for (int j = 1; j < p.length() + 1; j++)
				{
					if (p[j - 1] == '*')
					{
						dp[i][j] = dp[i - 1][j - 1] || dp[i][j - 1] || dp[i - 1][j];
					}
					else if (s[i - 1] == p[j - 1] || p[j - 1] == '?')
					{
						dp[i][j] = dp[i - 1][j - 1];
					}
					else
					{
						dp[i][j] = false;
					}
				}
			}
			return dp[s.length()][p.length()];
		}
	};
}

namespace wildcardmatchingDPRecursive
{
	class Solution {
	public:
		string ss;
		string pp;
		map<int, bool>* m=new std::map<int, bool>();
		bool isMatchRecursive( int i, int j)
		{
			int key = i * (ss.length() + 10) * (pp.length() + 10)+ j;
			if (m->find(key) != m->end())
			{
				return m->at(key);
			}
			bool value = false;
			if (j < 0)
			{
				if (i < 0)
				{
					value = true;
				}
				else
				{
					value = false;
				}
			}
			else if (i < 0)
			{
				if (pp[j] == '*')
				{
					value = isMatchRecursive( i, j - 1);
				}
				else
				{
					value = false;
				}
			}
			else if (pp[j] == '*')
			{
				value = isMatchRecursive(i,j - 1) || isMatchRecursive(i - 1,j);
			}
			else if (ss[i] == pp[j] || pp[j] == '?')
			{
				value = isMatchRecursive( i - 1, j - 1);
			}
			else
			{
				value = false;
			}
			m->insert({ key,value });
			return value;
		}
		bool isMatch(string s, string p) {
			ss = s;
			pp = p;
			bool result = isMatchRecursive( ss.length() - 1, pp.length() - 1);
			return result;
		}
	};
}

namespace wildcardmatchingKMP
{
	class Solution {
	public:
		vector<int> GetNextval(string p)
		{
			int pLen = p.length();
			vector<int> next(pLen, 0);
			next[0] = -1;
			int k = -1;
			int j = 0;
			
			while (j < pLen - 1)
			{
				if (p[j] == '*')
				{
					k = j;
					++j;
					next[j] = k;
				}
				else if (k == -1 || (p[j] == p[k] || p[j] == '?' || p[k] == '?' || p[j] == '*' || p[k] == '*'))
				{
					++j;
					++k;
					if (p[j] != p[k] || p[j] == '?' || p[k] == '?' || p[j] == '*' || p[k] == '*')
					{
						next[j] = k;
					}
					else
					{
						if (k != 0 && p[k - 1] == '*')
						{
							next[j] = k - 1;
						}
						else
						{
							next[j] = next[k];
						}
					}
				}
				else
				{
					k = next[k];
				}
			}
			return next;
		}
		bool isMatch(string s, string p) {
			if (p.empty())
			{
				if (s.empty())
				{
					return true;
				}
				else
				{
					return false;
				}
			}
			string pp =p;
			pp.push_back('?');
			vector<int> next = GetNextval(pp);

			int i = 0;
			int j = 0;
			int k = 0;
			int kk = 0;
			int sLen = s.length();
			int pLen = p.length();

			bool starFlag = false;
			while (i < sLen)
			{
				if (j == -1)
				{
					break;
				}

				while (j < pLen && p[j] == '*')
				{
					starFlag = true;
					j++;
				}

				if (j < pLen && (s[i] == p[j] || p[j] == '?' || p[j] == '*'))
				{
					i++;
					j++;
				}
				else
				{   
					if (starFlag == false)
					{
						break;
					}

					//j = next[j];

					//��֤?
					k = next[j];
					while (k > 0)
					{						
						kk = k;
						while (kk >= 0 && p[kk] != '*')
						{
							if (p[j - (k - kk)] == '?' && p[kk] != '?')
							{
								if (s[i - (k - kk)] != p[kk])
								{
									break;
								}
							}
							kk--;
						}
						if (kk < 0 || p[kk] == '*')
						{
							break;
						}
						else
						{
							k = next[k];
						}
					}

					j = k;

					if (p[j] == '*')
					{
						i++;
					}
				}
			}

			while (j < pLen && p[j] == '*')
			{
				j++;
			}
			if (i == sLen && j == pLen)
				return true;
			else
				return false;
		}
	};
}