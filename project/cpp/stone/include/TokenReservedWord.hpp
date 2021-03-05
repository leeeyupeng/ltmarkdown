#pragma once

#include<iostream>
#include<string>
using namespace std;

#include"Token.hpp"


class TokenReservedWord:Token{
    enum TokenReservedWordType{
        NONE,
        CHAR,
        INT,
        FLOAT,

        BOOL,
        IF,
        WHILE,
        RETURN,
        LPAREN,
        RPAREN,
    };
private:
    TokenReservedWordType tokenreservedwordtype=TokenReservedWordType::NONE;
public:
    TokenReservedWord(/* args */);
    ~TokenReservedWord();

    static TokenReservedWordType GetReservedWordType(string str);
};