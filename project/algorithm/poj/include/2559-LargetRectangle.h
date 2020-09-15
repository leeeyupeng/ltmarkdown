#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <algorithm>
#include <ctime>
using namespace std;

long long LargetRectangle(int n, vector<int>& v)
{
	long long ans=0;
	stack<int> s;
	int temp = 0;
	int index = 0;
	long long cnt;

	for (int i = 0; i < n; i++)
	{
		while (!s.empty())
		{
			if (v[s.top()] > v[i])
			{
				index = s.top();
				s.pop();
				temp = s.empty() ? (i) : (i - s.top() - 1);
				cnt = (long long)v[index] * temp;
				ans = ans > cnt ? ans : cnt;
			}
			else
			{
				break;
			}
		}
		s.push(i);
	}

	while (!s.empty())
	{
		index = s.top();
		s.pop();
		temp = s.empty() ? (n) : (n - s.top() - 1);
		cnt = (long long)v[index] * temp;
		ans = ans > cnt ? ans : cnt;
	}

	return ans;
}
int mainpoj()
{
	int n;
	while (scanf("%d", &n)!= EOF)
	{
		if (n == 0)
		{
			break;
		}
		vector<int> v(n);
		for (int i = 0; i < n; i++)
		{
			scanf("%d", &v[i]);
		}
		printf("%lld\n", LargetRectangle(n, v));
	}

	return 0;
}
