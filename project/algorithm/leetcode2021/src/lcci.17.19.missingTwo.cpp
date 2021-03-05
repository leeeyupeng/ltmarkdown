#include"leetcode.h"

class Solution {
public:
    vector<int> missingTwo(vector<int>& nums) {
        int n= nums.size() + 2;
        int abxor=0;
        long long absums = 0;
        for(int i = 1; i <= n; i ++){abxor^=i;absums+=i;}
        for(int i = 0; i < n-2; i ++){abxor^=nums[i];absums-=nums[i];}
        int a,b;
        int axor = 0;
        for(int i = 0; i < n -2; i ++){
            a = nums[i];
            b = absums - a;
            if(a < b && b<=n && ((a^b) == abxor)){axor^=a;}
        }
        for(int i = 1; i <= n; i ++){
            a = i;
            b = absums-a;
            if(a<b&&b<=n && ((a^b) == abxor)){axor^=a;}
        }
        return {axor,abxor ^ axor};
    }
};