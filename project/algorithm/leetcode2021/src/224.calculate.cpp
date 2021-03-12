#include"leetcode.h"

class Solution {
private:
    union keyword{
        struct{
            char isoper;
            char oper;
        };
        struct{
            char isnotdigit;
            int digit;
        };
    };
    void scanning(string& s,vector<keyword> & keywords){
        int temp=0;
        bool lastdigit = false;
        int n;
        for(auto c:s){
            if(c == ' '){}
            else if(c>='0' && c<='9'){
                temp = temp * 10 + (c - '0');
                lastdigit = true;
            }
            else{
                if(lastdigit==true){
                    keyword kw;
                    kw.isoper = 0;
                    kw.digit = temp;
                    keywords.push_back(kw);
                    temp = 0;
                    lastdigit = false;
                }
                keyword kw;
                kw.isoper = 1;
                kw.oper = c;
                keywords.push_back(kw);
            }
        }
        if(lastdigit){
            keyword kw;
            kw.isoper = 0;
            kw.digit = temp;
            keywords.push_back(kw);
        }
    }
public:
    int calculate(string s) {
        vector<char> priority(255,0);
        priority['('] = 3;
        priority['+'] = 2;
        priority['-'] = 2;
        priority[')'] = 1;
        priority['e'] = 0;
        vector<keyword> keywords;
        scanning(s,keywords);
        keyword kw;
        kw.isoper = 1;
        kw.oper = 'e';
        keywords.push_back(kw);
        stack<char> soper;
        stack<int> sdigit;
        int n = keywords.size();
        int a,b;
        int value;
        for(int i = 0; i < n; i ++){
            if(keywords[i].isoper==0){
                sdigit.push(keywords[i].digit);
            }
            else{
                while(!soper.empty() && priority[soper.top()]>=priority[keywords[i].oper]){
                    if(soper.top()=='(' && keywords[i].oper == ')'){
                        soper.pop();
                        break;
                    }
                    else if(soper.top()=='('){
                        break;
                    }
                    else{
                        b = sdigit.top();
                        sdigit.pop();
                        a = sdigit.top();
                        sdigit.pop();
                        if(soper.top() == '+'){value = a + b;}
                        else if(soper.top() == '-'){value = a - b;}
                        sdigit.push(value);
                        soper.pop();                                     
                    }
                }
                if(keywords[i].oper=='('){
                    soper.push(keywords[i].oper);
                }  
                else if(keywords[i].oper=='+' || keywords[i].oper=='-'){
                    if(i == 0){sdigit.push(0);}
                    else if(keywords[i-1].isoper == 1 && keywords[i-1].oper == '('){
                        sdigit.push(0);
                    }
                    soper.push(keywords[i].oper);
                }         
            }
        }
        return sdigit.top();
    }
};