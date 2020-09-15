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
	unordered_set<string> us;
	string ans;
	// Hierholzer Ëã·¨
	void dfs(string node) {
		for (int j = 0; j < k; j++) {
			string node2 = node;
			node2.push_back('0'+j);
			if (us.find(node2) == us.end()) {
				us.insert(node2);
				dfs(node2.substr(1));
				ans.push_back('0' + j);
			}			
		}		
	}
public:
	string crackSafe(int n, int k) {
		this->n = n;
		this->k = k;
		string start;
		for (int i = 0; i < n - 1; i++) {
			start.push_back('0'+0);
		}
		dfs(start);
		ans+=start;
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