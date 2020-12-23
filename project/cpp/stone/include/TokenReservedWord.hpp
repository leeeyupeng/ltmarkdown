#include<iostream>
#include<string>
using namespace std;

#include"Token.hpp"

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



class TokenReservedWord:Token{
private:
    TokenReservedWordType tokenreservedwordtype=TokenReservedWordType::NONE;
public:
    TokenReservedWord(/* args */);
    ~TokenReservedWord();

    static TokenReservedWordType GetReservedWordType(string str);
};