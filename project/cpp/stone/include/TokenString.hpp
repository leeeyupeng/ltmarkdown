#pragma once
#include<string>
using namespace std;
#include"Token.hpp"

class TokenString:Token{
private:

public:
    TokenString(/* args */);
    ~TokenString();
    virtual string tostring(){
        return "TokenString";
    }
};