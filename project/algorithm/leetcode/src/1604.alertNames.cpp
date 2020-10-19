#include"leetcode.h"

class Solution {
private:
    bool check(string& s,string& e){
        int is,ie;
        is = ((s[0]-'0')*10+(s[1]-'0')) * 60 + (s[3]-'0')*10 +(s[4]-'0');
        ie = ((e[0]-'0')*10+(e[1]-'0')) * 60 + (e[3]-'0')*10 +(e[4]-'0');
        return ie-is<=60;
    }
public:
    vector<string> alertNames(vector<string>& keyName, vector<string>& keyTime) {
        int n = keyName.size();
        vector<int> v(n);
        for(int i = 0; i < n; i ++){
            v[i] = i;
        }

        sort(v.begin(),v.end(),[&keyName,&keyTime](int a,int b){
            if(keyName[a] == keyName[b]){
                return keyTime[a] < keyTime[b];
            }
            return keyName[a]<keyName[b];
        });

        int i = 0,j = 0;
        vector<string> vans;
        int ii,jj;
        while(i<n&&j<n){
            while(j<n&&keyName[v[i]] == keyName[v[j]]){j++;}
            ii = i;jj=i+2;
            while(jj<j){
                if(check(keyTime[v[ii]],keyTime[v[jj]])){
                    vans.push_back(keyName[v[i]]);
                    break;
                }
                ii++;jj++;
            }
            i=j;
        }
        return vans;
    }
};


// int main(){
//     vector<string> keyName={
// "daniel","daniel","daniel","luis","luis","luis","luis"
//     };
//     vector<string> keyTime={
// "10:00","10:40","11:00","09:00","11:00","13:00","15:00"
//     };
//     Solution solution;
//     vector<string> ans = solution.alertNames(keyName,keyTime);
//     return 0;
// }