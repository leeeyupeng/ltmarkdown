#pragma once
#include <iostream>
#include <vector>
using namespace std;

bool isDivisibility(vector<int>& v, int n, int k)
{
	vector<bool>* dp = new vector<bool>(k);
	vector<bool>* dptemp = new vector<bool>(k);
	(*dp)[0] = true;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < k; j++)
		{
			(*dptemp)[j] = (*dp)[((j - v[i]) % k + k) % k] || (*dp)[((j + v[i]) % k + k) % k];
		}

		vector<bool>* temp = dp;
		dp = dptemp;
		dptemp = temp;
	}

	return (*dp)[0];
}

int mainpoj()
{
	int n, k;
	cin >> n >> k;
	vector<int> v(n);
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
	}

	bool result = isDivisibility(v,n,k);
	cout<< (result ? "Divisible" : "Not divisible")<<endl;
	return 0;
}