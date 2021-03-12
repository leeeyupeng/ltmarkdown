#include"leetcode.h"

class Solution {
private:
    union Keyword
    {
        struct{
            bool isoper;
            char oper;
        };
        struct 
        {
            bool isnotdigit;
            int digit;
        };  

        Keyword(bool _isoper,char _oper): isoper(_isoper),oper(_oper){}
        Keyword(bool _isnotdigit,int _digit):isnotdigit(_isnotdigit),digit(_digit){}     
    };
    
    void scanning(string s,vector<Keyword>& keywords){
        int digit = 0;
        bool negative = false;
        bool predigit = false;
        for(auto c:s){
            if(c==' '){continue;}
            else if(c>='0' && c<='9'){
                digit = digit * 10 + (c - '0');
                predigit = true;
            }
            else{
                if(predigit){
                    keywords.push_back(Keyword{false,digit * (negative?-1:1)});
                    predigit = false;
                    negative = false;
                    digit = 0;
                    keywords.push_back(Keyword{true,c});
                }
                else{
                    negative = (c == '-'?true:false);
                }
            }
        }

        if(predigit){
            keywords.push_back(Keyword{false,digit * (negative?-1:1)});
            predigit = false;
            negative = false;
            digit = 0;
        }
    }
    int cacl(int a,int b,char oper){
        int ab=0;
        switch (oper)
        {
        case '+':
            ab = a + b;
            break;
        case '-':
            ab = a - b;
            break;
        case '*':
            ab = a * b;
            break;
        case '/':
            ab = a / b;
            break;
        
        default:
            ab = 0;
            break;
        }
        return ab;
    }
public:
    int calculate(string s) {
        vector<char> priority(255,0);
        priority['+'] = 1;
        priority['-'] = 1;
        priority['*'] = 2;
        priority['/'] = 2;
        priority['e'] = 0;
        vector<Keyword> keywords;
        scanning(s,keywords);
        keywords.push_back(Keyword{1,'e'});
        stack<char> soper;
        stack<int> sdigit;
        int a,b,ab;
        for(auto keyword:keywords){
            if(keyword.isnotdigit == false){
                sdigit.push(keyword.digit);
            }
            else{
                while(!soper.empty() && priority[soper.top()] >= priority[keyword.oper]){
                    b = sdigit.top();sdigit.pop();
                    a = sdigit.top();sdigit.pop();
                    ab = cacl(a,b,soper.top());
                    soper.pop();
                    sdigit.push(ab);
                }
                soper.push(keyword.oper);
            }
        }
        return sdigit.top();
    }
};

// int main()
// {
//     string s{"-3+2*-2"};
//     Solution solution;
//     auto ret = solution.calculate(s);
//     return 0;
// }