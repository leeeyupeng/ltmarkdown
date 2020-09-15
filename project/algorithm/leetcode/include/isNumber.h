#pragma once
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include<string>
#include<algorithm>
using namespace std;


//https://leetcode-cn.com/problems/valid-number/

//1.数字 0 - 9
//2.指数 - "e"
//3.正 / 负号 - "+" / "-"
//4.小数点 - "."
//1
//31
//141	3141			341		14		314		34
//121	3121	14121	314121	1231	31231	141231	3141231	4121	34121	41231	341231	1421	31421	14231	314231
bool isNumber11(string s) {
	stack<int> sta;
	for (int i = 0; i < s.size(); i++)
	{
		char c = s[i];
		int type = 0;
		if (c >= 48 && c < 48 + 10)
		{
			type = 1;
		}
		else if (c == 'e')
		{
			type = 2;
		}
		else if (c == '-' || c == '+')
		{
			type = 3;
		}
		else if (c == '.')
		{
			type = 4;
		}
		else if (c == ' ')
		{
			type = 5;
		}
		else
		{
			return false;
		}

		if (sta.empty())
		{
			if (type != 5)
			{
				sta.push(type);
			}
		}
		else
		{
			if (type == 1 && sta.top() == 1)
			{
				continue;
			}
			else if (type == 5 && sta.top() == 5)
			{
				continue;
			}
			else
			{
				sta.push(type);
			}
		}
	}

	int res = 0;
	int m = 1;
	while (!sta.empty())
	{
		if (sta.top() == 5)
		{
			sta.pop();
		}
		else
		{
			break;
		}
	}
	while (!sta.empty())
	{
		res += sta.top() * m;
		sta.pop();
		m *= 10;
		if (res > 35142351)
		{
			return false;
		}
	}
	vector<int> v{1,31,141,3141,41	,	341,14		,314,121,	3121,	14121,	314121,	1231,	31231,	141231,	3141231,4121,	34121	,41231,	341231,1421	,31421	,14231	,314231,
	35141,3541,3514	,121,	35121,	14121,	3514121,	12351,	31231,	1412351,	351412351, 31412351,4121,	354121	,412351,	3541231,3412351,35412351,1421	,351421	,142351	,35142351 ,3514231,3142351 };
	for (int i = 0; i < v.size(); i++)
	{
		if (v[i] == res)
		{
			return true;
		}
	}
	return false;
}

//DFA
//DFA 有限状态机
bool isNumber22(string s)
{
	int ss[9][6] =
	{
		{0, 1, 6, 2,-1,-1},
		{-1,-1, 6, 2,-1,-1},
		{-1,-1, 3,-1,-1,-1},
		{8,-1, 3,-1, 4,-1},
		{-1, 7, 5,-1,-1,-1},
		{8,-1, 5,-1,-1,-1},
		{8,-1, 6, 3, 4,-1},
		{7,-1, 5,-1,-1,-1},
		{8,-1,-1,-1,-1,-1},
	};
	int state = 0;

	for (int i = 0; i < s.size(); i++)
	{
		char c = s[i];
		int type = 0;
		if (c >= 48 && c < 48 + 10)
		{
			type = 2;
		}
		else if (c == 'e')
		{
			type = 4;
		}
		else if (c == '-' || c == '+')
		{
			type = 1;
		}
		else if (c == '.')
		{
			type = 3;
		}
		else if (c == ' ')
		{
			type = 0;
		}
		else
		{
			type = 5;
		}

		state = ss[state][type];
		if (state == -1)
		{
			return false;
		}
	}

	state = ss[state][0];

	return state == 8;

}
