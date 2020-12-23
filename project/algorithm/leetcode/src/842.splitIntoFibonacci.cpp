#include"leetcode.h"
class Solution {
private:
    long long getlong(string& S,int start,int end){
        long long ret = 0;
        for(int i = start; i <= end; i ++){
            ret*=10;
            ret+=S[i]-'0';
        }
        return ret;
    }
    string getstr(int i){
        if(i==0){return "0";}
        string ret;
        while(i!=0){
            ret.push_back((i%10)+'0');
            i = i / 10;
        }
        reverse(ret.begin(),ret.end());
        return ret;
    }
    bool check(string &S,vector<int>& path,int a,int b,int index){
        if(index == S.length()){return true;}
        long long ab = (long long)a + (long long)b;
        if(ab>INT_MAX){return false;}
        string strab = getstr(a+b);
        int n = strab.length();
        if(S.length() - index < n){return false;}
        for(int i = 0; i < n; i ++){
            if(strab[i] != S[index + i]){return false;}
        }
        path.push_back(a+b);
        return check(S,path,b,a+b,index+n);
    }
    bool isfib(string &S,vector<int>& path,int i,int j){

        long long a = getlong(S,0,i);
        long long b = getlong(S,i+1,j);
        if(S[0] == '0' && i!= 0){return false;}
        if(S[i+1]=='0' && j-(i+1)!=0){return false;}
        if(a>INT_MAX){return false;}
        if(b>INT_MAX){return false;}
        path.push_back(a);
        path.push_back(b);
        return check(S,path,a,b,j+1);
    }
public:
    vector<int> splitIntoFibonacci(string S) {
        int n = S.length();
        vector<int> path;
        for(int i = 0;i <= 10 && i <= (n>>1); i ++){
            for(int j = i+1;j <= i+1+10 && j+1 + i + 1 <= n;j ++){
                path.clear();
                if(isfib(S,path,i,j)){
                    return path;
                }
            }
        }
        return {};
    }
};

// int main(){
//     string S="0000";
//     Solution solution;
//     vector<int> ans = solution.splitIntoFibonacci(S);

//     return 0;
// }