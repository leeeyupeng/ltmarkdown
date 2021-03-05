#pragma once
#include<string>
using namespace std;
#include"Token.hpp"

class TokenID:Token{
private:

public:
    TokenID(/* args */);
    ~TokenID();

    virtual string tostring(){
        return "TokenID";
    }
};