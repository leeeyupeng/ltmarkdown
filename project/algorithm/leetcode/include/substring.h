#pragma once
//http://acm.sdibt.edu.cn/JudgeOnline/problem.php?id=2682
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include<string>
#include<algorithm>

using namespace std;

int substring(string s,string p)
{
	int result = 0;
	int j = 0;
	int slength = s.size();
	int plength = p.size();
	for (int i = 0; i <= slength - plength; i++)
	{
		for (j = 0; j < plength; j++)
		{
			if (s[i + j] == p[j])
			{

			}
			else
			{
				break;
			}
		}
		if (j == p.size())
		{
			result++;
		}
	}

	return result;
}

int substring_DFA(string s, string p)
{
	return 0;
}

int substring_KMP(string s, string p)
{
	int result = 0;
	int slength = s.size();
	int plength = p.size();
	vector<int> next(plength);
	next[0] = -1;

	for (int i = 1; i < plength; i++)
	{
		int j = i - 1;
		while (j >= 0 && !(p[next[j] + 1] == p[i]))
		{
			j = next[j];
		}

		if (j >= 0 && (p[next[j] + 1] == p[i]))
		{
			next[i] = next[j] + 1;
		}
		else
		{
			next[i] = next[0];
		}
	}

	int i = 0;
	int j = 0;
	while(i < slength)
	{
		if (s[i] == p[j])
		{
			i++;
			j++;

			if (j == plength)
			{
				result += 1;
				j = next[j - 1] + 1;
			}
		}
		else
		{
			if (j == 0)
			{
				i++;
			}
			else
			{
				j = next[j - 1] + 1;
			}
		}
	}

	return result;
}

//int main()
//{
//	string s;
//	string p;
//	cin >> s;
//	cin >> p;
//	cout << substring_KMP(s, p)<<endl;
//	return 0;
//}