#pragma once

#include<string>
using namespace std;
class Token
{
public:
    enum TokenType{
        NONE,
        ID,
        NUM,
        REAL,
        STRING,
        RESERVERDWORD,
        TOKENEOF,
    };
public:
    TokenType tokentype=TokenType::NONE;
public:
    Token(/* args */);
    ~Token();

    virtual string tostring(){
        return "Token";
    }
};


class TokenEOF:public Token{
public:
    TokenEOF(){
        tokentype = TokenType::TOKENEOF;
    }
    virtual string tostring(){
        return "TokenEOF";
    }
};