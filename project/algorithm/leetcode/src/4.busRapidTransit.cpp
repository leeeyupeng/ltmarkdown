#include"leetcode.h"

class Solution {
	unordered_map<int, long long> us;
	vector<int> jump;
	vector<int> cost;
	int target;
	int inc; int dec;
	int jumpnums;	
	long long ans;
	int maxtarget = 0;
	int minjump;
	int mintarget = 0;
	int minstepcost = 0;

	vector<int> jumpsort;
	void dfs(long long loc,long long nowcost) {
		if (loc == target) { ans = min(ans, nowcost); return ; }
		if (loc > target) {
			if ((loc - target) * dec + nowcost >= ans) { return ; }
			else {
				ans = (loc - target) * dec + nowcost;
				return ;
			}
		}
		else if (loc > this->mintarget) {
			ans = min(ans, nowcost + (target - loc) * inc);
			return;
		}
		if ((target - loc) * this->minstepcost >= ans) { return; }

		ans = min(ans,(target-loc) * inc);

		if (us.find(loc) != us.end()) {
			if (us[loc] <= nowcost) { return ; }
		}
		us[loc] = nowcost;

		for (int i = 0; i < jumpnums; i++) {
			dfs(jump[jumpsort[i]] * loc, nowcost + cost[jumpsort[i]]);
		}
		//if ((target - loc) * this->minstepcost >= ans) { return; }
		//if (loc < target) {
		//	dfs(loc + 1, nowcost + inc);
		//}
		//if (loc > 1) {
		//	dfs(loc - 1, nowcost + dec);
		//}
		return ;
	}
public:
	int busRapidTransit(int target, int inc, int dec, vector<int>& jump, vector<int>& cost) {
		this->target = target;
		this->inc = inc;
		this->dec = dec;
		this->jump = jump;
		this->cost = cost;
		this->jumpnums = jump.size();
		this->minstepcost = inc;
 		ans= (long long)target * (long long)inc;
		this->minjump = this->jump[0];
		for (int i = 0; i < this->jumpnums; i++) {
			this->minjump = min(this->minjump, this->jump[i]);
			this->minstepcost = min(this->minstepcost, this->cost[i] / this->jump[i]);
		}
		this->mintarget = this->target / this->minjump;

		jumpsort = vector<int>(this->jumpnums);
		for (int i = 0; i < this->jumpnums; i++) {
			jumpsort[i] = i;
		}
		sort(jumpsort.begin(), jumpsort.end(), [this](int a, int b) {
			if (this->jump[a] * this->cost[b] == this->jump[b] * this->cost[a]) {
				return this->jump[a] < this->jump[b];
			}
			else {
				return this->jump[a] * this->cost[b] > this->jump[b] * this->cost[a];
			}});
		dfs(1,inc);
		ans %= 1000000007;
		return ans;
	}
};

//int main() {
//
//	Solution s;
//	int target = 100007, inc = 4, dec = 5;
//	vector<int> jump = { 3, 6, 8, 11, 5, 10, 4 };
//	vector<int>  cost = { 4, 7, 6, 3, 7, 6, 4 };
//	int ans = s.busRapidTransit(target,inc,dec,jump,cost);
//	cout << "ans:" << ans << endl;
//	//system("PAUSE");
//	getchar();
//	return 0;
//}