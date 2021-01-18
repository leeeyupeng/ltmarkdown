#include"leetcode.h"

class Solution {
private:
    int n;
    int m;
    vector<int> us;
    int find(int index){
        if(us[index] == index){
            return index;
        }
        us[index] = find(us[index]);
        return us[index];
    }
    void uni(int i1,int i2){
        i1 = find(i1);
        i2 = find(i2);
        us[i2] = i1;
    }
public:
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        this->n = s.length();
        this->m = pairs.size();
        us = vector<int>(this->n,0);
        for(int i = 0; i < this->n; i ++){us[i] = i;}
        int a,b;
        for(int i = 0; i < this->m; i ++){
            uni(pairs[i][0],pairs[i][1]);
        }
        
        unordered_map<int,vector<int>> map;
        int usindex = 0;
        for(int i = 0; i < this->n; i ++){
            usindex = find(i);
            if(map.find(usindex) == map.end()){
                map.insert({usindex,{}});
            }
            map[usindex].push_back(i);
        }
        for(unordered_map<int,vector<int>>::iterator ite = map.begin();ite!=map.end();ite++){
            sort(ite->second.begin(),ite->second.end(),[&s](int a,int b){
                if(s[a] == s[b]){
                    return a>b;
                }
                return s[a] > s[b];
            });
        }
        string ans(this->n,'0');
        for(int i = 0; i < this->n;i++){
            usindex = find(i);
            ans[i] = s[map[usindex].back()];
            map[usindex].pop_back();
        }
        return ans;
    }
};