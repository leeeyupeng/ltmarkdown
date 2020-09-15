/*
ID: leeyupeng
LANG: C++11
PROG: milk
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;
#define PROG milk
#define FILESTREAM
#ifdef FILESTREAM
#define IN(prog) TMP(prog.in)
#define OUT(prog) TMP(prog.out)
#define TMP(prog) #prog
#endif

struct farmer
{
	int price;
	int amount;
};
bool cmp(const farmer a, const farmer b) {
	return a.price < b.price;
}
void PROG() {
	int n, m;
	cin >> n >> m;
	vector<farmer> vm(m);
	for (int i = 0; i < m; i++) {
		cin >> vm[i].price >> vm[i].amount;
	}
	sort(vm.begin(),vm.end(), cmp);
	int nnums = 0;
	int costs = 0;
	for (int i = 0; i < m; i++) {
		if (n - nnums > vm[i].amount) {
			costs += vm[i].price * vm[i].amount;
			nnums += vm[i].amount;
		}
		else{
			costs += vm[i].price * (n - nnums);
			nnums += n - nnums;
			break;
		}
	}
	cout << costs << endl;
}

//int main()
//{
//#ifdef FILESTREAM
//	freopen(IN(PROG), "r", stdin);
//	freopen(OUT(PROG), "w", stdout);
//#endif
//	PROG();
//	return 0;
//}