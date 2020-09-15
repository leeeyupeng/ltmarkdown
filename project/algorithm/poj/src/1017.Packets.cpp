#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>

using namespace std;

#define PRODUCTSMAX 6
class Solution {
private:
	int products[PRODUCTSMAX];
	int space[PRODUCTSMAX];
	int BinPacking() {
		int ans = 0;
		for (int i = 0; i < PRODUCTSMAX; i++) {
			space[i] = 0;
		}
		ans += products[5];
		ans += products[4];
		space[0] += products[4]*11;
		ans += products[3];
		space[1] += products[3] * 5;
		ans += (products[2] + 3) / 4;
		int s = 4 - products[2] % 4;
		if (s == 1) { space[1] += 1; space[0] += 5; }
		else if (s == 2) { space[1] += 3; space[0] += 6;}
		else if (s == 3) { space[1] += 5; space[0] += 7; }
		int nums = products[1];
		if (space[1] >= nums) { space[0] += (space[1] - nums) * 4; space[1] = 0; }
		else {  
			ans += (nums - space[1] + 8) / 9; 
			space[0] += (9 - (nums - space[1]) % 9) * 4;
			space[1] = 0;
		}
		nums = products[0];
		if (space[0] < nums) {
			ans += (nums - space[0] + 35) / 36;
		}
		return ans;
	}
public:
	void solve()
	{
		while (true) {
			int nums = 0;
			for (int i = 0; i < PRODUCTSMAX; i++) {
				cin >> products[i];
				nums += products[i];
			}
			if (nums == 0) {
				break;
			}
			else {
				cout << BinPacking() << endl;
			}
		}
	}
};

//int main() {
//	Solution s;
//	s.solve();
//	return 0;
//}
