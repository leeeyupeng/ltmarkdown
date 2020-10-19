#include"leetcode.h"

class Solution {
private:
    int n; 
    bool check(string& s,string &e){
        int i = 0;
        int j = n-1;
        while(i < j && s[i] == e[j]){i++;j--;}
        while(i < j && e[i] == e[j]){i++;j--;}
        return i>=j;
    }
public:
    bool checkPalindromeFormation(string a, string b) {
        this->n = a.length();
        return check(a,b) || check(b,a);
    }
};