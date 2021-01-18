#pragma once

#include<iostream>
#include<fstream>
#include<regex>
#include<list>
using namespace std;
#include"Token.hpp"
#include"TokenNum.hpp"
class Lexer{
    ifstream& reader;
    list<Token> q;
    regex pattern;
public:
    Lexer(ifstream& _reader):reader(_reader){
        pattern = regex("\\s*|[0-9]+|[a-z]+|=|\".*\"");
    }

    Token read(){
        while(q.empty() && readline()){

        }
        if(!q.empty()){
            Token token =  q.front();
            q.pop_front();
            return token;
        }
        return TokenEOF();
    }
    Token peek(int i){
        while(q.size() <= i && readline()){

        }
        if(q.size() > i){
            list<Token>::iterator ite = q.begin();
            //ite = ite+i;
            for(int k = 0; k < i; k ++){
                ite++;
            }
            return (*ite);
        }
        return TokenEOF();
    }

    bool readline(){
        string sline;
        
        if(getline(reader,sline)){
            cout<<sline<<endl;
            auto params_it = std::sregex_iterator(sline.cbegin(), sline.cend(), pattern);
            auto params_end = std::sregex_iterator();
            
            while(params_it!=params_end){  
                smatch match;
                auto params = params_it->str();         
                if(regex_match(params,match,pattern)){
                    for(int i = 0; i < match.size();i++){
                        string str = match[i].str();
                        cout<<match[i].str()<<endl;
                        bool ret = regex_match(match[i].str(),regex("[0-9]+"));
                        if(regex_match(match[i].str(),regex("[0-9]+"))){
                            Token token = (Token)TokenNum(stoi(match[i].str()));
                            q.push_back(token);
                        }
                    }
                }
                params_it ++;
            }
            return true;
        }
        return false;
    }
};