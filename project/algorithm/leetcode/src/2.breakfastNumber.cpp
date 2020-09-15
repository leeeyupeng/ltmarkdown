#include"leetcode.h"

class Solution {
private:
    int n;
    int m;
public:
    int breakfastNumber(vector<int>& staple, vector<int>& drinks, int x) {
        sort(staple.begin(),staple.end());
        sort(drinks.begin(),drinks.end());
        n = staple.size();
        m = drinks.size();
        long long ans = 0;
        long long mod = (1000000000+7);
        int j=m-1;
        for(int i = 0; i<n; i++){
            if(j<0){break;}
			while (j >= 0 && drinks[j] > x - staple[i]) {
				j--;
			}
            ans += j + 1;
        }
        ans %= mod;
        return ans;
    }
};
//int main() {
//
//	Solution s;
//    vector<int> staple = {
//10,20,3,2,2,6,8,10,2,3,5,3
//    }; 
//    vector<int> drinks = {
//10,20,3,2,2,6,8,10,2,3,5,3
//    };
//    int x = 25;
//	int ans = s.breakfastNumber(staple,drinks,x);
//	cout << "ans:" << ans << endl;
//	//system("PAUSE");
//	getchar();
//	return 0;
//}