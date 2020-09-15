#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<numeric>
#include <time.h>
using namespace std;

#include "algorithm.hpp"
#define MAX 10000000

struct Grid {
	int x = 10;
	int y = 20;
};

void fillvectorint()
{
	vector<int> v;
	for (int i = 0; i < MAX; i++) {
		v.push_back({rand() % MAX });
	}
	for (int i = 0; i < MAX; i++) {
		cout << i << ":" << v[i] << endl;
	}
	lt::fill(v.begin(), v.end(), 0);
	for (int i = 0; i < MAX; i++) {
		cout << i<< ":" << v[i] << endl;
	}
}
void fillvectorgrid()
{
	vector<Grid> v;
	for (int i = 0; i < MAX; i++) {
		v.push_back({ i, rand() % MAX });
	}
	for (int i = 0; i < MAX; i++) {
		cout << v[i].x << ":" << v[i].y << endl;
	}
	Grid g = { 0,0 };
	lt::fill(v.begin(), v.end(), g);
	for (int i = 0; i < MAX; i++) {
		cout << v[i].x << ":" << v[i].y << endl;
	}
}
void accumulatevectorint() {
	vector<int> v;
	for (int i = 0; i < MAX; i++) {
		v.push_back({ rand() % MAX });
	}
	for (int i = 0; i < MAX; i++) {
		cout << i << ":" << v[i] << endl;
	}
	int ans = lt::accumulate(v.begin(), v.end(), 0);
	cout << "ans:" << ans << endl;

	int ans2 = accumulate(v.begin(), v.end(), 0);
	cout << "ans2:" << ans2 << endl;
}
void accumulatevectorstring() {
	vector<string> v;
	for (int i = 0; i < MAX; i++) {
		v.push_back(to_string(rand() % MAX));
	}
	//for (int i = 0; i < MAX; i++) {
	//	cout << i << ":" << v[i] << endl;
	//}
	string a1 = "";
	string ans = lt::accumulate(v.begin(), v.end(), a1);
	cout << "ans:" << ans << endl;

	string a2 = "";
	string ans2 = accumulate(v.begin(), v.end(), a2);
	cout << "ans2:" << ans2 << endl;

}
void sortvectorint()
{
	vector<int> v1;
	vector<int> v2;
	for (int i = 0; i < MAX; i++) {
		int v = rand() % MAX;
		v1.push_back(v);
		v2.push_back(v);
	}
	//for (int i = 0; i < MAX; i++) {
	//	cout << i << ":" << v1[i] << endl;
	//}
	clock_t bstart = clock();
	//lt::bubblesort(v1.begin(), v1.end());
	//for (int i = 0; i < MAX; i++) {
	//	for (int j = i+1; j < MAX; j++) {
	//		if (v1[i] > v1[j]) { 
	//			lt::swap(v1[i], v1[j]); 
	//		}
	//	}
	//}
	//lt::quicksort<std::vector<int>::iterator,int>(v1.begin(), v1.end());
	lt::mergesort<std::vector<int>::iterator,int>(v1.begin(),v1.end());

	clock_t bend = clock();
	cout << "test_ltsort: " << bend - bstart << endl;
	//for (int i = 0; i < MAX; i++) {
	//	cout << i << ":" << v1[i] << endl;
	//}
	clock_t sstart = clock();
	sort(v2.begin(), v2.end());
	clock_t send = clock();
	cout << "test_sort: " << send - sstart << endl;
	for (int i = 0; i < MAX; i++) {
		if (v1[i] != v2[i]) {
			cout << i << ":" << v1[i] << "," << v2[i] << endl;
		}
	}
}
//int main() {
//	//accumulatevectorint();
//	//accumulatevectorstring();
//	sortvectorint();
//	return 0;
//}