#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <queue>
#include<string>
#include<map>
#include<unordered_map>
#include<set>
#include<unordered_set>
#include<stack>

#include<cmath>
using namespace std;

class Solution {
private:
	int n, k;
	bool us[65536 *2] = {false};
	//unordered_set<int> us;
	string ans;
	int bits2;
	int bits;
	// Hierholzer Ëã·¨
	void dfs(int node) {
		int combine1 = (node << 4) & bits2;
		int node2 = (combine1 & bits);
		for (int j = 0; j < k; j++) {
			int combine2 = combine1 + j;
			int node3 = node2 + j;
			if (us[combine2] == false) {
				us[combine2] = true;
				dfs(node3);
				ans.push_back('0'+j);
			}			
		}		
	} 
public:
	string crackSafe(int n, int k) {
		this->n = n;
		this->k = k;
		int start = 0;
		bits = ((1 << (4 * (n - 1))) - 1);
		bits2 = ((1 << (4 * n)) - 1);
		dfs(start);
		for (int i = 0; i < n - 1; i++) {
			ans.push_back('0');
		}
		return ans;
	}
};

//int main()
//{
//	Solution s;
//	string ans = s.crackSafe(2,3);
//	cout << ans;
//	system("PAUSE");
//	return 0;
//}