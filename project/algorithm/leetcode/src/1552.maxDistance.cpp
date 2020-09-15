#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <queue>
#include<string>
#include<map>
#include<unordered_map>
#include<unordered_set>
#include<stack>
using namespace std;

class Solution {
private:
	int n;
	bool iscan(vector<int>& position, int m, int distance) {
		int last = 0;
		int count = m - 1;
		for (int i = 1; i < n&&count > 0; i++) {
			if (position[i] - position[last] >= distance) {
				last = i;
				count--;
			}
		}
		return count == 0;
	}
	int binary(vector<int>& position, int m, int left, int right) {
		if (!(left < right)) { return left; }
		int middle = (left + right + 1) >> 1;
		if (iscan(position, m, middle)) {
			return binary(position,m,middle,right);
		}
		else {
			return binary(position, m, left, middle - 1);
		}
	}
public:
	int maxDistance(vector<int>& position, int m) {
		sort(position.begin(),position.end());
		n = position.size();
		int left = 1, right = position[n - 1] - position[0];
		if (n < m) { return 0; }		
		else if (m == 2) { return right; }
		return binary(position,m,left,right);
	}
};

//int main()
//{
//	Solution s;
//	vector<int> position = {
//5,3,1,8
//	};
//	int m = 4;
//	int ans = s.maxDistance(position,m);
//	cout << ans<<endl;
//	system("PAUSE");
//
//	return 0;
//
//}