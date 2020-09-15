#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

struct Charm
{
	int weight;
	int desirability;
};
vector<Charm>* v = NULL;
vector<int> va;
vector<int> vb;
vector<int> vv;

int N;
int M;
bool cmp(Charm c1, Charm c2)
{
	if (c1.desirability * c2.weight == c2.desirability * c1.weight)
	{
		return c1.weight < c2.weight;
	}
	else
	{
		return 1.0f * c1.desirability / c1.weight < 1.0f * c2.desirability / c2.weight;
	}
}

void solveSubsetKnapsack(int i, int j, vector<int>& vv)
{
	if (i == j)
	{
		vv[(*v)[i].weight] = (*v)[i].desirability;
	}
	else
	{
		int middle = (i + j) / 2;
		solveSubsetKnapsack(i, middle, va);
		solveSubsetKnapsack(middle + 1, j, vb);

		for (int k = 0; k <= M; k++)
		{

		}
	}
}
int CharmBracelet(vector<Charm>* v, int n, int m)
{
	N = n;
	M = m;

	sort(v->begin(), v->end(), cmp);

	va=vector<int>(M);
	vb=vector<int>(M);
	vv = vector<int>(M);
	solveSubsetKnapsack(0, n - 1, vv);

	int ans = (n, m);
	return ans;
}
int mainpoj()
{
	int n, m;
	cin >> n >> m;
	v = new vector<Charm>(n);
	for (int i = 0; i < n; i++)
	{
		cin >> (*v)[i].weight;
		cin >> (*v)[i].desirability;
	}
	int result = CharmBracelet(v, n, m);
	delete v;
	v = NULL;
	cout << result << endl;
	return 0;
}