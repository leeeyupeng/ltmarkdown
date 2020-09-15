#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

#define MAX 100000000
class Solution {
private:
	int n;
	int getOneNums(long long num) {
		int value = 0;
		while (num > 0) {
			value += (num & 0x1);
			num = num >> 1;
		}
		return value;
	}
	long long getMulti(vector<int>& A,long long num) {
		long long result = 1;
		for (int i = 0; i < n; i++) {
			result *= (num&(1 << i)) == (1 << i) ? A[i] : 1;
		}
		return result;
	}
	unordered_map<long long, int> map;
public:
	int minScoreTriangulation(vector<int>& A) {
		n = A.size();
		for (int i = 1; i < (1<<n); i++) {
			int key = i;
			int keyOneNums = getOneNums(key);
			if (keyOneNums < 3) { continue; }
			if (keyOneNums == 3) {
				map[key] = getMulti(A,key);
				continue;
			}
			if (map.find(key) != map.end()) { continue; }
			map[key] = MAX;

			long long kkey1 = 0;
			long long kkey2 = key;
			int kkey1OneNums = 0;
			for (int ii = 0; ii < n; ii++) {
				if ((key & (1 << ii)) == 0x0) { continue; }
				for (int jj =ii + 1; jj < n; jj++) {
					if ((key & (1 << jj)) == 0x0) { continue; }
					kkey1 = (key & ((1 << (jj + 1)) - 1)) - (key & ((1 << (ii)) - 1));
					kkey1OneNums = getOneNums(kkey1);
					if (kkey1OneNums < 3 || keyOneNums - kkey1OneNums + 2 < 3) { continue; }
					kkey2 = key - kkey1 + (1 << ii) + (1 << jj);

					map[key] = min(map[key], map[kkey1] + map[kkey2]);
				}
			}
		}

		int key = (1<<n)-1;
		int ans = map[key];
 		return ans;
	}
};

//#include <algorithm>
//#include <functional>
//int main()
//{
//	Solution s;
//	vector<int> matrix{
//		1, 3, 1, 4, 1, 5,
//		91, 3, 41, 44, 1, 5,
//		21, 53, 31, 34, 1, 5,
//		91, 83, 1, 4, 1, 5,
//
//	};
//	using std::placeholders::_1;
//	auto minScoreTriangulation = std::bind(&Solution::minScoreTriangulation, &s, _1);
//	int ans = minScoreTriangulation(matrix);
//	cout << ans;
//	system("PAUSE");
//
//	return 0;
//	 
//}