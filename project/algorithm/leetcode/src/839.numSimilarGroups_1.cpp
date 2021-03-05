#include"leetcode.h"

class Solution {
private:
    int n;
    int m;
    int find(vector<int> &us,int index){
        if(us[index]!=index){
            us[index] = find(us,us[index]);
        }
        return us[index];
    }
    inline bool isconnect(string &a,string &b){
        int counter = 0;
        for(int i = 0; i < m; i ++){
            if(a[i]!=b[i]){counter++;}
        }
        return counter<=2;
    }
public:
    int numSimilarGroups(vector<string>& strs) {
        n = strs.size();
        if(n<=1){return n;}
        m = strs[0].length();
        vector<int> us(n,0);
        for(int i = 0; i < n; i ++){us[i] = i;}
        int a,b;
        for(int i = 0; i < n; i ++){
            for(int j = i +1;j < n; j ++){
                if(isconnect(strs[i],strs[j])){
                    a = find(us,i);
                    b = find(us,j);
                    if(a!=b){
                        us[b] = a;
                    }
                }
            }
        }
        int ret = 0;
        for(int i = 0; i < n; i ++){
            if(us[i] == i){ret++;}
        }
        return ret;
    }
};