#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>

using namespace std;


namespace poj2985
{
#define MAX 2002
	class Solution {
	private:
		int n, m;
		int sums;
		int us[MAX];
		int nums[MAX];
		int bit[MAX];
		int usfind(int i) {
			while (us[i] != i) { i = us[i]; }
			return i;
		}
		void usconnected(int i, int j) {
			i = usfind(i);
			j = usfind(j);
			if (i == j) { return; }
			sums--;
			bitupdate(nums[i], -1);
			bitupdate(nums[j], -1);
			if (nums[i] >= nums[j]) {
				us[j] = i;
				nums[i] += nums[j];
				nums[j] = 0;
				bitupdate(nums[i], 1);
			}
			else
			{
				us[i] = j;
				nums[j] += nums[i];
				nums[i] = 0;
				bitupdate(nums[j], 1);
			}
		}
		void bitupdate(int index, int val) {
			while (index <= n) {
				bit[index] += val;
				index += (index & (-index));
			}
		}
		int bitgetsum(int index) {
			int result = 0;
			while (index > 0) {
				result += bit[index];
				index -= (index & (-index));
			}
			return result;
		}
		int bitfindkth(int k) {
			int mink = sums - k + 1;
			int ans = 0;
			for (int i = 20; i >=0; i--) {
				if (ans + (1 << i) <= n && bit[ans + (1 << i)] < mink) {
					ans += 1 << i; 
					mink -= bit[ans];
				}
			}
			if (mink > 0) { ans++; }
			return ans;
		}
	public:
		void solve() {
			//cin >> n >> m;
			scanf("%d%d", &n, &m);
			for (int i = 0; i < n; i++) {
				us[i] = i;
				nums[i] = 1;
				bit[i] = 0;
			}
			bit[n] = 0;
			bitupdate(1, n);
			sums = n;
			int c, p1, p2;
			for (int i = 0; i < m; i++) {
				//cin >> c;
				scanf("%d", &c);
				if (c == 0) {
					//cin >> p1 >> p2;
					scanf("%d%d", &p1, &p2);
					usconnected(p1 - 1, p2 - 1);
				}
				else {
					//cin >> p1;
					scanf("%d", &p1);
					int size = bitfindkth(p1);
					//cout << left << endl;
					printf("%d\n", size);
				}
			}
		}
	};

}
//int main() {
//	poj2985::Solution s;
//	s.solve();
//	return 0;
//}