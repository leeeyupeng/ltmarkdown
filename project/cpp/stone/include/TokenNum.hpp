#pragma once
#include<string>
using namespace std;

#include"Token.hpp"

class TokenNum:public Token{
private:
    int value;
public:
    TokenNum(int _value):value(_value){
        tokentype = (Token::TokenType::NUM);
    };
    ~TokenNum(){};
    virtual string tostring(){
        return "TokenNum";
    }
};