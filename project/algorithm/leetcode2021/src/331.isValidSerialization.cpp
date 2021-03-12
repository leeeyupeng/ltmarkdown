#include"leetcode.h"

class Solution {
public:
    bool isValidSerialization(string preorder) {
        int n = preorder.length();
        if(n==0){return false;}
        if(n==1){
            if(preorder[0]=='#'){return true;}
            else{return false;}
        }
        if(preorder[0] == '#'){return false;}
        if(preorder[0] == ','){return false;}
        stack<char> sta;
        for(int i = 0; i < n;){
            if(i!=0 && sta.empty()){return false;}
            
            if(preorder[i]=='#'){                
                sta.top()++;
                if(sta.top()>2){return false;}
                while(!sta.empty() && sta.top()==2){
                    sta.pop();
                    if(!sta.empty()){
                        sta.top()++;
                    }
                }
                i++;i++;
            }
            else{
                while(i<n&&preorder[i] != ','){i++;}
                i++;
                sta.push(0);
            }            
        }
        return sta.empty();
    }
};


// int main(){
//     string s{"91,13,14,#,#,10"};
//     Solution solution;
//     auto ret = solution.isValidSerialization(s);

//     return 0;
// }