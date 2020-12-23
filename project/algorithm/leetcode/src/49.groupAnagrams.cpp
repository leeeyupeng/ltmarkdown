#include"leetcode.h"

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n = strs.size();
        vector<vector<string>> ans;
        vector<string> strssort;
        string strsort;
        bool flag = false;
        for(int i = 0; i < n;i ++)
        {
            strsort = strs[i];
            flag = false;
            sort(strsort.begin(),strsort.end());
            for(int j = 0;j < strssort.size();j ++){
                if(strssort[j] == strsort){
                    ans[j].push_back(strs[i]);
                    flag = true;
                    break;
                }
            }
            if(flag==false){
                strssort.push_back(strsort);
                ans.push_back(vector<string>(1,strs[i]));
            }
        }

        return ans;
    }
};