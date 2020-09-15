// poj.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <stack>
#include<string>
#include<algorithm>
using namespace std;
int rs1(int n, string a, string b) {
	unordered_map<char, int> map;
	int ans = 0;
	int i = n - 1, j = n - 1;
	while (i >= 0 && j >= 0) {
		if (a[i] == b[j]) { i--; j--; }
		else if (map.find(b[j]) != map.end() && map[b[j]] > 0) {
			map[b[j]] --;
			j--;
		}
		else {
			if (map.find(a[i]) == map.end()) {
				map.insert({ a[i],1 });
			}
			else {
				map[a[i]]++;
			}
			ans++;
			i--;
		}
	}
	while (j >= 0) {
		if (map.find(b[j]) != map.end() && map[b[j]] > 0) {
			map[b[j]] --;
			j--;
		}
		else {
			break;
		}
	}
	if (j == -1) {
		return ans;
	}
	else
	{
		return -1;
	}
}
const int N = 2005;
string s, t;
int suf[26][N], suf2[26][N];
int cache[N][N];
int dp(int i, int j)
{
	if (j == 0)
		return 0;
	int &ans = cache[i][j];
	if (ans != -1)
		return ans;
	ans = 2e9;
	if (i > 0)
	{
		ans = 1 + dp(i - 1, j);
		if (s[i - 1] == t[j - 1])
			ans = min(ans, dp(i - 1, j - 1));
	}
	int ch = t[j - 1] - 'a';
	if (suf[ch][i + 1] - suf2[ch][j + 1] > 0)
		ans = min(ans, dp(i, j - 1));
	return ans;
}
int rs2(int n, string a, string b) {
	n = n;
	s = a;
	t = b;
	for (int i = 0; i <= n; i++)
		for (int j = 0; j <= n; j++)
			cache[i][j] = -1;
	for (int i = 0; i <= 25; i++)
		for (int j = 0; j <= n + 1; j++)
			suf[i][j] = suf2[i][j] = 0;
	for (int i = n; i >= 1; i--)
	{
		for (int j = 0; j < 26; j++)
		{
			suf[j][i] = suf[j][i + 1];
			suf2[j][i] = suf2[j][i + 1];
		}
		suf[s[i - 1] - 'a'][i]++;
		suf2[t[i - 1] - 'a'][i]++;
	}
	int ans = dp(n, n);
	if (ans > 1e9)
		ans = -1;
	return ans;
}
vector<bool> flag;
string strp;
int nums = 0;
void Perm(string& a,int index) {
	if (index == a.size()) {
		int rs1ans = rs1(a.size(),strp,a);
		int rs2ans = rs2(a.size(), strp, a);
		if (rs1ans != rs2ans) {
			cout << strp << "  "<< a << endl;
			cout << "rs1ans:" << rs1ans << endl;
			cout << "rs2ans:" << rs2ans << endl;
		}
		nums++;
		return;
	}
	for (int i = 0; i < a.size(); i++) {
		if (flag[i] == false) {
			a[index] = strp[i];
			flag[i] = true;
			Perm(a,index+1);
			flag[i] = false;
		}
	}
}
int testdata()
{	
	string a;
	while (cin >> a)
	{
		flag = vector<bool>(a.size(), false);
		strp = a;
		nums = 0;
		Perm(a, 0);
		cout << nums << endl;
	}
	return 0;
}