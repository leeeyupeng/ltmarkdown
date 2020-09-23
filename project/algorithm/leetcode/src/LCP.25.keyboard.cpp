#include "leetcode.h"

#define CHARNUMS 26
class Solution {
private:
    int k;
    int n;
    unordered_map<int,long long> map;
    vector<int> vnums;
    long long dfs(int index,int nums){
        if(map.find((index<<8)+nums)!=map.end()){return map[(index<<8)+nums];}
        if(nums == 0){return getNums(n,index,vnums);}
        long long ans = 0;
        for(int i = min(k,nums);i>=0 && nums - i <= k*(CHARNUMS-index - 1); i --){
            vnums[index] = i;
            ans += dfs(index+1,nums-i);
            ans%=1000000007ll;
        }
        vnums[index] = 0;
        map[(index<<8)+nums] = ans;
        return map[(index<<8)+nums];
    }
    long long getNums(int n,int index,vector<int> &vnums){
        long long ans = 1;
        long long sums=1;
        int indexsums = 0;

        long long g=1;
        for(int i = 1; i <= n; i ++){
            ans *= i;            

            if(sums > 1){
                g = gcd(ans,sums);
                ans /= g;
                sums/=g;
            }
            else if(indexsums<index){
                if(vnums[indexsums] != 0){
                    sums*=getA(vnums[indexsums]);                
                }
                indexsums ++;

                g = gcd(ans,sums);
                ans /= g;
                sums/=g;
            }
            else{
                ans %= 1000000007ll;
            }
        }
        return ans;
    }
    long long gcd(long long a,long long b){
        if(b==0){return a;}
        return gcd(b,a%b);
    }
    long long getA(int n){
        if(n==0){return 1;}
        else if(n==1){return 1;}
        return n*getA(n-1) % 1000000007ll;
    }

    long long getA(int n,int k){
        long long ans = 1;
        for(int i = n;i > k;i --){
            ans *= i;
            ans %= 1000000007ll;
        }
        return ans % 1000000007ll;
    }
public:
    int keyboard(int k, int n) {
        this->k = k;
        this->n = n;
        vnums=vector<int>(CHARNUMS);
        for(int i = 0; i < CHARNUMS; i ++){
            vnums[i] = 0;
        }
        long long ans = dfs(0,n);
        ans = ans%1000000007ll;
        return ans;
    }
};

// int main(){
//     Solution solution;
//     int ans =  solution.keyboard(2,2);
//     return 0;
// }