#include"leetcode.h"

class Solution {
private:
    int n;
    int m;
    inline int getcount(vector<int>& v,int value){
        int i = 0,j = m;
        int mid = (i+j)>>1;
        while(i<j){
            mid = (i+j)>>1;
            if(v[mid]<=value){i = mid+1;}
            else{j = mid;}
        }
        return i;
    }
public:
    int breakfastNumber(vector<int>& staple, vector<int>& drinks, int x) {
        sort(staple.begin(),staple.end());
        sort(drinks.begin(),drinks.end());
        n = staple.size();
        m = drinks.size();
        long long ans = 0;
        long long mod = (1000000000+7);
        int lasts=0,lasta=0;
        for(int i = 0; i<n; i++){
            if(x - staple[i]<=0){break;}
            if(lasts==staple[i]){ans += lasta;continue;}
            lasts = staple[i];
            lasta = getcount(drinks,x - staple[i]);
            ans += lasta;
        }
        ans %= mod;
        return ans;
    }
};
// int main() {

// 	Solution s;
//    vector<int> staple = {
// 10,20,5
//    }; 
//    vector<int> drinks = {
// 5,5,2
//    };
//    int x = 15;
// 	int ans = s.breakfastNumber(staple,drinks,x);
// 	cout << "ans:" << ans << endl;
// 	//system("PAUSE");
// 	getchar();
// 	return 0;
// }