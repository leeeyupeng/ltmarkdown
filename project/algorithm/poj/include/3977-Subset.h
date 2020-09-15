#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>
#include <ctime>
using namespace std;
long long anssum = LLONG_MAX;
int ansnum = 1000;

struct Pair
{
	long long sum;
	int num;

	Pair()
	{
	}
	Pair(long long s, int n)
	{
		sum = s;
		num = n;
	}
	bool operator<(const Pair& p)
	{
		//return id > s.id;//Ωµ–Ú≈≈¡–
		if (sum == p.sum)
		{
			return num < p.num;
		}
		return sum < p.sum;//…˝–Ú≈≈¡–
	}
};

bool cmp(Pair a, Pair b) {
	if (a.sum == b.sum) return a.num < b.num;
	return a.sum < b.sum;
}
int approximate(int i, int j, vector<Pair>& sums, long long sum);
int Subset(int n, vector<long long>& v
	,vector<Pair>& sums)
{
	int counter = 0;
	int size = counter;
	for (int i = 0; i < n; i++)
	{
		size = counter;
		sums[counter].sum = v[i];
		sums[counter].num = 1;
		counter++;
		for (int j = 0; j < size; j++)
		{
			sums[counter].sum=sums[j].sum+ v[i];
			sums[counter].num= sums[j].num + 1;
			counter++;
		}
	}

	return counter;
}
long long ABS(long long a)
{
	return a >= 0 ? a : -a;
}
void Merge(int counter1,vector< Pair>& sums1
	,int counter2, vector<Pair>& sums2)
{
	long long  tempsum;
	for (int i = 0; i < counter1; i++)
	{
		tempsum = ABS(sums1[i].sum);
		if (tempsum > anssum)
		{
		}
		else if (tempsum < anssum)
		{
			anssum = tempsum;
			ansnum = sums1[i].num;
		}
		else if (tempsum == anssum)
		{
			ansnum = ansnum < sums1[i].num
				? ansnum : sums1[i].num;
		}

		//int j = approximate(0, counter2 - 1, sums2, -sums1[i].sum);
		//vector<Pair>::iterator iter = lower_bound(sums2.begin(), sums2.begin() + counter2, Pair(-sums1[i].sum, 0), cmp);
		int j = lower_bound(sums2.begin(), sums2.begin() + counter2, Pair(-sums1[i].sum,0), cmp) - sums2.begin();
		if (j < counter2)
		{
			tempsum = ABS(sums1[i].sum + sums2[j].sum);
			if (tempsum > anssum)
			{
			}
			else if (tempsum < anssum)
			{
				anssum = tempsum;
				ansnum = sums1[i].num + sums2[j].num;
			}
			else if (tempsum == anssum)
			{
				ansnum = ansnum < sums1[i].num + sums2[j].num
					? ansnum : sums1[i].num + sums2[j].num;
			}
		}

		if (j > 0) 
		{
			j--;
			tempsum = ABS(sums1[i].sum + sums2[j].sum);
			if (tempsum > anssum)
			{
			}
			else if (tempsum < anssum)
			{
				anssum = tempsum;
				ansnum = sums1[i].num + sums2[j].num;
			}
			else if (tempsum == anssum)
			{
				ansnum = ansnum < sums1[i].num + sums2[j].num
					? ansnum : sums1[i].num + sums2[j].num;
			}
		}
	}

	int j = lower_bound(sums2.begin(), sums2.begin() + counter2, Pair(0, 0), cmp) - sums2.begin();
	if (j < counter2)
	{

		tempsum = ABS(sums2[j].sum);
		if (tempsum > anssum)
		{
		}
		else if (tempsum < anssum)
		{
			anssum = tempsum;
			ansnum = sums2[j].num;
		}
		else if (tempsum == anssum)
		{
			ansnum = ansnum < sums2[j].num
				? ansnum : sums2[j].num;
		}
	}

	if (j > 0)
	{
		j--;
		tempsum = ABS(sums2[j].sum);
		if (tempsum > anssum)
		{
		}
		else if (tempsum < anssum)
		{
			anssum = tempsum;
			ansnum = sums2[j].num;
		}
		else if (tempsum == anssum)
		{
			ansnum = ansnum < sums2[j].num
				? ansnum : sums2[j].num;
		}
	}
}

int approximate(int i,int j, vector<Pair>& sums, long long sum)
{
	if (i == j)
	{
		return i;
	}
	int m = i + (j - i) / 2;
	if (sums[m].sum <= sum && sums[m + 1].sum >= sum)
	{
		if (sums[m].sum - sum == sums[m + 1].sum - sum)
		{
			return sums[m].num < sums[m +1].num? m : m + 1;
		}
		else
		{
			return sums[m].sum - sum <= sums[m + 1].sum - sum ? m : m + 1;
		}
	}
	else if (sums[m].sum > sum)
	{
		return approximate(i, m, sums, sum);
	}
	else if (sums[m].sum < sum)
	{
		return approximate(m + 1, j, sums, sum);
	}
}

int mainpoj()
{
	int n;
	while (cin >> n)
	{
		if (n == 0)
		{
			break;
		}
		vector<long long> v(n);
		for (int i = 0; i < n; i++)
		{
			cin >> v[i];
		}

		anssum = LLONG_MAX;
		ansnum = n;
		//sort(v.begin(), v.end());
		vector<long long> v1;
		vector<long long> v2;
		for (int i = 0; i < n; i++)
		{
			if (i < ((n + 1) / 2))
			{
				v1.push_back(v[i]);
			}
			else
			{
				v2.push_back(v[i]);
			}
		}

		vector<Pair> sums1(2<<((n + 1) / 2));
		vector<Pair> sums2(2<<(n - (n + 1) / 2));

		//clock_t start, end;
		//start = clock();
		int counter1 = Subset((n + 1) / 2, v1, sums1);
		//end = clock();
		//cout << (double)(end - start) / CLOCKS_PER_SEC << endl;

		//start = clock();
		int counter2 = Subset(n - (n + 1) / 2, v2, sums2);
		//end = clock();
		//cout << (double)(end - start) / CLOCKS_PER_SEC << endl;

		//start = clock();
		sort(sums2.begin(), sums2.begin() + counter2);
		//end = clock();
		//cout << (double)(end - start) / CLOCKS_PER_SEC << endl;

		//start = clock();
		Merge(counter1, sums1, counter2, sums2);
		//end = clock();
		//cout << (double)(end - start) / CLOCKS_PER_SEC << endl;
		cout << anssum << " " << ansnum << endl;
	}
	return 0;
}