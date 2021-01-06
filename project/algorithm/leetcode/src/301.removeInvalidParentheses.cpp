#include"leetcode.h"

class Solution {
private:
    int n;
    int stasize;
    vector<string> ans;
    void dfs(string& s,vector<int>& sta,vector<char>& vflag,int staindex,int index){
        if(index == n){
            if(staindex == stasize){
                string ret;
                for(int i = 0; i < n; i ++){
                    if(vflag[i] == 1){
                        ret.push_back(s[i]);
                    }
                }
                ans.push_back(ret);
            }
            return ;
        }

        if(staindex == stasize){
            dfs(s,sta,vflag,staindex,index+1);
        }
        else if(s[sta[staindex]] == ')' && s[index] == ')'){
            if(index <= sta[staindex]){
                if((index == 0 || s[index-1]!=')' || vflag[index-1] == 0)){
                    vflag[index] = 0;
                    dfs(s,sta,vflag,staindex+1,index+1);
                    vflag[index] = 1;
                }
                dfs(s,sta,vflag,staindex,index+1);
            }
        }
        else if(s[sta[staindex]] == '(' && s[index] == '('){
            if(index >= sta[staindex]){
                if((index == 0 || s[index-1]!='(' || vflag[index-1] == 0)){
                    vflag[index] = 0;
                    dfs(s,sta,vflag,staindex+1,index+1);
                    vflag[index] = 1;
                }
                dfs(s,sta,vflag,staindex,index+1);
            }
            else{
                dfs(s,sta,vflag,staindex,index+1);
            }
        }
        else{
            dfs(s,sta,vflag,staindex,index+1);
        }
    }
public:
    vector<string> removeInvalidParentheses(string s) {
        n = s.length();
        vector<int> sta(n,0);
        stasize = 0;
        for(int i = 0; i < n; i ++){
            if(s[i] == '('){
                sta[stasize] = (i);
                stasize ++;
            }
            else if(stasize != 0 && s[sta[stasize - 1]] == '(' && s[i] == ')'){
                stasize--;
            }
            else if( s[i] == ')'){
                sta[stasize] = (i);
                stasize ++;
            }
        }

        ans.clear();
        vector<char> vflag(n,1);
        dfs(s,sta,vflag,0,0);
        return ans;
    }
};

// int main()
// {
//     string s="a";
//     Solution solution;
//     vector<string> ret = solution.removeInvalidParentheses(s);

//     return 0;
// }